#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "constas.h"
#include "funcoes_para_contas.h"

/// Deve ser possível cadastrar contas de clientes em agências: incluir contas, excluir contas e listas todas as contas.
///o Uma conta só pode ser criada para um cliente que exista na lista de clientes, e em uma agência que exista na lista de
///agências.


/// Sobre as contas, guardar: número da conta, cliente da conta, agência da conta, data de criação da conta, saldo e valor de
///limite permitido. Não é permitido guardar dados duplicados dos clientes ou das agências na lista de contas; deve-se guardar a
///referência aos clientes e às agências de uma das seguintes formas: ou armazenando-se na lista de contas apenas os
///respectivos códigos (de cliente e de agência) ou via apontadores para aquelas listas. Para excluir uma conta, informe o
///código da conta (se houver transações bancárias desta conta, avisar o usuário e removê-las também).

void incluir_contas(Agencia** AG, Clientes** CL, Contas** CO)
{
    int cpf_ver;
    int codigo_agencia_ver;
    int codigo_conta;
    int temp, temp2=0;
    int dia,mes,ano;
    float saldo_cad, limite_cad;
    ///numero da conta
    printf("\nDIGITE O NÚMERO DA CONTA:\n");
    do{
        temp = 0;
        scanf("%d", &codigo_conta);
        temp = verifica_se_codigo_conta_ja_existe(*CO, codigo_conta );
        if(temp==1){
            printf("\nConta Já Existe.\n");
            return;
        }
    }while(temp==1);
    ///cpf cliente para procura-lo
    printf("\nDIGITE O CPF DO DONO DA CONTA:\n");
    scanf("%d", &cpf_ver);
    ///agencia da conta
    printf("\nDIGITE O CÓDIGO DA AGENCIA DA CONTA:\n");
    scanf("%d", &codigo_agencia_ver);
    printf("\nVERIFICANDO OS DADOS:");
    temp2 = Clientes_busca_para_contas(*CL, cpf_ver, codigo_agencia_ver);///verificar se bate dados de cliente
    if(temp2 == 1){
        ///data criação da conta
        printf("\nDIGITE O DIA DA CRIAÇÃO DA CONTA:\n");
        scanf("%d", &dia);
        printf("\nDIGITE O MES DA CRIAÇÃO DA CONTA:\n");
        scanf("%d", &mes);
        printf("\nDIGITE O ANO DA CRIAÇÃO DA CONTA:\n");
        scanf("%d", &ano);
        printf("\nDIGITE O SALDO INICIAL DO CLIENTE:\n");
        scanf("%f", &saldo_cad);
        printf("\nDIGITE O LIMITE MAXIMO DO CLIENTE:\n");
        scanf("%f", &limite_cad);
        Conta_insere (CO, dia, mes, ano, saldo_cad, limite_cad, codigo_agencia_ver, cpf_ver, codigo_conta);
        printf("\nINSERIDO COM SUCESSO!!\n");
    }else{
        printf("\nNÃO EXISTE ESTE CLIENTE E/OU AGÊNCIA!!!\n");
    }
}

void excluir_contas(Contas** CO)
{
    int opcao;
    int cod_excluir, codigo_ag_excluir, cpf_excluir;
	do{
        imprime_menu_contas_excluir();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///listar contas de um cliente
			    printf("\nDIGITE O CPF DO CLIENTE QUE DESEJA APAGAR TODAS CONTAS:\n");
			    scanf("%d", &cpf_excluir);
                excluir_contas_de_um_cliente(CO, cpf_excluir);
				break;
			case 2:///listar contas de uma agencia
			    printf("\nDIGITE O CÓDIGO DA AGÊNCIA QUE DESEJA APAGAR TODAS CONTAS:\n");
			    scanf("%d", &codigo_ag_excluir);
				excluir_contas_de_uma_agencia(CO, codigo_ag_excluir);
				break;
            case 3:///listas todas as contas
                printf("\nDIGITE O CÓDIGO DA CONTA:\n");
                scanf("%d", &cod_excluir);
				excluir_contas_pelo_codigo(CO, cod_excluir);
				break;
			case 4:///listas todas as contas
				excluir_contas_todas(CO);///destroi a lista
				break;
			case 5:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=5);
}

void listar_contas(Contas* CO)
{
    int opcao;
	do{
        imprime_menu_contas_listar();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///listar contas de um cliente
				listar_contas_de_um_cliente(&CO);
				break;
			case 2:///listar contas de uma agencia
				listar_contas_de_uma_agencia(&CO);
				break;
			case 3:///listas todas as contas
				listar_contas_todas(&CO);
				break;
			case 4:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=4);
}

void menu_contas(Agencia** AG, Clientes** CL, Contas** CO)
{
    int opcao;
	do{
        imprime_menu_contas();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///incluir transação
				incluir_contas(AG, CL, CO);
				break;
			case 2:///excluir transação
				excluir_contas(CO);
				break;
			case 3:///listas todas as transações
				listar_contas(*CO);
				break;
			case 4:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=4);
}



