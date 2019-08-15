#ifndef FUNCOES_PARA_TRANSACOES_H_INCLUDED
#define FUNCOES_PARA_TRANSACOES_H_INCLUDED
void excluir_todas_transacoes();

void excluir_uma_transacoes();

void excluir_transacoes_de_uma_agencia();

void excluir_transacao_de_um_cliente();

void excluir_todas_transacoes();

void listar_transacao_de_um_cliente_por_periodo(Transacoes* inicio);

void listar_transacoes_de_um_cliente_feita_numa_agencia(Transacoes* inicio);

void listar_todas_transacoes_do_cliente(Transacoes* inicio);

void listar_transacao_de_uma_agencia_por_periodo(Transacoes* inicio);

void listar_todas_transacoes_da_agencia(Transacoes* inicio);

void listar_todas_transacao(Transacoes* inicio);

void imprime_menu_transacao_listar();

void imprime_menu_transacao_listar_cliente();

void imprime_menu_transacao();

void imprime_menu_transacao_excluir();

void imprime_menu_transacao_listar_agencia();

void imprime_tipos_transacoes();

#endif // FUNCOES_PARA_TRANSACOES_H_INCLUDED
