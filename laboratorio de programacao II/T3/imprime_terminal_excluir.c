#include <stdio.h>
#include <stdlib.h>
#include "imprime_terminal_excluir.h"

void imprime_excluir_terminal()
{
    printf("_______________________________________________\n");
	printf("        TERMINAL EXCLUIR AGÊNCIA\n");
	printf("_______________________________________________\n");
	printf("DIGITE O CÓDIGO DA AGÊNCIA A SER EXCLUIDA: \n");
}

void imprime_confirmacao_excluir()
{
    printf("________________________________________________\n");
    printf("Você tem certeza que deseja excluir esta agência\n");
	printf("________________________________________________\n");
}

void clientes_relacionados_a_agencia()
{
    printf("________________________________________________\n");
    printf("Se você excluir esta agência apagará as seguintes \ncontas/clientes\n");
	printf("________________________________________________\n");
}

void digita_sim_nao()
{
    printf("________________________________________________\n");
    printf("DIGITE: 1 - PARA SIM\n");
    printf("        2 - PARA NÃO\n");
	printf("________________________________________________\n");
}

void certeza_que_sim_ou_nao()
{
    printf("________________________________________________\n");
    printf("       TEM CERTEZA DE SUA ESCOLHA?\n");
    printf("DIGITE: 1 - PARA SIM\n");
    printf("        2 - PARA NÃO\n");
	printf("________________________________________________\n");
}

void imprime_excluir_gerente()
{
    printf("_______________________________________________\n");
	printf("        TERMINAL EXCLUIR GERENTE\n");
	printf("_______________________________________________\n");
	printf("DIGITE O CPF DO GERENTE A SER EXCLUIDO: \n");
}

void imprime_deletar_gerente_confirmacao()
{
    printf("_______________________________________________________________\n");
    printf("            DELETAR GERENTE!!!\n");
    printf("ESCOLHA UMA OPÇÃO DIGITANDO: \n");
    printf("  1 - PARA DELETAR O GERERENTE\n");
    printf("  2 - PARA CANCELAR\n");
	printf("_______________________________________________________________\n");
}

void imprime_deletar_cliente()
{
    printf("_______________________________________________________________\n");
    printf("                     DELETAR CLIENTE!!!\n");
    printf("ESCOLHA UMA OPÇÃO DIGITANDO: \n");
    printf("  1 - PARA DELETAR A CONTA DO CLIENTE EM TODAS AGENCIAS.\n");
    printf("  2 - PARA DELETAR A CONTA DO CLIENTE EM UMA AGENCIA ESPECIFICA.\n");
    printf("  3 - PARA RETORNAR.\n");
	printf("_______________________________________________________________\n");
}

void imprime_deleta_cliente_all_agencia_cpf()
{
    printf("_______________________________________________________________\n");
    printf("            DELETAR CLIENTE EM TODAS AGENCIAS!!!\n");
    printf("DIGITE O CPF DO CLIENTE:\n");
}

void imprime_deleta_cliente_uma_agencia_cpf()
{
    printf("_______________________________________________________________\n");
    printf("            DELETAR CLIENTE EM UMA AGENCIA!!!\n");
    printf("DIGITE O CPF DO CLIENTE:\n");
}

void imprime_deleta_cliente_uma_agencia_codigo()
{
    printf("_______________________________________________________________\n");
    printf("            DELETAR CLIENTE DE UMA AGENCIA!!!\n");
    printf("DIGITE A AGÊNCIA DO CLIENTE PARA REMOVE-LO: \n");
}

void imprime_deletar_cliente_all_agencia_confirmacao()
{
    printf("_______________________________________________________________\n");
    printf("            DELETAR CLIENTE EM TODAS AGENCIAS!!!\n");
    printf("ESCOLHA UMA OPÇÃO DIGITANDO: \n");
    printf("  1 - PARA DELETAR OS CLIENTES\n");
    printf("  2 - PARA CANCELAR\n");
	printf("_______________________________________________________________\n");
}

void imprime_deletar_cliente_uma_agencia_confirmacao()
{
    printf("_______________________________________________________________\n");
    printf("            DELETAR CLIENTE NESTA AGENCIA!!!\n");
    printf("ESCOLHA UMA OPÇÃO DIGITANDO: \n");
    printf("  1 - PARA DELETAR O CLIENTE\n");
    printf("  2 - PARA CANCELAR\n");
	printf("_______________________________________________________________\n");
}

void imprime_deletar_cliente_all_agencia_transacoes()
{
    printf("_______________________________________________________________\n");
    printf("        VOCÊ TEM CERTEZA QUE DESEJA DELETAR ESTE\n");
    printf("             CLIENTE EM TODAS AGENCIAS?\n");
    printf("\n");
    printf("         AO DELETAR O CLIENTE TAMBÉM IRA APAGAR\n");
    printf("              TODAS SUAS CONTAS ABAIXO \n");
	printf("_______________________________________________________________\n");
}

void imprime_deletar_cliente_uma_agencia_conta()
{
    printf("_______________________________________________________________\n");
    printf("        VOCÊ TEM CERTEZA QUE DESEJA DELETAR ESTE\n");
    printf("                CLIENTE NESTA AGENCIA?\n");
    printf("\n");
    printf("         AO DELETAR O CLIENTE TAMBÉM IRA APAGAR\n");
    printf("                  SUAS CONTA ABAIXO \n");
	printf("_______________________________________________________________\n");
}
