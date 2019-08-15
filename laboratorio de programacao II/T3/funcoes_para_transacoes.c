#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "funcoes_para_transacoes.h"
#include "funcoes_para_contas.h"

void excluir_todas_transacoes(Transacoes** inicio)
{
    Transacoes* p = *inicio;
    if(p == NULL){
        printf("não tem transações para retirar\n");
        return;
    }
    while(p != NULL){
        /* retira elemento do encadeamento */
        if (*inicio == p){/* testa se é o primeiro elemento */
            *inicio = p->prox;
            free(p);
        }else{
            p->ant->prox = p->prox;
            free(p);
        }
        if (p->prox != NULL){ 	/* testa se é o último elemento */
            p->prox->ant = p->ant;
            free(p);
        }
        p = p->prox;
   }
}

void excluir_uma_transacoes(Transacoes** inicio, int cod_transacoes)
{
   Transacoes* p = *inicio;
    if(p == NULL){
        printf("não tem transações para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->codigo_transacao == cod_transacoes){
            /* retira elemento do encadeamento */
            if (*inicio == p){/* testa se é o primeiro elemento */
                *inicio = p->prox;
                free(p);
            }else{
                p->ant->prox = p->prox;
                free(p);
            }
            if (p->prox != NULL){ 	/* testa se é o último elemento */
                p->prox->ant = p->ant;
                free(p);
            }
        }
        p = p->prox;
   }
}

void listar_todas_transacao(Transacoes* inicio)
{
    Transacoes* p = inicio;
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        p = p->prox;
    }
    printf("\n");
}

void listar_transacao_de_um_cliente_por_periodo(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int mes1, mes2, ano1, ano2, cod;
    printf("\nDIGITE O CÓDIGO DA CONTA DO CLIENTE:\n");
    scanf("%d", &cod);
    printf("\nDIGITE O MES DE INICIO DA LISTA:\n");
    scanf("%d", &mes1);
    printf("\nDIGITE O ANO DE INICIO DA LISTA:\n");
    scanf("%d", &ano1);
    printf("\nDIGITE O MES DE FINAL DA LISTA:\n");
    scanf("%d", &mes2);
    printf("\nDIGITE O ANO DE FINAL DA LISTA:\n");
    scanf("%d", &ano2);
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if((p->ano>=ano1)&&(p->ano<=ano2)&&(p->mes>=mes1)&&(p->mes<=mes2)&&(p->numero_conta_tran==cod)){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void listar_transacoes_de_um_cliente_feita_numa_agencia(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int cod, ag;
    printf("\nDIGITE O CÓDIGO DA CONTA DO CLIENTE:\n");
    scanf("%d", &cod);
    printf("\nDIGITE A AGÊNCIA DO CLIENTE:\n");
    scanf("%d", &ag);
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if((p->numero_conta_tran==cod)&&(p->codigo_agencia_da_trans==ag)){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void listar_todas_transacoes_do_cliente(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int cod;
    printf("\nDIGITE O CÓDIGO DA CONTA DO CLIENTE:\n");
    scanf("%d", &cod);
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->numero_conta_tran==cod){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void listar_transacao_de_uma_agencia_por_periodo(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int mes1, mes2, ano1, ano2, ag;
    printf("\nDIGITE O CÓDIGO DA AGÊNCIA:\n");
    scanf("%d", &ag);
    printf("\nDIGITE O MES DE INICIO DA LISTA:\n");
    scanf("%d", &mes1);
    printf("\nDIGITE O ANO DE INICIO DA LISTA:\n");
    scanf("%d", &ano1);
    printf("\nDIGITE O MES DE FINAL DA LISTA:\n");
    scanf("%d", &mes2);
    printf("\nDIGITE O ANO DE FINAL DA LISTA:\n");
    scanf("%d", &ano2);
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if((p->ano>=ano1)&&(p->ano<=ano2)&&(p->mes>=mes1)&&(p->mes<=mes2)&&(p->codigo_agencia_da_trans==ag)){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void listar_todas_transacoes_da_agencia(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int ag;
    printf("\nDIGITE A AGÊNCIA AONDE FORAM FEITAS AS TRANSAÇÕES:\n");
    scanf("%d", &ag);
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->codigo_agencia_da_trans==ag){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void imprime_menu_transacao_listar()
{
    printf("==========================================\n");
	printf("          MENU TRANSAÇÕES LISTAR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - LISTAR TRANSAÇÕES DE UM CLIENTE. ||\n");
	printf("|| 2 - LISTAR TRANSAÇÕES DE UMA AGÊNCIA.||\n");
	printf("|| 3 - LISTAR TODAS AS TRANSAÇÕES.      ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_menu_transacao_listar_cliente()
{
    printf("==========================================\n");
	printf("   MENU TRANSAÇÕES DE UM CLIENTE LISTAR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - LISTAR TRANSAÇÕES DE UM PERIODO. ||\n");
	printf("|| 2 - L. TRANS. FEITAS EM UMA AGÊNCIA. ||\n");
	printf("|| 3 - LISTAR TODAS AS TRANSAÇÕES.      ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_menu_transacao()
{
    printf("==========================================\n");
	printf("             MENU TRANSAÇÕES!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - FAZER UMA TRANSAÇÃO.             ||\n");
	printf("|| 2 - EXCLUIR UMA TRANSAÇÃO.           ||\n");
	printf("|| 3 - LISTAR AS TRANSAÇÕES.            ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_menu_transacao_excluir()
{
    printf("==========================================\n");
	printf("         MENU RXCLUIR TRANSAÇÕES!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - EXCLUIR UMA TRANSAÇÃO.           ||\n");
	printf("|| 2 - EXCLUIR TODAS TRANSAÇÕES.        ||\n");
	printf("|| 3 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_menu_transacao_listar_agencia()
{
    printf("==========================================\n");
	printf("   MENU TRANSAÇÕES DE UM CLIENTE LISTAR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - LISTAR TRANSAÇÕES DE UM PERIODO. ||\n");
	printf("|| 2 - LISTAR TODAS AS TRANSAÇÕES.      ||\n");
	printf("|| 3 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_tipos_transacoes()
{
    printf("==========================================\n");
	printf("   MENU FAZER UM TIPO DE TRANSAÇÕES!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - VERIFICAR SALDO.                 ||\n");
	printf("|| 2 - EFETUAR UM SAQUE.                ||\n");
	printf("|| 3 - EFETUAR UMA TRANSFERÊNCIA.       ||\n");
	printf("|| 4 - EFETUAR UM PAGAMENTO.            ||\n");
	printf("|| 5 - EFETUAR UM DEPOSITO.             ||\n");
	printf("|| 6 - SAIR                             ||\n");
	printf("==========================================\n");
}


