#ifndef FUNCOES_ARVORE_H_INCLUDED
#define FUNCOES_ARVORE_H_INCLUDED
/*tipos exportados*/
typedef struct no No;

typedef struct arvore Arvore;

Arvore * arv_cria ();
No * arv_cria_no (int v, float m, char * n);

int arv_vazia (Arvore * arvore);
int arv_no_vazio (No * no);

No * arv_busca_raiz (Arvore * arvore);

No* arv_busca_filho(No * no, int dir);
void arv_busca_valor(No * no, int temp);

No * arv_busca_no(No * no, int v);

void arv_libera_arvore(Arvore * arv);
void insere_na_arvore(Arvore * arv, int v, float m, char * n, int aux);
void arv_insere_no(Arvore * arv, Nol * v);

int arv_remove_no(Arvore * arv, int v);

#endif // FUNCOES_ARVORE_H_INCLUDED
