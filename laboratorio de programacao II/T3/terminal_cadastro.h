#ifndef TERMINAL_CADASTRO_H_INCLUDED
#define TERMINAL_CADASTRO_H_INCLUDED
void cadastrar_agencias(Agencia** l);

void cadastrar_clientes(Clientes** c, Agencia** l);

void cadastrar_gerente(Gerente** g, Agencia** l);

int cadastro_nome_agencia_verif(Agencia* inicio, char* v);

int verifica_cpf_nesta_agencia(Clientes* inicio, int cpf_NV, int codigo_agencia_NV);

int verifica_agencia_existe(Agencia* inicio,int codigo_agencia_ver);

int verifica_agencia_gerente_igual(Agencia* inicio, char* nome, int codigo_agencia_ver);

int verifica_cliente_existe(Clientes* inicio, int cpf_ver);
#endif // TERMINAL_CADASTRO_H_INCLUDED
