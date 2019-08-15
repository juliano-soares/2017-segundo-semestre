#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

///R1: listar o nome dos clientes e o nome da ag�ncia em que estes possuem conta
void listar_clientes_agencia_possuem_conta(Agencia* inicio, Clientes* c);

///R2: listar as ag�ncias que ainda n�o possuem nenhuma conta aberta
void listar_agencias_que_nao_possue_conta(Agencia* l, Contas* CO);

///R3: listar todos os saques efetuados em certo m�s informado pelo usu�rio
void listar_saques_efetuados_em_certo_mes(Transacoes* inicio);

///R4: listar o saldo das contas que n�o est�o no negativo
void listar_saldo_que_estao_negativo(Contas* inicio);

///R5: listar todas as contas de certo cliente informado pelo usu�rio
void listar_contas_de_certo_cliente(Contas* inicio);

///R6: listar todas as transfer�ncias banc�rias efetuadas numa certa ag�ncia informada pelo usu�rio
void listar_transferencias_efetuadas_em_uma_agencia(Transacoes* inicio);

///R7: listar todas as transa��es banc�rias realizadas por certo cliente informado pelo usu�rio
void listar_transacoes_realizada_por_cliente(Transacoes* inicio);

///R8: listar todos os pagamentos realizados
void listar_pagamentos_realizados(Transacoes* inicio);

///R9: listar o nome dos clientes que n�o realizaram nenhuma transa��o banc�ria.
void listar_clientes_nao_realizaram_transacao(Clientes* cl, Transacoes* TR, Contas* CO);

///R10: listar o nome dos clientes que t�m o maior saldo em conta em cada ag�ncia.
void listar_cliente_maior_saldo_cada_agencia(Agencia* l, Clientes* c, Contas* CO);

#endif // RELATORIOS_H_INCLUDED
