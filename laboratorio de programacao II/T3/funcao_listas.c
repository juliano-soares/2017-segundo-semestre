#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listas.h"

///insere na lista

///***************insere na agencia****************///
void Agencia_insere (Agencia** inicio, char* nome_novo, char* end_novo, char* gerent_novo, int codigo_AGnovo)
{
    Agencia* novo = (Agencia*) malloc(sizeof(Agencia));
    novo->nome = (char*) malloc(sizeof(char));
    novo->endereco = (char*) malloc(sizeof(char));
    novo->nome_gerente = (char*) malloc(sizeof(char));
    strcpy(novo->nome, nome_novo);
    strcpy(novo->endereco, end_novo);
    strcpy(novo->nome_gerente, gerent_novo);
    novo->codigo_da_agencia = codigo_AGnovo;
    novo->prox = *inicio;
    novo->ant = NULL;
    if (*inicio != NULL)
        (*inicio)->ant = novo;
    *inicio = novo;
}
///***************insere no clientes***************///
void Clientes_insere(Clientes** inicio, char* nome_novo, char* telefone_novo, int agencia_novo, int cpf_novo)
{
    Clientes* novo = (Clientes*) malloc(sizeof(Clientes));
    novo->nome = (char*) malloc(sizeof(char));
    novo->telefone = (char*) malloc(sizeof(char));
    strcpy(novo->nome, nome_novo);
    strcpy(novo->telefone, telefone_novo);
    novo->cpf = cpf_novo;
    novo->codigo_agencia = agencia_novo;
    novo->prox = *inicio;
    novo->ant = NULL;
    if(*inicio != NULL)
        (*inicio)->ant = novo;
    *inicio = novo;
}
///***************insere um gerente****************///
void Gerente_insere(Gerente** inicio, char* nome_novo, char* telefone_novo, int agencia_novo, int cpf_novo)
{
    Gerente* novo = (Gerente*) malloc(sizeof(Clientes));
    novo->nome = (char*) malloc(sizeof(char));
    novo->telefone = (char*) malloc(sizeof(char));
    strcpy(novo->nome, nome_novo);
    strcpy(novo->telefone, telefone_novo);
    novo->cpf = cpf_novo;
    novo->codigo_agencia = agencia_novo;
    novo->prox = *inicio;
    novo->ant = NULL;
    if(*inicio != NULL)
        (*inicio)->ant = novo;
    *inicio = novo;
}
///*************insere uma transação***************///
void Transacoes_insere(Transacoes** inicio, int codigo_transacao,int numero_conta_tran,int codigo_agencia_da_trans,float valor, int dia,int mes,int ano, int tipo)
{
    Transacoes* novo = (Transacoes*) malloc(sizeof(Transacoes));
    novo->codigo_transacao =codigo_transacao;
    novo->numero_conta_tran = numero_conta_tran;
    novo->codigo_agencia_da_trans = codigo_agencia_da_trans;
    novo->valor = valor;
    novo->tipo_transacao = tipo;
    novo->dia = dia;
    novo->mes = mes;
    novo->ano = ano;
    novo->prox = *inicio;
    novo->ant = NULL;
    if (*inicio != NULL)
        (*inicio)->ant = novo;
    *inicio = novo;
}

///remove da lista

///***************remove na agencia****************///
/* função retira: remove elemento da lista */
void Agencia_retira (Agencia** inicio, int v)
{
   Agencia* p = Agencia_busca(*inicio,v);
   if (p == NULL)
      return ;                             /* não achou o elemento: */

   /* retira elemento do encadeamento */
   if (*inicio == p)		/* testa se é o primeiro elemento */
      *inicio = p->prox;
   else
      p->ant->prox = p->prox;

   if (p->prox != NULL) 	/* testa se é o último elemento */
      p->prox->ant = p->ant;
   free(p);
}
///****remove no clientes apartir de uma agencia***///
void retira_todos_os_clientes_vinculado_agencia(Clientes** inicio, int v)//v = codigo da agencia
{
    Clientes* p = *inicio;
    if(p == NULL){
        printf("não tem clientes para retirar\n");
        return;
    }
    printf("chegou no while remove clientes apartir de uma agencia");
    while(p != NULL){
        if(p->codigo_agencia == v){
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
///****remove o clientes apartir de uma agencia***///
void retira_cliente_vinculado_agencia(Clientes** inicio, int agencia_ver, int cpf_ver)
{
    Clientes* p = *inicio;
    if(p == NULL){
        printf("não tem clientes para retirar\n");
        return;
    }
    printf("chegou no while\n");
    while(p != NULL){
        if((p->codigo_agencia == agencia_ver) && (p->cpf == cpf_ver)){
                /* retira elemento do encadeamento */
               if (*inicio == p){/* testa se é o primeiro elemento */
                  *inicio = p->prox;
                  free(p);
                  return;
               }else{
                  p->ant->prox = p->prox;
                  free(p);
                  return;
               }
               if (p->prox != NULL){ 	/* testa se é o último elemento */
                  p->prox->ant = p->ant;
                  free(p);
                  return;
               }
        }
        p = p->prox;
   }
}
///****remove no gerente apartir de uma agencia****///
void retira_gerente_agencia(Gerente** inicio, int codigo_de_agencia)
{
    Gerente* p = *inicio;
    if(p == NULL){
        printf("não tem gerentes para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->codigo_agencia == codigo_de_agencia){
               /* retira elemento do encadeamento */
               if (*inicio == p)		/* testa se é o primeiro elemento */
                  *inicio = p->prox;
               else
                  p->ant->prox = p->prox;

               if (p->prox != NULL) 	/* testa se é o último elemento */
                  p->prox->ant = p->ant;
               free(p);
        }
        p = p->prox;
   }
}
///***************remove todos clientes***************///
void retira_todos_cliente(Clientes** inicio, int cpf_ver)
{
    Clientes* p = *inicio;
    if(p == NULL){
        printf("não tem clientes para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->cpf == cpf_ver){
            /* retira elemento do encadeamento */
            if (*inicio == p)		/* testa se é o primeiro elemento */
                *inicio = p->prox;
            else
                p->ant->prox = p->prox;

            if (p->prox != NULL) 	/* testa se é o último elemento */
                p->prox->ant = p->ant;
                free(p);
        }
        p = p->prox;
    }
}
///***************remove todos contas*****************///
void retira_todas_contas(Contas** inicio, int cpf_ver)
{
    Contas* p = *inicio;
    if(p == NULL){
        printf("não tem contas para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->cpf_cliente_conta == cpf_ver){
            /* retira elemento do encadeamento */
            if (*inicio == p)		/* testa se é o primeiro elemento */
                *inicio = p->prox;
            else
                p->ant->prox = p->prox;

            if (p->prox != NULL) 	/* testa se é o último elemento */
                p->prox->ant = p->ant;
            free(p);
        }
        p = p->prox;
    }

}
///***************remove no gerentes***************///
void retira_gerente_da_agencia(Gerente** inicio, int v)
{//usa cpf para remover
    Gerente* p = *inicio;
    if(p == NULL){
        printf("não tem gerentes para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->cpf == v){
               /* retira elemento do encadeamento */
               if (*inicio == p)		/* testa se é o primeiro elemento */
                  *inicio = p->prox;
               else
                  p->ant->prox = p->prox;

               if (p->prox != NULL) 	/* testa se é o último elemento */
                  p->prox->ant = p->ant;
               free(p);
        }
        p = p->prox;
   }
}
///**********remove contas de uma agencia**********///
void retira_todas_contas_apartir_agencia(Contas** inicio,int v)
{
    Contas* p = *inicio;
    if(p == NULL){
        printf("não tem contas para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->codigo_agencia_conta == v){
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
///****remover transações apartir de uma agência***///
void retira_todas_transacoes_apartir_agencia(Transacoes** inicio,int v)
{
    Transacoes* p = *inicio;
    if(p == NULL){
        printf("não tem transações para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->codigo_agencia_da_trans == v){
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
///*******remover conta apartir de um cliente******///
void retira_todas_contas_apartir_clientes(Contas** inicio,int v)//v = cpf cliente
{
    Contas* p = *inicio;
    if(p == NULL){
        printf("não tem contas para retirar\n");
        return;
    }
    while(p != NULL){
        if(p->codigo_agencia_conta == v){
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
///imprime uma lista

///***************imprime na agencia****************///
void Agencia_imprime(Agencia* inicio)
{
    Agencia* p = inicio;
    printf("\n\nA LISTA DE AGENCIAS: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        printf("Código da agência: %d | Nome da agência: %s | Endereço: %s | Nome gerente: %s", p->codigo_da_agencia, p->nome, p->endereco, p->nome_gerente);
        printf("\n");
        p = p->prox;
    }
    printf("\n");
}
///***************imprime no clientes***************///
void Clientes_imprime(Clientes* inicio)
{
    Clientes* p = inicio;
    printf("\n\nA LISTA DE CLIENTES: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        printf("Código da agência: %d | Cpf: %d | Nome: %s | Telefone: %s", p->codigo_agencia, p->cpf, p->nome, p->telefone);
        printf("\n");
        p = p->prox;
    }
    printf("\n");
}
///***************imprime no gerentes***************///
void Gerente_imprime(Gerente* inicio)
{
    Gerente* p = inicio;
    printf("\n\nA LISTA DE GERENTES:\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        printf("Código da agência: %d | Cpf: %d | Nome: %s | Telefone: %s", p->codigo_agencia, p->cpf, p->nome, p->telefone);
        p = p->prox;
        printf("\n");
    }
    printf("\n");
}
///******imprime no transaçoes de uma agencia*******///
void imprime_transacoes_de_uma_agencia(Transacoes* inicio_TR, int codigo_agencia_exc)
{
    Transacoes* p = inicio_TR;
    printf("\n\nA LISTA DE TRANSAÇÕES NESTA AGÊNCIA: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->codigo_agencia_da_trans==codigo_agencia_exc){
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
///********imprime as contas de uma agencia*********///
void imprime_contas_de_uma_agencia(Contas* inicio_CO, int codigo_agencia_exc)
{
    Contas* p = inicio_CO;
    printf("\n\nA LISTA DE CONTAS NESTA AGÊNCIA: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->codigo_agencia_conta == codigo_agencia_exc){
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
///**imprime a contas de um cliente em uma agencia**///
void imprime_conta_cliente_especifico_agencia_espcifica(Contas** inicio_CO,int cpf_ver,int codigo_agencia_ver)
{
    Contas* p = *inicio_CO;
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if((p->cpf_cliente_conta == cpf_ver)&&(p->codigo_agencia_conta == codigo_agencia_ver)){
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
///*********imprime a contas de um cliente**********///
void imprime_contas_de_um_cliente(Contas** inicio, int cpf_ver)
{
    Contas* p = *inicio;
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

///destroi uma lista

///***************destroi na agencia****************///
///***************destroi no clientes***************///
///***************destroi no gerentes***************///


///procura na lista

///***************procura na agencia****************///
Agencia* Agencia_busca (Agencia* inicio, int v)
{//encontra agencia com mesmo código
   Agencia* p = inicio;
   while(p!=NULL){
       if (p->codigo_da_agencia == v)
          return p;
       p=p->prox;
   }
   return NULL;	/* não achou o elemento */
}
///***************procura no clientes***************///
Clientes* Clientes_busca_AGespecifica(Clientes* inicio, int codigo_ag, int cpf_ver)
{//procura cliente de uma agencia especifica
    Clientes* p = inicio;
    while(p!=NULL){
        if((p->codigo_agencia == codigo_ag) && (p->cpf == cpf_ver)){
            return p;
        }
        p=p->prox;
    }
    return NULL;
}
///**********procura no clientes se existe**********///
Clientes* Clientes_busca_existe(Clientes* inicio, int cpf_ver)
{//procura cliente e diz se existe
    Clientes* p = inicio;
    while(p!=NULL){
        if(p->cpf == cpf_ver){
            return p;///retorna se existe
        }
        p=p->prox;
    }
    return NULL;///retorna se não existe
}
///*procura no clientes e imprime de todas contas***///
void Clientes_busca_imprime_cliente_allcontas(Clientes* inicio, int cpf_ver)
{//procura cliente e imprime todas suas contas em todas agencias
    Clientes* p = inicio;
    while(p!=NULL){
        if(p->cpf == cpf_ver){
            printf("Código da agência: %d | Cpf: %d | Nome: %s | Telefone: %s", p->codigo_agencia, p->cpf, p->nome, p->telefone);
            printf("\n");
        }
        p=p->prox;
    }
}
///***************procura no gerentes***************///
Gerente* Gerente_busca (Gerente* inicio, int cpf_ver)
{//encontra agencia com mesmo código
   Gerente* p = inicio;
   while(p!=NULL){
       if (p->cpf == cpf_ver)
          return p;
       p=p->prox;
   }
   return NULL;	/* não achou o elemento */
}

///cria lista

///***************cria na agencia****************///
void Agencia_cria(Agencia** inicio)
{//cria lista agencia
   *inicio = NULL;
}
///***************cria no clientes***************///
void Clientes_cria(Clientes** inicio)
{//cria lista clientes
   *inicio = NULL;
}
///***************cria no gerentes***************///
void Gerente_cria(Gerente** inicio)
{//cria lista gerente
   *inicio = NULL;
}
///***************cria no contas*****************///
void Contas_cria(Contas** inicio)
{//cria lista contas
   *inicio = NULL;
}
///***************cria no transferência**********///
void Transacoes_cria(Transacoes** inicio)
{//cria lista transações
   *inicio = NULL;
}


///verifica se lista vazia

///***************vazia? na agencia****************///
int Agencia_vazia(Agencia* inicio)
{
    return(inicio==NULL);
}
///***************vazia? no clientes***************///
int Clientes_vazia(Clientes* inicio)
{
    return(inicio==NULL);
}
///***************vazia? no gerentes***************///
int Gerente_vazia(Gerente* inicio)
{
    return(inicio==NULL);
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

///*********imprime relação agencia/cliente*********///
void imprime_clientes_de_uma_agencia(Clientes* inicio, int codigo_agencia_verf)
{
    Clientes* p = inicio;
    printf("A LISTA DE CLIENTES DA AGÊNCIA: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->codigo_agencia == codigo_agencia_verf){
            printf("Código da agência: %d | Cpf: %d | Nome: %s | Telefone: %s", p->codigo_agencia, p->cpf, p->nome, p->telefone);
            printf("\n");
        }
        p = p->prox;
    }
    printf("\n");
}





