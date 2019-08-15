#ifndef CONSTAS_H_INCLUDED
#define CONSTAS_H_INCLUDED
void incluir_contas(Agencia** AG, Clientes** CL, Contas** CO);
void excluir_contas(Contas** CO);
void listar_contas(Contas* CO);
void menu_contas(Agencia** AG, Clientes** CL, Contas** CO);
void ver_dados_conta_cliente(Contas** CO, Clientes** inicio);
#endif // CONSTAS_H_INCLUDED
