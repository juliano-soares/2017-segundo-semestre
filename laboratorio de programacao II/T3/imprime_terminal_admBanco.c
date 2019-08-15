#include <stdio.h>
#include <stdlib.h>
#include "imprime_terminal_admBanco.h"

void imprime_boasvindas_adm()
{
	printf("==========================================\n");
	printf("       SEJA BEM-VINDO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OP��ES:               ||\n");
	printf("|| 1 - FAZER CADASTROS                  ||\n");
	printf("|| 2 - EMITIR RELATORIOS                ||\n");
	printf("|| 3 - EXCLUIR ALGUM CADASTRO           ||\n");
	printf("|| 4 - RELAT�RIOS                       ||\n");
    printf("|| 5 - MENU CONTAS                      ||\n");
    printf("|| 6 - MENU TRANSA��ES                  ||\n");
    printf("|| 7 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_cadastro_adm()
{
	printf("==========================================\n");
	printf("    SE��O DE CADASTRO DO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OP��ES:               ||\n");
	printf("|| 1 - CADASTRAR AG�NCIAS               ||\n");
	printf("|| 2 - CADASTRAR GERENTES               ||\n");
	printf("|| 3 - CADASTRAR CLIENTES               ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_excluir_adm()
{
	printf("==========================================\n");
	printf("   SE��O DE RELATORIOS DO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OP��ES:               ||\n");
	printf("|| 1 - EXCLUIR AG�NCIAS                 ||\n");
	printf("|| 2 - EXCLUIR GERENTES                 ||\n");
	printf("|| 3 - EXCLUIR CLIENTES                 ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_listar_adm()
{
	printf("==========================================\n");
	printf("   SE��O DE LISTAS DO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OP��ES:               ||\n");
	printf("|| 1 - LISTAR AG�NCIAS                  ||\n");
	printf("|| 2 - LISTAR GERENTES                  ||\n");
	printf("|| 3 - LISTAR CLIENTES                  ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_relatorios_adm()
{
	printf("==========================================\n");
	printf("   SE��O DE RELAT�RIOS DO ADMINISTRADOR!\n");
	printf("======================================================================================================\n");
	printf("||ESCOLHA UMA DAS OP��ES:                                                                           ||\n");
	printf("|| 1 - listar o nome dos clientes e o nome da ag�ncia em que estes possuem conta.                   ||\n");
	printf("|| 2 - listar as ag�ncias que ainda n�o possuem nenhuma conta aberta.                               ||\n");
	printf("|| 3 - listar todos os saques efetuados em certo m�s informado pelo usu�rio.                        ||\n");
	printf("|| 4 - listar o saldo das contas que n�o est�o no negativo.                                         ||\n");
	printf("|| 5 - listar todas as contas de certo cliente informado pelo usu�rio.                              ||\n");
    printf("|| 6 - listar todas as transfer�ncias banc�rias efetuadas numa certa ag�ncia informada pelo usu�rio.||\n");
    printf("|| 7 - listar todas as transa��es banc�rias realizadas por certo cliente informado pelo usu�rio.    ||\n");
    printf("|| 8 - listar todos os pagamentos realizados.                                                       ||\n");
    printf("|| 9 - listar o nome dos clientes que n�o realizaram nenhuma transa��o banc�ria.                    ||\n");
    printf("|| 10 - listar o nome dos clientes que t�m o maior saldo em conta em cada ag�ncia.                  ||\n");
    printf("|| 11 - SAIR                                                                                        ||\n");
	printf("======================================================================================================\n");

}
