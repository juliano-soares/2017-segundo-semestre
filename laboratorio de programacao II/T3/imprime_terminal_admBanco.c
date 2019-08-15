#include <stdio.h>
#include <stdlib.h>
#include "imprime_terminal_admBanco.h"

void imprime_boasvindas_adm()
{
	printf("==========================================\n");
	printf("       SEJA BEM-VINDO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - FAZER CADASTROS                  ||\n");
	printf("|| 2 - EMITIR RELATORIOS                ||\n");
	printf("|| 3 - EXCLUIR ALGUM CADASTRO           ||\n");
	printf("|| 4 - RELATÓRIOS                       ||\n");
    printf("|| 5 - MENU CONTAS                      ||\n");
    printf("|| 6 - MENU TRANSAÇÕES                  ||\n");
    printf("|| 7 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_cadastro_adm()
{
	printf("==========================================\n");
	printf("    SEÇÃO DE CADASTRO DO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - CADASTRAR AGÊNCIAS               ||\n");
	printf("|| 2 - CADASTRAR GERENTES               ||\n");
	printf("|| 3 - CADASTRAR CLIENTES               ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_excluir_adm()
{
	printf("==========================================\n");
	printf("   SEÇÃO DE RELATORIOS DO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - EXCLUIR AGÊNCIAS                 ||\n");
	printf("|| 2 - EXCLUIR GERENTES                 ||\n");
	printf("|| 3 - EXCLUIR CLIENTES                 ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_listar_adm()
{
	printf("==========================================\n");
	printf("   SEÇÃO DE LISTAS DO ADMINISTRADOR!\n");
	printf("==========================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:               ||\n");
	printf("|| 1 - LISTAR AGÊNCIAS                  ||\n");
	printf("|| 2 - LISTAR GERENTES                  ||\n");
	printf("|| 3 - LISTAR CLIENTES                  ||\n");
	printf("|| 4 - SAIR                             ||\n");
	printf("==========================================\n");
}

void imprime_relatorios_adm()
{
	printf("==========================================\n");
	printf("   SEÇÃO DE RELATÓRIOS DO ADMINISTRADOR!\n");
	printf("======================================================================================================\n");
	printf("||ESCOLHA UMA DAS OPÇÕES:                                                                           ||\n");
	printf("|| 1 - listar o nome dos clientes e o nome da agência em que estes possuem conta.                   ||\n");
	printf("|| 2 - listar as agências que ainda não possuem nenhuma conta aberta.                               ||\n");
	printf("|| 3 - listar todos os saques efetuados em certo mês informado pelo usuário.                        ||\n");
	printf("|| 4 - listar o saldo das contas que não estão no negativo.                                         ||\n");
	printf("|| 5 - listar todas as contas de certo cliente informado pelo usuário.                              ||\n");
    printf("|| 6 - listar todas as transferências bancárias efetuadas numa certa agência informada pelo usuário.||\n");
    printf("|| 7 - listar todas as transações bancárias realizadas por certo cliente informado pelo usuário.    ||\n");
    printf("|| 8 - listar todos os pagamentos realizados.                                                       ||\n");
    printf("|| 9 - listar o nome dos clientes que não realizaram nenhuma transação bancária.                    ||\n");
    printf("|| 10 - listar o nome dos clientes que têm o maior saldo em conta em cada agência.                  ||\n");
    printf("|| 11 - SAIR                                                                                        ||\n");
	printf("======================================================================================================\n");

}
