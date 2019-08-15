#include "imprime_terminal_admBanco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "terminal_admBanco.h"
#include "terminal_cadastro.h"
#include "terminal_excluir.h"
#include "relatorios.h"
#include "constas.h"
#include "transacoes.h"
/*
	O que pode fazer neste terminal:
		1 - cadastro de ag�ncias.
		2 - cadastro de gerentes para cada ag�ncia.
		4 - cadastro de clientes para cada ag�ncia.
		5 - emitir relat�rios.
		6 - excluir qualquer dado;
*/

///***************cadastros do adm***************///
void terminal_admBanco_cadastrar(Agencia** l, Clientes** c, Gerente** g)
{
	int opcao;///variavel para o switch
	do{
		imprime_cadastro_adm();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				cadastrar_agencias(l);
				break;
			case 2:
				cadastrar_gerente(g, l);
				break;
			case 3:
				cadastrar_clientes(c, l);
				break;
			case 4://sair
				break;
			default:
				printf("Opc�o invalida!\n");
		}
	}while(opcao!=4);
}

///***************excluir do adm***************///
void terminal_admBanco_excluir(Agencia** l, Clientes** c, Gerente** g, Contas** CO, Transacoes** TR)
{
	int opcao;///variavel para o switch
	do{
		imprime_excluir_adm();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				excluir_agencias(l, c, g, CO, TR);
				break;
			case 2:
				excluir_gerentes(g);
				break;
			case 3:
				excluir_clientes(c,CO,TR);
				break;
			case 4://sair
				break;
			default:
				printf("Opc�o invalida!\n");
		}
	}while(opcao!=4);
}

///*****************relatorios*****************///
void terminal_relatorios(Agencia* l, Clientes* c, Gerente* g, Contas* CO, Transacoes* TR)
{
    int opcao;
    do{
        imprime_relatorios_adm();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:///R1: listar o nome dos clientes e o nome da ag�ncia em que estes possuem conta
                listar_clientes_agencia_possuem_conta(l, c);
                break;
            case 2:///R2: listar as ag�ncias que ainda n�o possuem nenhuma conta aberta
                listar_agencias_que_nao_possue_conta(l,CO);
                break;
            case 3:///R3: listar todos os saques efetuados em certo m�s informado pelo usu�rio
                listar_saques_efetuados_em_certo_mes(TR);
                break;
            case 4:///R4: listar o saldo das contas que n�o est�o no negativo
                listar_saldo_que_estao_negativo(CO);
                break;
            case 5:///R5: listar todas as contas de certo cliente informado pelo usu�rio
                listar_contas_de_certo_cliente(CO);
                break;
            case 6:///R6: listar todas as transfer�ncias banc�rias efetuadas numa certa ag�ncia informada pelo usu�rio
                listar_transferencias_efetuadas_em_uma_agencia(TR);
                break;
            case 7:///R7: listar todas as transa��es banc�rias realizadas por certo cliente informado pelo usu�rio
                listar_transacoes_realizada_por_cliente(TR);
                break;
            case 8:///R8: listar todos os pagamentos realizados
                listar_pagamentos_realizados(TR);
                break;
            case 9:///R9: listar o nome dos clientes que n�o realizaram nenhuma transa��o banc�ria.
                listar_clientes_nao_realizaram_transacao(c, TR, CO);
                break;
            case 10:///R10: listar o nome dos clientes que t�m o maior saldo em conta em cada ag�ncia.
                listar_cliente_maior_saldo_cada_agencia(l, c, CO);
                break;
            case 11:///sair
                break;
            default:
                printf("\nOp��o invalida!!\n");
        }
    }while(opcao!=11);
}

///***************listar do adm***************///
void terminal_admBanco_listar(Agencia* l, Clientes* c, Gerente* g)
{
	int opcao;///variavel para o switch
	do{
		imprime_listar_adm();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				Agencia_imprime(l);
				break;
			case 2:
                Gerente_imprime(g);
				break;
			case 3:
			    Clientes_imprime(c);
				break;
			case 4://sair
				break;
			default:
				printf("Opc�o invalida!\n");
		}
	}while(opcao!=4);
}

///***************terminal de op��o do adm***************///
void terminal_admBanco(Agencia* l, Clientes* c, Gerente* g, Contas* CO, Transacoes* TR)
{
	int opcao;///variavel para o switch
	do{
		imprime_boasvindas_adm();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				terminal_admBanco_cadastrar(&l, &c, &g);
				break;
			case 2:// menu listar
				terminal_admBanco_listar(l, c, g);
				break;
			case 3://menu excluir
				terminal_admBanco_excluir(&l, &c, &g, &CO, &TR);
				break;
			case 4://menu relatorios
			    terminal_relatorios(l, c, g, CO, TR);
				break;
            case 5://menu contas
                menu_contas(&l, &c, &CO);
                break;
            case 6://menu transa��es
                menu_transacoes(&l, &c, &CO, &TR);
                break;
            case 7://sair
                break;
			default:
				printf("Opc�o invalida!\n");
		}
	}while(opcao!=7);
}
