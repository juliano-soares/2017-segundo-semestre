#ifndef TERMINAL_EXCLUIR_H_INCLUDED
#define TERMINAL_EXCLUIR_H_INCLUDED

void excluir_agencias(Agencia** inicio, Clientes** inicio_c, Gerente** inicio_g, Contas** inicio_CO, Transacoes** inicio_TR);
void excluir_gerentes(Gerente** inicio);
void deletar_cliente_all_agencias(Clientes** inicio_c, Contas** inicio_CO, Transacoes** inicio_TR);
void deletar_cliente_1agencia(Clientes** inicio_c, Contas** inicio_CO, Transacoes** inicio_TR);
void excluir_clientes(Clientes** inicio_c, Contas** inicio_CO, Transacoes** inicio_TR);
#endif // TERMINAL_EXCLUIR_H_INCLUDED
