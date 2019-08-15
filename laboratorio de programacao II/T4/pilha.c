#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pilha.h"


Pilha* pilha_cria (void)
{
   Pilha* p = (Pilha*) malloc(sizeof(Pilha));
   p->prim = NULL;
   return p;
}

void pilha_libera (Pilha* p)
{
   No* q = p->prim;
   while (q!=NULL) {
      No* t = q->prox;
      free(q);
      q = t;
   }
   free(p);
}

int pilha_vazia (Pilha* p)
{
   return (p->prim==NULL);
}

void pilha_push (Pilha* p,int idnovo, int TIPO, int T_CHEG,int T_EXC)
{
   No* n = (No*) malloc(sizeof (No));


   n->id = idnovo;
   n->tipo = TIPO;
   n->t_chegada = T_CHEG ;
   n->t_exec  = T_EXC;

   n->prox = p->prim;
   p->prim = n;
}

void pilha_pop (Pilha* p)
{
   No* t;
   if (pilha_vazia(p)) {
      printf("Pilha vazia.\n");
   }
   t = p->prim;
   p->prim = t->prox;
   free(t);
}

void imprime(Pilha * p)
{
   No* q = p->prim;
   while (q!=NULL) {
      No* t = q->prox;
      printf("\nID = P%d TEMPO CHEGADA = %d TEMPO EXECUCAO = %d TIPO = %d\n", q->id, q->t_chegada, q->t_exec, q->tipo);
      q = t;
   }
}
