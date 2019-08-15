#include <stdlib.h>
#include <stdio.h>

#include "lista.h"
#include "funcoes_arvore.h"

void imprime_asc(No * no, int qImprimir){ ///qImprimir = qual forma devo imprimir as arvores
    if (no==NULL){
        return;
    }
    imprime_asc(arv_busca_filho(no,0), qImprimir);
    arv_busca_valor(no, qImprimir);
    imprime_asc(arv_busca_filho(no,1), qImprimir);
}

///le string para inserir
char* le_frases()
{
    char* resultado =(char*)malloc(50);
    if(resultado == NULL){
        printf("Sem espaço suficiente\n");
    }
    scanf(" %[^\n]s", resultado);
    return resultado;
}

void imprime_menu()
{
    printf("***************************\n");
    printf("     ESCOLHA UMA OPCAO\n");
    printf("1 - Incluir aluno\n");
    printf("2 - Excluir aluno\n");
    printf("3 - Percorrer lista\n");
    printf("4 - Listar por codigo\n");
    printf("5 - Listar por nome\n");
    printf("6 - Listar por media final\n");
    printf("7 - Sair\n");
    printf("***************************\n");
}

void incluir_aluno_lista(Arvore * A, Arvore * ANOTA, Arvore * ANOME, Nol ** inicio)
{
    int codigo_inserir;
    char* nome_inserir;
    float media_inserir;
    printf("Digite o codigo do aluno:\n");
    scanf("%d", &codigo_inserir);
    //verificar se codigo ja existe na arvore se sim = digite outro codigo se nao = continua a execuчуo
    printf("Digite o nome do aluno:\n");
    nome_inserir = le_frases();
    printf("Digite a media final do aluno:\n");
    scanf("%f", &media_inserir);
    int ver = lst_busca (*inicio, codigo_inserir);
    if(ver == 0){//ver = comparar se ja existe o codigo do aluno
        lst_insere (inicio, codigo_inserir, media_inserir, nome_inserir);
        insere_na_arvore(A, codigo_inserir, media_inserir, nome_inserir, 1);
        insere_na_arvore(ANOME, codigo_inserir, media_inserir, nome_inserir, 2);
        insere_na_arvore(ANOTA, codigo_inserir, media_inserir, nome_inserir, 3);
    }else{
        printf("codigo ou nome ja existente\n");
    }
}

void excluir_aluno_lista(Arvore * A, Arvore * Anota, Arvore * Anome, Nol ** inicio) /*excluir apartir do codigo do aluno*/
{
    int opcao;
    int codigo;

    do{
        printf("\nEscolha uma opção para excluir:\n");
        printf("\n1 - Excluir por codigo;\n2 - Voltar\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1://excluir por codigo
                printf("\nDigite o codigo para remover:\n");
                scanf("%d", &codigo);
                lst_retira (inicio, codigo);
                printf("removeu lista");
                arv_remove_no(A, codigo);
                arv_remove_no(Anota, codigo);
                arv_remove_no(Anome, codigo);
                break;
            case 2://sair
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opcao!=2);

}

void listar_alunos_por_codigo(Arvore * A)
{
    printf("\nimprimindo apartir do codigo:\n");
    imprime_asc(arv_busca_raiz(A), 1);//1 porque imprime pelo codigo
}

void listar_alunos_por_nome(Arvore * A)
{
    printf("\nimprimindo ordem alfabetica:\n");
    imprime_asc(arv_busca_raiz(A), 2);//2 porque imprime ordem alfabetica
}

void listar_alunos_por_media_final(Arvore * A)
{
    printf("\nimprimindo apartir da media final:\n");
    imprime_asc(arv_busca_raiz(A), 3);//3 porque imprime ordem nota
}
