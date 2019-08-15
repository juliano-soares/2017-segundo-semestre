#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
/* nó da lista para armazenar valores */
struct noF {
   int id;
   int t_chegada;
   int t_exec;
   int tipo;
   struct noF* prox;
};

typedef struct noF NoF;

/* estrutura da fila */
struct fila {
   NoF* ini;
   NoF* fim;
};
typedef struct fila Fila;


Fila* fila_cria (void);

void fila_insere(Fila * f,int idnovo,int tcheg,int texc, int tiponovo);
void fila_retira (Fila* f);
int fila_tamanho (Fila* f);
int fila_vazia (Fila* f);
void fila_libera (Fila* f);
void imprime_fila(Fila * f);
int verifica_se_existe_exc_sistema(Fila * f);
int processa_comando_somente_primeiro_fila(Fila* f, int tp);

#endif
