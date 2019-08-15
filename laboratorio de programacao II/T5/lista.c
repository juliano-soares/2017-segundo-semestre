#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

struct nol {
   int codigo;
   float notafinal;
   char* nome;
   struct nol* ant;
   struct nol* prox;
};

/* função busca: busca um elemento na lista */
int lst_busca (Nol* inicio, int v)
{
   Nol* p = inicio;
   while(p!=NULL) {
       if (p->codigo == v){
          return 1;
       }
       p=p->prox;
   }

   return 0;	/* não achou o elemento */
}

Nol* lst_busca_retira (Nol* inicio, int v)
{
   Nol* p = inicio;
   while(p!=NULL) {
       if (p->codigo == v)
          return p;
       p=p->prox;
   }

   return NULL;	/* não achou o elemento */
}

void lst_insere (Nol** inicio, int codigo_inserir, float media_inserir, char * nome_inserir)
{
   Nol* novo = (Nol*) malloc(sizeof(Nol));
   novo->codigo = codigo_inserir;
   novo->nome = nome_inserir;
   novo->notafinal = media_inserir;
   novo->prox = *inicio;
   novo->ant = NULL;
   if (*inicio != NULL)
      (*inicio)->ant = novo;
   *inicio = novo;
}

/* função retira: remove elemento da lista */
void lst_retira (Nol** inicio, int v)
{
   Nol* p = lst_busca_retira(*inicio,v);
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

void lst_cria(Nol** inicio)
{
   *inicio = NULL;
}

void lst_insere_final(Nol** inicio, int v)
{
   Nol* novo = (Nol*)malloc(sizeof(Nol));

   novo->codigo = v;
   novo->prox = NULL;

   if ( *inicio == NULL ) { // se a lista eh vazia
      novo->ant = NULL;
      *inicio = novo;
   } else {
      Nol* p = *inicio;
      while ( p->prox != NULL ) {
         p = p->prox;
      }
      p->prox = novo;
      novo->ant = p;
   }
}

void lst_imprime(Nol* inicio)
{
   Nol* p = inicio;

   printf("\n\nImprime: \n");
   while ( p != NULL ) {
      printf("codigo = %d, nome = %s, nota = %0.2f\n", p->codigo, p->nome, p->notafinal);
      p = p->prox;
   }
   printf("\n");
}

void lst_imprime_para_tras(Nol* inicio)
{
   Nol* p = inicio;

   printf("\n\nImprime para tras: ");
   while ( p != NULL ) {
      printf("codigo = %d, nome = %s, nota = %0.2f\n", p->codigo, p->nome, p->notafinal);
      p = p->ant;
   }
   printf("\n");
}
