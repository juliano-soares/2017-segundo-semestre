#ifndef PRINCIPAL_H_INCLUDED
#define PRINCIPAL_H_INCLUDED
void imprime_menu();
char* le_frases();
void imprime_asc(No * no, int qImprimir);
void incluir_aluno_lista(Arvore * A, Arvore * ANOTA, Arvore * ANOME, Nol ** inicio);
void excluir_aluno_lista(Arvore * A, Arvore * Anota, Arvore * Anome, Nol ** inicio);
void listar_alunos_por_codigo(Arvore * A);
void listar_alunos_por_nome(Arvore * A);
void listar_alunos_por_media_final(Arvore * A);
#endif // PRINCIPAL_H_INCLUDED
