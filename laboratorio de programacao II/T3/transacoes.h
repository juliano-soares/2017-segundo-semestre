#ifndef TRANSACOES_H_INCLUDED
#define TRANSACOES_H_INCLUDED

float soma_saques_em_uma_data(Transacoes* TR,int n_conta, int dia, int mes, int ano);

int saque_na_conta(Contas* inicio,int n_conta,float valor);

void transacao_saldo(Contas* inicio);

void transacao_saque(Agencia** l, Contas** CO, Transacoes** TR);

int transfere_para_contas(Contas* inicio, int n_conta1, int n_conta2, float valor);

float soma_transacao_em_uma_data(Transacoes** TR,int n_conta,int dia, int mes, int ano);

void transacao_transferencia(Agencia** l,Contas** CO, Transacoes** TR);

float soma_pagamentos_em_uma_data(Transacoes** TR,int n_conta, int dia, int mes, int ano);

int saque_na_conta_pelo_pagamento(Contas** inicio,int n_conta,float valor);

void transacao_pagamento(Agencia** l, Contas** CO, Transacoes** TR);

void deposita_na_conta(Contas* inicio,int n_conta,float valor_dep);

void transacao_deposito(Agencia** l,Contas** CO, Transacoes** TR);

void fazer_uma_transacao(Agencia** l,Contas** CO, Transacoes** TR);

void excluir_transacao();

void menu_listar_transacao_de_um_cliente();

void menu_listar_transacoes_de_uma_agencia();

void listar_transacao(Transacoes* TR);

void menu_transacoes(Agencia** l, Clientes** c, Contas** CO, Transacoes** TR);

#endif // TRANSACOES_H_INCLUDED
