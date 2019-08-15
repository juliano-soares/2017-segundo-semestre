#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fila.h"

Fila* fila_cria (void)
{
   Fila* f = (Fila*) malloc(sizeof(Fila));
   f->ini = NULL;
   f->fim = NULL;
   return f;
}

int fila_vazia (Fila* f)
{
    return (f->ini==NULL);
}

void fila_insere(Fila * f,int idnovo,int tcheg,int texc, int tiponovo)
{
   NoF* n = (NoF*) malloc(sizeof (NoF));
   n->id = idnovo;
   n->tipo = tiponovo;
   n->t_chegada = tcheg;
   n->t_exec = texc;
   n->prox = NULL;      /* novo nó passa a ser o último      */
   if (f->fim != NULL)    /* verifica se lista não estava vazia */
      f->fim->prox = n;
   else                         /* fila estava vazia                            */
      f->ini = n;
   f->fim = n;               /* fila aponta para novo elemento     */
}

void fila_retira (Fila* f)
{
   if (fila_vazia(f)) {
      printf("Fila vazia.\n");
      f->fim = NULL;
      return;
   }
   NoF* t = f->ini;
   f->ini = t->prox;
   if (f->ini == NULL)	/* verifica se fila ficou vazia */
      f->fim = NULL;
   free(t);
}

void fila_libera (Fila* f)
{
   NoF* q = f->ini;
   while (q!=NULL) {
      NoF* t = q->prox;
      free(q);
      q = t;
   }
   free(f);
}

void imprime_fila(Fila * f)
{
   NoF* q = f->ini;
   while (q!=NULL) {
      NoF* t = q->prox;
      printf("\nID = P%d TEMPO CHEGADA = %d TEMPO EXECUCAO = %d TIPO = %d\n", q->id, q->t_chegada, q->t_exec, q->tipo);
      q = t;
   }

}

int processa_comando_somente_primeiro_fila(Fila* f, int tp)
{
    printf("\nPROCESSANDO O PRIMEIRO COMANDO\n");
    NoF* q = f->ini;
    if(q->t_exec > tp){
        return 1;
    }
    if(q->t_exec <= tp){
        return 0;
    }
}

int verifica_se_existe_exc_sistema(Fila * f)
{
    int cont = 0;
    NoF* q = f->ini;
    while (q!=NULL) {
        NoF* t = q->prox;
        if(q->tipo == 1){
            cont++;
        }
        q = t;
    }
    if(cont>0){
        return 1;
    }
    return 0;
}
