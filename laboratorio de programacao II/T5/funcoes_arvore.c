#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "funcoes_arvore.h"

/*composição de um no*/
struct no{
   int info;
   float nota;
   char * nome;
   struct no* pai;
   struct no* esq;
   struct no* dir;
};

/*composição de uma arvore*/
struct arvore{
    No * raiz;
};

static void arv_libera_no(No * no);
void arv_insere_no2(No * no, int v, float m, char * n);

static void arv_insere (No* pai, No* filho, int dir);

static void arv_remove_no3(No * filho);
static int arv_remove_no2(No * no, int v);

static No * encontra_maior(No * no);
static No * encontra_menor(No * no);

void arv_insere_no2_codigo(No * no, int v, float m, char * n);
void arv_insere_no2_nome(No * no, int v, float m, char * n);
void arv_insere_no2_nota(No * no, int v, float m, char * n);
/* função de criação */
Arvore * arv_cria ()
{
    Arvore * arv = (Arvore *) malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

/* função de criação */
No * arv_cria_no (int v, float m, char * n)
{
    No * no = (No *) malloc(sizeof(No));
    no->info = v;
    no->nome = n;
    no->nota = m;
    no->esq = NULL;
    no->dir = NULL;
    no->pai = NULL;
    return no;
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int arv_vazia (Arvore * arvore)
{
   return (arvore->raiz == NULL);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int arv_no_vazio (No * no)
{
   //supondo que no não seja nulo
   return (no->esq==NULL && no->dir == NULL);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
No * arv_busca_raiz (Arvore * arvore)
{
   return (arvore->raiz);
}

No* arv_busca_filho(No * no, int dir){
    if (dir)
        return no->dir;
    else return no->esq;
}

void arv_busca_valor(No * no, int temp)
{
    if(temp == 1){//por codigo
        printf("codigo = %d, nome= %s, nota = %0.2f,\n", no->info, no->nome, no->nota);
    }if(temp == 2){//por nome
        printf("nome= %s, codigo = %d, nota = %0.2f,\n", no->nome, no->info, no->nota);
    }if(temp == 3){//por nota
        printf("nota = %0.2f, nome= %s, codigo = %d,\n",  no->nota, no->nome, no->info);
    }
}

void arv_libera_arvore(Arvore * arv){

    arv_libera_no(arv->raiz);
    free(arv);
}

static void arv_libera_no(No * no){
    if (no==NULL)
        return;
    arv_libera_no(no->esq);
    arv_libera_no(no->dir);
    free(no);

}

void insere_na_arvore(Arvore * arv, int v, float m, char * n, int aux){
    if(aux == 1){
        if (arv->raiz==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv->raiz = filho;
            return;
        }
        arv_insere_no2_codigo(arv->raiz, v, m, n);
    }if(aux == 2){
        if (arv->raiz==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv->raiz = filho;
            return;
        }
        arv_insere_no2_nome(arv->raiz, v, m, n);
    }if(aux == 3){
        if (arv->raiz==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv->raiz = filho;
            return;
        }
        arv_insere_no2_nota(arv->raiz, v, m, n);
    }
}

void arv_insere_no2_codigo(No * no, int v, float m, char * n){
    if (no==NULL) return;

    if (v < no->info)
    {
        if (no->esq==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv_insere(no, filho, 0);
            return;
        }

        arv_insere_no2_codigo(no->esq, v, m, n);
    }
    else {
        if (no->dir==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv_insere(no, filho, 1);
            return;
        }

        arv_insere_no2_codigo(no->dir, v, m, n);
    }

}

void arv_insere_no2_nota(No * no, int v, float m, char * n){
    if (no==NULL) return;
    if (m < no->nota)
    {
        if (no->esq==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv_insere(no, filho, 0);
            return;
        }
        arv_insere_no2_nota(no->esq, v, m, n);
    }
    else {
        if (no->dir==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv_insere(no, filho, 1);
            return;
        }
        arv_insere_no2_nota(no->dir, v, m, n);
    }
}

void arv_insere_no2_nome(No * no, int v, float m, char * n){///comparação entre strings
    if (no==NULL) return;
    if (m < no->nota)
    {
        if (no->esq==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv_insere(no, filho, 0);
            return;
        }
        arv_insere_no2_nota(no->esq, v, m, n);
    }
    else {
        if (no->dir==NULL){
            No * filho = arv_cria_no (v, m, n);
            arv_insere(no, filho, 1);
            return;
        }
        arv_insere_no2_nota(no->dir, v, m, n);
    }
}

int arv_remove_no(Arvore * arv, int v){
    if (arv->raiz==NULL) return 0;

    return arv_remove_no2(arv->raiz, v);
}

static int arv_remove_no2(No * no, int v){
    if (no==NULL) return 0;

    if (no->info==v)
    {
        arv_remove_no3(no);
        return 1;
    }

    if (v < no->info)
        return arv_remove_no2(no->esq, v);
    else return arv_remove_no2(no->dir, v);

}

static void arv_remove_no3(No * filho){

    if (filho->esq==NULL && filho->dir == NULL)
    {
        if (filho->pai->esq==filho)
            filho->pai->esq = NULL;
        else filho->pai->dir = NULL;
        free(filho);
        return;
    }
    if (filho->esq!=NULL) {

        No * maior = encontra_maior(filho->esq);
        filho->info = maior->info;

        arv_remove_no3(maior);
        return;
    }
    else{

        No * menor = encontra_menor(filho->dir);
        filho->info = menor->info;

        arv_remove_no3(menor);
        return;
    }

}

No * arv_busca_no(No * no, int v){
    if (no==NULL)
        return NULL;

    if (no->info==v)
        return no;
    if (v<no->info)
        return arv_busca_no(no->esq, v);

    return arv_busca_no(no->dir, v);

}

static No * encontra_maior(No * no)
{
    if (no->dir==NULL) return no;
    return encontra_maior(no->dir);
}

static No * encontra_menor(No * no)
{
    if (no->esq==NULL) return no;
    return encontra_menor(no->esq);
}

/* inserção de um no filho abaixo de um no pai */
static void arv_insere (No* pai, No* filho, int dir)
{
   if (dir)
       pai->dir = filho;
   else
      pai->esq = filho;

   filho->pai = pai;

}
