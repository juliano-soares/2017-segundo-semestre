#ifndef TERMINAL_ADMBANCO_H_INCLUDED
#define TERMINAL_ADMBANCO_H_INCLUDED

void terminal_admBanco_cadastrar(Agencia** l, Clientes** c, Gerente** g);

void terminal_admBanco_listar(Agencia* l, Clientes* c, Gerente* g);

void terminal_admBanco_excluir(Agencia** l, Clientes** c, Gerente** g, Contas** CO, Transacoes** TR);

void terminal_admBanco(Agencia* l, Clientes* c, Gerente* g, Contas* CO, Transacoes* TR);

void terminal_relatorios(Agencia* l, Clientes* c, Gerente* g, Contas* CO, Transacoes* TR);

#endif // TERMINAL_ADMBANCO_H_INCLUDED
