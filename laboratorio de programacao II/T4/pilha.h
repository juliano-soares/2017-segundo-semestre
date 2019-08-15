#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/* nó da lista para armazenar valores reais */
struct no{
   int id;
   int t_chegada;
   int t_exec;
   int tipo;
   struct no* prox;
};

typedef struct no No;

/* estrutura da pilha */
struct pilha {
   No* prim;    /* aponta para o topo da pilha */
};

typedef struct pilha Pilha;

Pilha* pilha_cria (void);
int pilha_vazia (Pilha* p);

void pilha_push (Pilha* p,int idnovo, int TIPO, int T_CHEG,int T_EXC);
void pilha_pop (Pilha* p);

void pilha_libera (Pilha* p);
void imprime(Pilha * p);
#endif
