#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"

struct item{
    Vertice * vertice;
    struct item  * precedente;
    struct item  * prox_item;
};

typedef struct item Item;

typedef struct lista{
    Item * primeiro_item;
    Item * ultimo_item;
} Lista;

void menor_caminho (Grafo * grafo, Vertice * origem, Vertice * destino);
Lista * cria_lista();
Item * adiciona_item(Lista * lista, Vertice * vertice, Item * prec);
Item * busca_item(Lista * lista, Vertice * vertice);

void printaCaminho(Item* item){
    if ( item == NULL ) return;
    printaCaminho(item->precedente);
    printf("%s -> ", grafo_retorna_nome(item->vertice));
}

void menor_caminho (Grafo * grafo, Vertice * origem, Vertice * destino){
    Lista * lista = cria_lista();
    adiciona_item(lista, origem, NULL);
    Item * item = lista->primeiro_item;
    while (item!=NULL) {
        int cont = 0;
        Vertice ** v_dest = grafo_busca_vertices_saida(grafo, item->vertice, &cont);
        int i = 0;
        for (i=0;i<cont;i++) {
            Item * item_ = busca_item(lista, v_dest[i]);
            if (item_==NULL) {
                item_ = adiciona_item(lista, v_dest[i], item);
                if ( item_->vertice == destino ) {
                    printf("\nO caminho mais curto eh:\n");
                    printaCaminho(lista->ultimo_item);
                    printf("\n");
                    return;
                }
            }
        }
        item = item->prox_item;
    }

    printf("Os vertices nao estao conectados.\n");
}

Lista * cria_lista(){
    Lista * lista = (Lista*) malloc(sizeof(Lista));
    lista->primeiro_item = NULL;
    lista->ultimo_item = NULL;
    return lista;
}

Item * adiciona_item(Lista * lista, Vertice * vertice, Item * prec){
    Item * item = (Item *)malloc(sizeof(Item));
    item->vertice = vertice;
    item->prox_item = NULL;
    item->precedente = prec;

    if (lista->primeiro_item==NULL){
        lista->primeiro_item = item;
        lista->ultimo_item = item;
    }
    else{
        lista->ultimo_item->prox_item = item;
        lista->ultimo_item = item;
    }
    return item;

}

Item * busca_item(Lista * lista, Vertice * vertice){
    Item * item = lista->primeiro_item;
    while (item!=NULL){
        if (item->vertice == vertice)
            return item;
        item = item->prox_item;
    }
    return NULL;
}

Vertice * busca_vertice_e_retorna(Vertice * vertice[], char * v_busca, int j){
    int i;
    for(i=0; i<j; i++){
        char *nome = grafo_retorna_nome(vertice[i]);
        if(strcmp(nome, v_busca)==0){
            return vertice[i];
        }
    }
    return NULL;
}

void imprime_menu_para_usuario(){
    printf("\n==========================");
    printf("\n|| 1 - Imprimir todo grafo ");
    printf("\n|| 2 - Imprimir apartir de um vertice");
    printf("\n|| 3 - Fazer uma busca de menor distancia\n||entre dois vertices ");
    printf("\n|| 4 - Sair ");
    printf("\n==========================\n");

}

void imprime_mensagem_erro_para_usuario(){
    printf("\nNao possui Arestas!!! ou ;\n");
    printf("\nNao foi encontrado ou foi escrito de forma incorreta;\n");
    printf("A escrita deve ser da mesma forma que inserido com letras \nmaiusculas e minusculas se for o caso\n");
}

int main(){
    printf("Programa criado por Juliano Leonardo Soares.\n");
    printf("Leia o arquivo README dentro da pasta do programa para saber mais.\n");
    /*#####################################################################*/
    FILE *fp;//inicialização ponteiro para arquivo
    //abertura de arquivo

    /*caso queira mudar o nome do arquivo texto deve modificar o "amizades.txt"*/
    fp = fopen( "amizades.txt", "r" );
    if (fp == NULL){
        printf("Erro ao abrir o arquivo");
        return  0;
    }
    /*#####################################################################*/

    /*duas variaveis para auxiliar a contagem de linhas
    a contaem de linhas serve para alocar o grafo de certo tamanho*/
    char l, letra = '\n';
    int vezes=0;
    while(fread (&l, sizeof(char), 1, fp)) {
        if(l == letra) {
            vezes++;
        }
    }
    if(vezes==0){
        printf("Arquivo vazio!!!");
        return 0;
    }
    fclose(fp);
    /*#####################################################################*/

    /*opos leitura de contar n° linhas cria o tamanho do grafo necessario*/
    Grafo * grafo = grafo_cria(vezes);
    /*opos leitura de contar n° linhas cria a quantidade de vertices necessario*/
    Vertice * vvetor[vezes];

    /*#####################################################################*/
    //leitura dos vertices
    /*
        le primeira linha salva le segunda linha e vai para proxima ate terminar arquivo.
    */
    fp = fopen( "amizades.txt", "r" );
    int i;
    char linha[1024];
    char *_palavra;
    for(i = 0; i<vezes; i++){
        fgets(linha, sizeof(linha), fp);
        _palavra = strtok(linha, ";" );
        vvetor[i] = grafo_cria_vertice(grafo, _palavra);
    }
    fclose(fp);
    /*#####################################################################*/
    //leitura das arestas
    /*
        vai lendo caracter por caracter ate ';' e 1° = 0 se 1° == 1 salva como vertice entrada;
        acha o ponteiro deste vertice de entrada;
        depois de achar vertice de entrada começa a ler a segunda palavra ate ';' leu salva ;
        acha o ponteiro deste vertice de chegada;
        apos achado os dois vertices insere a aresta entre os dois;
        na ultima palavra sera '\n';
        caso encontre '\n' passa para a proxima linha e recomeça a inserção dos vertices;
        caso a  primeira palavra ja seja '\n' ou terminar o arquivo para a inserção e procegue a execução;
    */
    fp = fopen( "amizades.txt", "r" );
    char palavra_saida[50];               //palavra que sai a aresta
    memset(palavra_saida, '\0', sizeof(palavra_saida));
    char palavra_chegada[50];             //palavra que chega a aresta
    memset(palavra_chegada, '\0', sizeof(palavra_chegada));
    char string[50];
    memset(string, '\0', sizeof(string)); //palavra auxiliar
    char c;
    int verificador=0;
    int k;
    for(k = 0; k<vezes; k++){           //contagem de linhas
        fgets(linha, sizeof(linha), fp);//salva linha a ser tratada
        /*tratamento na linha*/
        int j = strlen(linha);
        int cont = 0;
        for(i = 0; i < j; i++){
            c = linha[i];
            if(c == ';' || c == '\n' || c == '\0'){
                cont = 0;
                if(verificador == 0){
                    strcat(palavra_saida, string);
                }else{
                    strcat(palavra_chegada, string);
                }
                //busca ponteiro que sai a aresta
                Vertice * sai = busca_vertice_e_retorna(vvetor, palavra_saida, vezes);
                if(palavra_chegada[0] != '\0'){
                    //busca ponteiro que chega a aresta
                    Vertice * chega = busca_vertice_e_retorna(vvetor, palavra_chegada, vezes);
                    //insere a aresta entre os vertices
                    grafo_insere_aresta(grafo, sai, chega, 1);
                }
                memset(palavra_chegada, '\0', sizeof(palavra_chegada));
                memset(string, '\0', sizeof(string));
                verificador = 1;
            }else{
                string[cont] = c;
                cont++;
            }

        }
        memset(palavra_saida, '\0', sizeof(palavra_saida));
        verificador  = 0;
    }
    fclose(fp);
    //menu principal do programa
    char palavra_imp[50];
    char primeiro_nome[50];
    char segundo_nome[50];
    Vertice * vert_imp;//alocando ponteiro para o nome da busca impressão apartir de um vertice
    Vertice * vert_primeiro_nome;//alocando ponteiro para o primeiro nome da busca
    Vertice * vert_segundo_nome;//alocando ponteiro para o segundo nome da busca
    int opcao;
    do{
        imprime_menu_para_usuario();
        scanf("%d", &opcao);
        switch(opcao){
            case 1://lista todo o grafo
                for(i=0; i<vezes; i++){
                    grafo_imprime_tab (grafo, vvetor[i]);
                }
                break;
            case 2://lista apartir de um vertice
                printf("\nDigite o nome do vertice a ser buscado:\n");
                scanf(" %s", palavra_imp);
                vert_imp = busca_vertice_e_retorna(vvetor, palavra_imp, vezes);
                if(vert_imp != NULL){
                    printf("\nIMPRIMINDO APARTIR DO %s\n", palavra_imp);
                    grafo_imprime_tab (grafo, vert_imp);
                }else{
                    imprime_mensagem_erro_para_usuario();
                }
                break;
            case 3://busca
                printf("\nDigite o primeiro nome:\n");
                scanf(" %s", primeiro_nome);
                printf("\nDigite o segundo nome:\n");
                scanf(" %s", segundo_nome);
                vert_primeiro_nome = busca_vertice_e_retorna(vvetor, primeiro_nome, vezes);
                vert_segundo_nome = busca_vertice_e_retorna(vvetor, segundo_nome, vezes);
                if((vert_primeiro_nome == NULL) || (vert_segundo_nome == NULL)){
                    printf("\nAlgum nome esta incorreto ou nao foi possivel encontrar nome\n");
                    imprime_mensagem_erro_para_usuario();
                }else{
                    menor_caminho(grafo, vert_primeiro_nome,vert_segundo_nome);
                }
                break;
            case 4://sair
                break;
            default:
                printf("\nOpcao invalida!!!\n");
                break;
        }
    }while(opcao!=4);
    grafo_libera(grafo);
    return 0;
}
