#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "funcoes_para_transacoes.h"
#include "funcoes_para_contas.h"
#include "funcao_listas.h"
#include "transacoes.h"
#include "terminal_cadastro.h"

float soma_saques_em_uma_data(Transacoes* TR,int n_conta, int dia, int mes, int ano)
{
    float soma=0;
    Transacoes* p = TR;
    while(p!=NULL){
        if((p->dia==dia)&&(p->mes==mes)&&(p->ano==ano) && (p->numero_conta_tran== n_conta)){
            soma+=p->valor;
        }
        p=p->prox;
    }
    return soma;
}

int saque_na_conta(Contas* inicio,int n_conta,float valor)
{
    Contas* p = inicio;
    float temp = p->total;
    if(p == NULL){
        printf("lista vazia\n");
        return 1;
    }
    while(p != NULL){
            printf("entrou no saque conta");
        if(p->codigo_agencia_conta==n_conta){
            temp-=valor;
            if(temp<0){
                printf("\nSALDO E LIMITE ESTOURADO!!\n");
                return 1;
            }else{
                (p->saldo)-= valor;
                (p->total)-= valor;
                printf("\nSAQUE EFETUADO COM SUCESSO!!\n");
            }
            return 0;
        }
        p = p->prox;
    }
    printf("\n\nSAQUE FEITO!! \n");
    printf("\n");
    return 0;
}

void transacao_saque(Agencia** l, Contas** CO, Transacoes** TR)
{/// transação saque codigo ************** 2 ************
    float total_saques_neste_dia,valor;
    int n_conta,cod_ag, n_transacao;
    int temp,temp1, temp2;
    int dia, mes, ano;
    printf("\nDIGITE O NUMERO TRANSAÇÃO:\n");
    scanf("%d", &n_transacao);
    Transacoes* p = *TR;
    while(p!=NULL){
        if(p->codigo_transacao == n_transacao){
            temp1= 1;
        }
        p=p->prox;
    }
    p = *TR;
    if(temp1==1){
        printf("\nJá existe esta operação\n");
        return;
    }
    printf("\nDIGITE O NUMERO DA CONTA PARA EFETUAR SAQUE:\n");
    scanf("%d", &n_conta);
    printf("\nDIGITE O NUMERO DE QUAL AGÊNCIA QUER EFETUAR SAQUE:\n");
    scanf("%d", &cod_ag);
    temp = verifica_agencia_existe(*l, cod_ag);
    temp2 = verifica_se_codigo_conta_ja_existe(*CO, n_conta);
    if((temp == 1)&&(temp2 == 1)){
        printf("\nDIGITE O VALOR QUE DESEJA EFETUAR SAQUE:\n");
        scanf("%f", &valor);
        if(valor<0){
            printf("\nVALORES NEGATIVOS NÃO SÃO PERMITIDOS!!\n");
            return;
        }
        printf("\nDIGITE O DIA DO SAQUE:\n");
        scanf("%d", &dia);
        printf("\nDIGITE O MES DO SAQUE:\n");
        scanf("%d", &mes);
        printf("\nDIGITE O ANO DO SAQUE:\n");
        scanf("%d", &ano);
        total_saques_neste_dia = soma_saques_em_uma_data(*TR,n_conta, dia, mes, ano);
        if((valor <= 1000) && (total_saques_neste_dia <=1000)){
            if(saque_na_conta(*CO,n_conta,valor) == 0){
                Transacoes_insere(TR, n_transacao,n_conta,cod_ag,valor,dia,mes,ano, 2);
            }
        }else{
            printf("\nSAQUE ACIMA DO LIMITE DE R$1000,00 DIÁRIO\n");
        }
    }else{
        printf("\nESTA CONTA E/OU AGÊNCIA NÃO EXISTE!!!\n");
    }
}

float soma_transacao_em_uma_data(Transacoes** TR,int n_conta,int dia, int mes, int ano)
{
    float soma=0;
    Transacoes* p = *TR;
    while(p!=NULL){
        if((p->dia=dia)&&(p->mes=mes)&&(p->ano=ano) && (p->numero_conta_tran==n_conta)){
            soma+=p->valor;
        }
        p=p->prox;
    }
    return soma;
}

void transacao_transferencia(Agencia** l,Contas** CO, Transacoes** TR)
{/// transação transferencia codigo ************** 3 ************
    int n_conta1, n_conta2,dia,mes,ano,cod_ag, n_transacao,temp2;
    float valor, temp, temp1;
    Contas* p = *CO;
    printf("\nDIGITE O NÚMERO DA TRANSAÇÃO:\n");
    scanf("%d", &n_transacao);
    printf("\nDIGITE DE QUAL CONTA DESEJA EFETUAR A TRANSAÇÃO:\n");
    scanf("%d", &n_conta1);
    Transacoes* t = *TR;
    while(t!=NULL){
        if(t->codigo_transacao == n_transacao){
            temp= 1;
        }
        t=t->prox;
    }
    t = *TR;
    if(temp==1){
        printf("\nDIGITE DE QUAL CONTA IRÁ RECEBER A TRANSAÇÃO:\n");
        scanf("%d", &n_conta2);///NÃO IRA VERIFICAR SE CONTA QUE RECEBER DINHEIRO EXISTE
        printf("\nDIGITE O VALOR DA TRANSFERÊNCIA:\n");
        scanf("%f", &valor);
        if(valor<0){
            printf("\nVALORES NEGATIVOS NÃO SÃO PERMITIDOS!!\n");
            return;
        }
        printf("\nDIGITE O DIA DESTA TRANSAÇÃO:\n");
        scanf("%d", &dia);
        printf("\nDIGITE O MÊS DESTA TRANSAÇÃO:\n");
        scanf("%d", &mes);
        printf("\nDIGITE O ANO DESTA TRANSAÇÃO:\n");
        scanf("%d", &ano);
        temp = soma_transacao_em_uma_data(TR,n_conta1,dia, mes, ano);
        if((valor > 3000) && (temp > 3000)){
            printf("\nLIMITE MÁXIMO DE TRANSFERÊNCIA DIÁRIO ATINGIDO\n");
            return;
        }
        printf("\nDIGITE DE QUAL AGÊNCIA PRETENDE FAZER A TRANSAÇÃO:\n");
        scanf("%d", &cod_ag);
        temp2 = verifica_agencia_existe(*l, cod_ag);
        if(temp2 == 1){
            //saqua
            temp1 = p->total;
            while(p != NULL){
                if(p->numero_conta==n_conta1){
                    temp-=valor;
                    if(temp1<0){
                        printf("\nSALDO E LIMITE ESTOURADO!!\n");
                        return;
                    }else{
                        (p->saldo)-= valor;
                        (p->total)-= valor;
                    }
                }
                p = p->prox;
            }
            p = *CO;
            //deposita
            while(p != NULL){
                if(p->numero_conta==n_conta2){
                    (p->saldo)+= valor;
                    (p->total)+= valor;
                    return;
                }
                p = p->prox;
            }
            Transacoes_insere(TR, n_transacao,n_conta1,cod_ag,valor,dia,mes,ano,3);
        }else{
            printf("\nESTA AGÊNCIA NÃO EXISTE\n");
            return;
        }
    }else{
        printf("\nCONTA PARA EFETUAR TRANSAÇÃO NÃO EXISTE!!\n");
    }
}

float soma_pagamentos_em_uma_data(Transacoes** TR,int n_conta, int dia, int mes, int ano)
{
    float soma=0;
    Transacoes* p = *TR;
    while(p!=NULL){
        if((p->dia=dia)&&(p->mes=mes)&&(p->ano=ano)&&(p->numero_conta_tran==n_conta)){
            soma+=p->valor;
        }
        p=p->prox;
    }
    return soma;
}

int saque_na_conta_pelo_pagamento(Contas** inicio,int n_conta,float valor)
{
    Contas* p = *inicio;
    float temp = p->total;
    if(p == NULL){
        printf("lista vazia\n");
        return 0;
    }
    while(p != NULL){
        if(p->codigo_agencia_conta==n_conta){
            temp-=valor;
            if(temp<0){
                printf("\nSALDO E LIMITE ESTOURADO!!\n");
                return 1;
            }else{
                (p->saldo)-= valor;
                (p->total)-= valor;
                printf("\nSAQUE EFETUADO COM SUCESSO!!\n");
            }
            return 0;
        }
        p = p->prox;
    }
    printf("\n\nDEPOSITO FEITO!! \n");
    printf("\n");
    return 0;
}

void transacao_pagamento(Agencia** l, Contas** CO, Transacoes** TR)
{/// transação pagamentos codigo ************** 4 ************
    float total_pagamentos_neste_dia,valor;
    int n_conta,cod_ag, n_transacao;
    int temp,temp1, temp2, temp3;
    int dia, mes, ano;
    printf("\nDIGITE O NUMERO TRANSAÇÃO:\n");
    scanf("%d", &n_transacao);
    Transacoes* p = *TR;
    while(p!=NULL){
        if(p->codigo_transacao == n_transacao){
            temp1= 1;
        }
        p=p->prox;
    }
    p = *TR;
    if(temp1==1){
        printf("\nJá existe esta operação\n");
        return;
    }
    printf("\nDIGITE O NUMERO DA CONTA PARA EFETUAR PAGAMENTOE:\n");
    scanf("%d", &n_conta);
    printf("\nDIGITE O NUMERO DE QUAL AGÊNCIA QUER EFETUAR PAGAMENTO:\n");
    scanf("%d", &cod_ag);
    temp = verifica_agencia_existe(*l, cod_ag);
    temp2 = verifica_se_codigo_conta_ja_existe(*CO, n_conta);
    if((temp == 1)&&(temp2 == 1)){
        printf("\nDIGITE O VALOR QUE DESEJA EFETUAR PAGAMENTO:\n");
        scanf("%f", &valor);
        if(valor<0){
            printf("\nVALORES NEGATIVOS NÃO SÃO PERMITIDOS!!\n");
            return;
        }
        printf("\nDIGITE O DIA DO PAGAMENTO:\n");
        scanf("%d", &dia);
        printf("\nDIGITE O MES DO PAGAMENTO:\n");
        scanf("%d", &mes);
        printf("\nDIGITE O ANO DO PAGAMENTO:\n");
        scanf("%d", &ano);
        total_pagamentos_neste_dia = soma_pagamentos_em_uma_data(TR,n_conta, dia, mes, ano);
        if((valor <= 5000) && (total_pagamentos_neste_dia <=5000)){
            temp3 = saque_na_conta_pelo_pagamento(CO,n_conta,valor);
            if(temp3 == 1){
                printf("temp3 não passou no pagamento");
                return;
            }
            Transacoes_insere(TR, n_transacao,n_conta,cod_ag,valor,dia,mes,ano, 4);
        }else{
            printf("\nPAGAMENTO ACIMA DO LIMITE DE R$5000,00 DIÁRIO");
        }
    }else{
        printf("\nESTA CONTA E/OU AGÊNCIA NÃO EXISTE!!!\n");
    }
}

void deposita_na_conta(Contas* inicio,int n_conta,float valor_dep)
{
    Contas* p = inicio;

    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->codigo_agencia_conta==n_conta){
            (p->saldo)+= valor_dep;
            (p->total)+= valor_dep;
            return;
        }
        p = p->prox;
    }
    printf("\n\nDEPOSITO FEITO!! \n");
    printf("\n");
}

void transacao_deposito(Agencia** l,Contas** CO, Transacoes** TR)
{/// transação deposito codigo ************** 5 ************
    int temp, temp2, n_conta,codigo_transacao,dia,mes,ano, cod_ag;
    float valor_dep;
    printf("\nDIGITE O NÚMERO DA TRANSACÃO:\n");
    scanf("%d", &codigo_transacao);
    Transacoes* p = *TR;
    while(p!=NULL){
        if(p->codigo_transacao == codigo_transacao){
            temp= 1;
        }
        p=p->prox;
    }
    p = *TR;
    if(temp==1){
        printf("\nNÚMERO DE TRANSACAO JA EXISTE!!\n");
        return;
    }
    printf("\nDIGITE O NÚMERO DA CONTA QUE DESEJA DEPOSITAR:\n");
    scanf("%d", &n_conta);
    if(temp==1){
        printf("\nDIGITE O VALOR QUE DESEJA DEPOSITAR:\n");
        scanf("%f", &valor_dep);
        if(valor_dep<0){
            printf("\nVALOR MENOR QUE '0' NÃO PERMITIDO!!\n");
            return;
        }
        printf("\nDIGITE APARTIR DE QUAL AGÊNCIA QUER FAZER O DEPOSITO\n");
        scanf("%d", &cod_ag);
        temp2 = verifica_agencia_existe(*l, cod_ag);
        if(temp2 == 0){
            printf("\nESTA AGÊNCIA NÃO EXISTE\n");
            return;
        }
        printf("\nDIGITE O DIA DO DEPOSITO\n");
        scanf("%d", &dia);
        printf("\nDIGITE O MÊS DO DEPOSITO\n");
        scanf("%d", &mes);
        printf("\nDIGITE O ANO DO DEPOSITO\n");
        scanf("%d", &ano);
        Transacoes_insere(TR,codigo_transacao,n_conta,cod_ag,valor_dep, dia, mes, ano , 5);
        deposita_na_conta(*CO, n_conta, valor_dep);
    }else{
        printf("\nCONTA INEXISTENTE!!\n");
    }
}

void fazer_uma_transacao(Agencia** l,Contas** CO, Transacoes** TR)
{
    int opcao;
	do{
		imprime_tipos_transacoes();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///verificar saldo
				transacao_saldo(*CO);
				break;
			case 2:///efetuar saque limite diario 1000
				transacao_saque(l,CO,TR);
				break;
			case 3:///efetuar transferencia limite diario 3000
				transacao_transferencia(l,CO,TR);
				break;
			case 4:///efetuar pagamento limite diario 5000
			    transacao_pagamento(l,CO,TR);
				break;
            case 5:///efetuar deposito
                transacao_deposito(l,CO,TR);
                break;
            case 6:///sair
                break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=6);
}

void excluir_transacao(Transacoes** TR)
{
    int opcao;
    int cod_transacoes;
	do{
		imprime_menu_transacao_excluir();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///EXCLUIR UMA TRANSAÇÃO.
			    printf("\nDIGITE O CODIGO DA TRANSAÇÃO QUE DESEJA APAGAR:\n");
			    scanf("%d", &cod_transacoes);
				excluir_uma_transacoes(TR, cod_transacoes);
				break;
			case 2:///EXCLUIR TODAS TRANSAÇÕES.
			    excluir_todas_transacoes(TR);
				break;
            case 3:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=3);
}

void menu_listar_transacao_de_um_cliente(Transacoes* TR)
{
    int opcao;
	do{
		imprime_menu_transacao_listar_cliente();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				listar_transacao_de_um_cliente_por_periodo(TR);
				break;
			case 2:
				listar_transacoes_de_um_cliente_feita_numa_agencia(TR);
				break;
			case 3:
				listar_todas_transacoes_do_cliente(TR);
				break;
			case 4:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=4);
}

void menu_listar_transacoes_de_uma_agencia(Transacoes* TR)
{
    int opcao;
	do{
		imprime_menu_transacao_listar_agencia();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				listar_transacao_de_uma_agencia_por_periodo(TR);
				break;
			case 2:
				listar_todas_transacoes_da_agencia(TR);
				break;
			case 3:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=3);
}

void listar_transacao(Transacoes* TR)
{
    int opcao;
	do{
		imprime_menu_transacao_listar();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///incluir transação
				menu_listar_transacao_de_um_cliente(TR);
				break;
			case 2:///excluir transação
				menu_listar_transacoes_de_uma_agencia(TR);
				break;
			case 3:///listas todas as transações
				listar_todas_transacao(TR);
				break;
			case 4:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=4);
}

void menu_transacoes(Agencia** l, Clientes** c, Contas** CO, Transacoes** TR)
{
    int opcao;
	do{
		imprime_menu_transacao();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///incluir transação
				fazer_uma_transacao(l, CO, TR);
				break;
			case 2:///excluir transação
				excluir_transacao(TR);
				break;
			case 3:///listas todas as transações
				listar_transacao(*TR);
				break;
			case 4:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=4);
}

void transacao_saldo(Contas* inicio)
{
    int n_conta;
    printf("\nDIGITE O NÚMERO DA CONTA PARA VER SALDO:\n");
    scanf("%d", &n_conta);
    Contas* p = inicio;
    printf("\n\nO SALDO DA CONTA É: \n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->numero_conta == n_conta){
            printf("----------------------------------------------------------------------");
            printf("\nCÓDIGO DA CONTA: %d\nCÓDIGO DA AGÊNCIA DA CONTA: %d\nCPF DO DONO DA CONTA: %d\n", p->numero_conta,p->codigo_agencia_conta, p->cpf_cliente_conta);
            printf("\nDATA DE CRIAÇÃO DA CONTA: %d / %d / %d\n", p->dia, p->mes, p->ano);
            printf("\nSALDO DA CONTA: %f  LIMITE DA CONTA: %f\n", p->saldo, p->limite);
            printf("----------------------------------------------------------------------");
            printf("\n");
        }
        p = p->prox;
    }
    printf("\n");
}





