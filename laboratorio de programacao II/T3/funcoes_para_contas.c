#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "funcoes_para_contas.h"

Contas* Contas_busca (Contas* inicio, int v)
{//encontra agencia com mesmo código
   Contas* p = inicio;
   while(p!=NULL){
       if (p->numero_conta == v)
          return p;
       p=p->prox;
   }
   return NULL;	/* não achou o elemento */
}

void excluir_contas_pelo_codigo(Contas** inicio, int v)
{
   Contas* p = Contas_busca(*inicio,v);
   if (p == NULL)
      return ;/* não achou o elemento: */
   /* retira elemento do encadeamento */
   if (*inicio == p)		/* testa se é o primeiro elemento */
      *inicio = p->prox;
   else
      p->ant->prox = p->prox;

   if (p->prox != NULL) 	/* testa se é o último elemento */
      p->prox->ant = p->ant;
   free(p);
}

void excluir_contas_de_um_cliente(Contas** inicio, int cpf_ver)
{
    Contas* p = *inicio;
    if(p == NULL){
        printf("não tem contas para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->cpf_cliente_conta == cpf_ver){
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

void excluir_contas_de_uma_agencia(Contas** inicio, int codigo_ag)
{
    Contas* p = *inicio;
    if(p == NULL){
        printf("não tem contas para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->codigo_agencia_conta == codigo_ag){
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

void excluir_contas_todas(Contas** inicio)
{
    Contas* p = *inicio;
    if(p == NULL){
        printf("não tem contas para retirar\n");
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

void listar_contas_de_um_cliente(Contas** inicio)
{
    Contas* p = *inicio;
    int cpf_ver;
    printf("\nDIGITE O CPF DO CLIENTE QUE DESEJA VER AS CONTAS:\n");
    scanf("%d", &cpf_ver);
    printf("\n\nA LISTA DE CONTAS: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->cpf_cliente_conta == cpf_ver){
            printf("----------------------------------------------------------------------");
            printf("\nCÓDIGO DA CONTA: %d\nCÓDIGO DA AGÊNCIA DA CONTA: %d\nCPF DO DONO DA CONTA: %d\n", p->numero_conta,p->codigo_agencia_conta, p->cpf_cliente_conta);
            printf("\nDATA DE CRIAÇÃO DA CONTA: %d / %d / %d\n", p->dia, p->mes, p->ano);
            printf("\nSALDO DA CONTA: %f  LIMITE DA CONTA: %f\n", p->saldo, p->limite);
            printf("----------------------------------------------------------------------");
            printf("\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void listar_contas_de_uma_agencia(Contas** inicio)
{
    Contas* p = *inicio;
    int codigo_agencia_ver;
    printf("\nDIGITE O CÓDIGO DA AGÊNCIA QUE DESEJA VER AS CONTAS:\n");
    scanf("%d", &codigo_agencia_ver);
    printf("\n\nA LISTA DE CONTAS: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->codigo_agencia_conta == codigo_agencia_ver){
            printf("----------------------------------------------------------------------");
            printf("\nCÓDIGO DA CONTA: %d\nCÓDIGO DA AGÊNCIA DA CONTA: %d\nCPF DO DONO DA CONTA: %d\n", p->numero_conta,p->codigo_agencia_conta, p->cpf_cliente_conta);
            printf("\nDATA DE CRIAÇÃO DA CONTA: %d / %d / %d\n", p->dia, p->mes, p->ano);
            printf("\nSALDO DA CONTA: %f  LIMITE DA CONTA: %f\n", p->saldo, p->limite);
            printf("----------------------------------------------------------------------");
            printf("\n");
        }
        p = p->prox;
    }
    printf("\n");
}

void listar_contas_todas(Contas** inicio)
{
    Contas* p = *inicio;
    printf("\n\nA LISTA DE CONTAS: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        printf("----------------------------------------------------------------------");
        printf("\nCÓDIGO DA CONTA: %d\nCÓDIGO DA AGÊNCIA DA CONTA: %d\nCPF DO DONO DA CONTA: %d\n", p->numero_conta,p->codigo_agencia_conta, p->cpf_cliente_conta);
        printf("\nDATA DE CRIAÇÃO DA CONTA: %d / %d / %d\n", p->dia, p->mes, p->ano);
        printf("\nSALDO DA CONTA: %f  LIMITE DA CONTA: %f\n", p->saldo, p->limite);
        printf("----------------------------------------------------------------------");
        printf("\n");
        p = p->prox;
    }
    printf("\n");
}

///***************insere na conta******************///
void Conta_insere (Contas** inicio,int dia_cad,int mes_cad,int ano_cad,float saldo_cad,float limite_cad,int codigo_agencia_ver,int cpf_ver,int codigo_conta)
{
    Contas* novo = (Contas*) malloc(sizeof(Contas));
    novo->codigo_agencia_conta = codigo_agencia_ver;
    novo->cpf_cliente_conta = cpf_ver;
    novo->numero_conta = codigo_conta;
    novo->dia = dia_cad;
    novo->mes = mes_cad;
    novo->ano = ano_cad;
    novo->saldo = saldo_cad;
    novo->limite = limite_cad;
    novo->total = (novo->limite + novo->saldo);
    novo->prox = *inicio;
    novo->ant = NULL;
    printf("\n%d\n", novo->codigo_agencia_conta);
    printf("%d\n", novo->cpf_cliente_conta);
    printf("%d\n", novo->numero_conta);
    printf("%f\n", novo->saldo);
    printf("%f\n", novo->limite);
    if (*inicio != NULL)
        (*inicio)->ant = novo;
    *inicio = novo;
}

int verifica_se_codigo_conta_ja_existe(Contas* inicio, int v)
{
   Contas* p = inicio;
   while(p!=NULL){
       if (p->numero_conta == v)
          return 1; /* retorna "1" se achou o elemento */
       p=p->prox;
   }
   return 0;/* retorna "0" se não achou o elemento */
}

int Clientes_busca_para_contas(Clientes* CL, int cpf_ver,int codigo_agencia_ver)
{
    Clientes* p = CL;
    while(p!=NULL){
        if((p->codigo_agencia == codigo_agencia_ver) && (p->cpf == cpf_ver)){
            return 1;
        }
        p=p->prox;
    }
    return 0;
}

///***************funções de imprimir***************///
void imprime_menu_contas()
{
    printf("==========================================\n");
	printf("           SEÇÃO CONTAS!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - CADASTRAR CONTAS.                ||\n");
	printf("|| 2 - EXCLUIR CONTAS.                  ||\n");
	printf("|| 3 - LISTAR CONTAS.                   ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_menu_contas_listar()
{
    printf("==========================================\n");
	printf("         SEÇÃO LISTAR CONTAS!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - LISTAR CONTAS DE UM CLIENTE.     ||\n");
	printf("|| 2 - LISTAR CONTAS DE UMA AGENCIA.    ||\n");
	printf("|| 3 - LISTAR TODAS AS CONTAS .         ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_menu_contas_excluir()
{
    printf("==========================================\n");
	printf("         SEÇÃO LISTAR CONTAS!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - EXCLUIR CONTAS DE UM CLIENTE.    ||\n");
	printf("|| 2 - EXCLUIR CONTAS DE UMA AGENCIA.   ||\n");
	printf("|| 3 - EXCLUIR UMA CONTA.               ||\n");
	printf("|| 4 - EXCLUIR TODAS AS CONTAS .        ||\n");
	printf("|| 5 - SAIR                             ||\n");
	printf("==========================================\n");
}
