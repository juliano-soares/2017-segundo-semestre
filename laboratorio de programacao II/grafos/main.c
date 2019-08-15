#include "stdlib.h"
#include "stdio.h"
#include "grafo.h"
#include "limits.h"

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


void printaCaminho(Item* item)
{
    if ( item == NULL ) return;
    printaCaminho(item->precedente);
    printf(", %s", grafo_retorna_nome(item->vertice));
}

//essa eh a funcao a ser implementada. Ela pode ser inspirada na bfs e usar as funcoes que manipulam lista
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
                    printf("O caminho mais curto eh");
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

int main()
{
   Grafo * grafo = grafo_cria(10);


   FILE *fp;//inicialização ponteiro para arquivo

    //abertura de arquivo
    fp = fopen( "amizades.txt", "r" ); /* abre arquivo. Conteúdo anterior é perdido.*/
    if (fp == NULL){
        printf("Erro ao abrir o arquivo");
        return  0;
    }

    //leitura dos vertices
    /*
        le primeira palavra salva le segunda palavra verifica se existe se ja existe
        passa para proxima se não salva e vai para proxima ate terminar arquivo.
    */


    //leitura das arestas
    /*
        pega primeira palavra salva e passa para segunda se não deu quebra de linha pega segunda e insere a aresta
        1_palavra
        se (\n){
            pula linha
        } se nao \n{
            2_palavra
        }
        insere_aresta
        *modelo = grafo_insere_aresta(grafo, vJoao, vMaria, 1);
        passa para proxima ate quebra linha se deu quebra de linha pula para proxima linha e comesça denovo
    */
    //fecha arquivo
    fclose(fp);


   Vertice * vSantaMaria = grafo_cria_vertice(grafo, "Santa Maria");
   Vertice * vRosario = grafo_cria_vertice(grafo, "Rosario do Sul");
   Vertice * vSaoSepe = grafo_cria_vertice(grafo, "Sao Sepe");
   Vertice * vSaoVicente = grafo_cria_vertice(grafo, "Sao Vicente");
   Vertice * vSaoPedro = grafo_cria_vertice(grafo, "Sao Pedro");
   Vertice * vSaoGabriel = grafo_cria_vertice(grafo, "Sao Gabriel");


   grafo_insere_aresta(grafo, vSantaMaria, vRosario, 430); //230
   grafo_insere_aresta(grafo, vSantaMaria, vSaoPedro, 60);
   grafo_insere_aresta(grafo, vSaoPedro, vSantaMaria, 60);
   grafo_insere_aresta(grafo, vSaoPedro, vSaoVicente, 50);
   grafo_insere_aresta(grafo, vSaoVicente, vRosario, 130);
   grafo_insere_aresta(grafo, vSantaMaria, vSaoSepe, 80);
   grafo_insere_aresta(grafo, vSaoSepe, vSaoGabriel, 140);
   grafo_insere_aresta(grafo, vSaoGabriel, vRosario, 60);

   menor_caminho(grafo, vSantaMaria, vSaoVicente);

   grafo_libera(grafo);

   return 0;
}
