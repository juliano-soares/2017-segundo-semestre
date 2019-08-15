#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct nol Nol;

void lst_cria(Nol ** inicio);
int lst_busca (Nol* inicio, int v);
void lst_insere (Nol** inicio, int codigo_inserir, float media_inserir, char *nome_inserir);
void lst_insere_final (Nol** inicio, int v);
void lst_retira (Nol** inicio, int v);
void lst_imprime(Nol * inicio);
void lst_imprime_para_tras(Nol * inicio);

#endif // LISTA_H_INCLUDED
