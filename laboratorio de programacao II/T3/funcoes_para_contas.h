#ifndef FUNCOES_PARA_CONTAS_H_INCLUDED
#define FUNCOES_PARA_CONTAS_H_INCLUDED
Contas* Contas_busca (Contas* inicio, int v);
void excluir_contas_pelo_codigo();
void excluir_contas_de_um_cliente();
void excluir_contas_de_uma_agencia();
void excluir_contas_todas();
void listar_contas_de_um_cliente(Contas** inicio);
void listar_contas_de_uma_agencia(Contas** inicio);
void listar_contas_todas(Contas** inicio);
void Conta_insere (Contas** inicio,int dia_cad,int mes_cad,int ano_cad,float saldo_cad,float limite_cad,int codigo_agencia_ver,int cpf_ver,int codigo_conta);
int verifica_se_codigo_conta_ja_existe(Contas* inicio, int v);
int Clientes_busca_para_contas(Clientes* CL, int cpf_ver,int codigo_agencia_ver);
void imprime_menu_contas();
void imprime_menu_contas_listar();
void imprime_menu_contas_excluir();

#endif // FUNCOES_PARA_CONTAS_H_INCLUDED
