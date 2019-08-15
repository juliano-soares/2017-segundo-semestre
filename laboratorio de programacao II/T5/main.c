#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "funcoes_arvore.h"
#include "principal.h"
int main()
{
    Nol* inicio;                      /* declara uma lista não iniciada*/
    lst_cria(&inicio);               /* inicia lista vazia*/
    Arvore * arv = arv_cria();
    Arvore * arvNOME = arv_cria();
    Arvore * arvNOTA = arv_cria();
    int opcao;
    do{
        imprime_menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                incluir_aluno_lista(arv, arvNOTA, arvNOME, &inicio);
                break;
            case 2:
                excluir_aluno_lista(arv, arvNOTA, arvNOME, &inicio);
                break;
            case 3:
                lst_imprime(inicio);
                break;
            case 4:
                listar_alunos_por_codigo(arv);
                break;
            case 5:
                listar_alunos_por_nome(arvNOME);
                break;
            case 6:
                listar_alunos_por_media_final(arvNOTA);
                break;
            case 7:
                printf("\nSAINDO!\n");
                break;
            default:
                printf("\nOPCAO INVALIDA!!\n");
                break;
        }
    }while(opcao!=7);
    return 0;
}
