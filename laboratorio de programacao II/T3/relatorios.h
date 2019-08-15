#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

///R1: listar o nome dos clientes e o nome da agência em que estes possuem conta
void listar_clientes_agencia_possuem_conta(Agencia* inicio, Clientes* c);

///R2: listar as agências que ainda não possuem nenhuma conta aberta
void listar_agencias_que_nao_possue_conta(Agencia* l, Contas* CO);

///R3: listar todos os saques efetuados em certo mês informado pelo usuário
void listar_saques_efetuados_em_certo_mes(Transacoes* inicio);

///R4: listar o saldo das contas que não estão no negativo
void listar_saldo_que_estao_negativo(Contas* inicio);

///R5: listar todas as contas de certo cliente informado pelo usuário
void listar_contas_de_certo_cliente(Contas* inicio);

///R6: listar todas as transferências bancárias efetuadas numa certa agência informada pelo usuário
void listar_transferencias_efetuadas_em_uma_agencia(Transacoes* inicio);

///R7: listar todas as transações bancárias realizadas por certo cliente informado pelo usuário
void listar_transacoes_realizada_por_cliente(Transacoes* inicio);

///R8: listar todos os pagamentos realizados
void listar_pagamentos_realizados(Transacoes* inicio);

///R9: listar o nome dos clientes que não realizaram nenhuma transação bancária.
void listar_clientes_nao_realizaram_transacao(Clientes* cl, Transacoes* TR, Contas* CO);

///R10: listar o nome dos clientes que têm o maior saldo em conta em cada agência.
void listar_cliente_maior_saldo_cada_agencia(Agencia* l, Clientes* c, Contas* CO);

#endif // RELATORIOS_H_INCLUDED
