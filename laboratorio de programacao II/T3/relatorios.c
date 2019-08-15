#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "relatorios.h"


///R1: listar o nome dos clientes e o nome da agência em que estes possuem conta
void listar_clientes_agencia_possuem_conta(Agencia* inicio, Clientes* c)
{
    Agencia* p = inicio;
    Clientes* cl = c;
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR1: listar o nome dos clientes e o nome da agência em que estes possuem conta\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(cl!= NULL){
        printf("----------------------------------------------------------------------");
        printf("\nNOME DO CLIENTE: %s\n", cl->nome);
        while(p !=NULL){
            if(cl->codigo_agencia == p->codigo_da_agencia){
                printf("\nNOME DA AGÊNCIA: %s\n", p->nome);
            }
            p = p->prox;
        }
        p = inicio;
        printf("----------------------------------------------------------------------");
        printf("\n");
        cl= cl->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R2: listar as agências que ainda não possuem nenhuma conta aberta
void listar_agencias_que_nao_possue_conta(Agencia* l, Contas* CO)
{
    Contas* p = CO;
    Agencia* a = l;
    int cont=0;
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR2: listar as agências que ainda não possuem nenhuma conta aberta\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(a != NULL){
        while(p !=  NULL){
            if(p->codigo_agencia_conta == a->codigo_da_agencia){
                cont++;
            }
            p = p->prox;
        }
        p = CO;
        if(cont ==  0){
            printf("\nCÓDIGO DA AGÊNCIA: %d NOME DA AGÊNCIA: %s\n", a->codigo_da_agencia , a->nome);
        }
        a = a->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R3: listar todos os saques efetuados em certo mês informado pelo usuário
void listar_saques_efetuados_em_certo_mes(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int mes;
    printf("\nDIGITE O MES PARA VER OS SAQUE EFETUADOS NELE:\n");
    scanf("%d", &mes);
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR3: listar todos os saques efetuados em certo mês\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if((p->mes==mes)&&(p->tipo_transacao==2)){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d \n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R4: listar o saldo das contas que não estão no negativo
void listar_saldo_que_estao_negativo(Contas* inicio)
{
    Contas* p = inicio;
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR4: listar o saldo das contas que não estão no negativo\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->saldo>0){
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
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R5: listar todas as contas de certo cliente informado pelo usuário
void listar_contas_de_certo_cliente(Contas* inicio)
{
    Contas* p = inicio;
    int cpf_ver;
    printf("\nDIGITE O CPF DO CLIENTE QUE DESEJA VER AS CONTAS:\n");
    scanf("%d", &cpf_ver);
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR5: listar todas as contas de certo cliente\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->cpf_cliente_conta == cpf_ver){
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
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R6: listar todas as transferências bancárias efetuadas numa certa agência informada pelo usuário
void listar_transferencias_efetuadas_em_uma_agencia(Transacoes* inicio)
{//*****************************************************************************************************************************
    Transacoes* p = inicio;
    int cod_ag;
    printf("\nDIGITE O CÓDIGO DA AGÊNCIA:\n");
    scanf("%d", &cod_ag);
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR6: listar todas as transferências bancárias efetuadas numa certa agência\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if((p->codigo_agencia_da_trans==cod_ag)&&(p->tipo_transacao==3)){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d | %d | %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R7: listar todas as transações bancárias realizadas por certo cliente informado pelo usuário
void listar_transacoes_realizada_por_cliente(Transacoes* inicio)
{
    Transacoes* p = inicio;
    int cod;
    printf("\nDIGITE O CÓDIGO DA CONTA DO CLIENTE:\n");
    scanf("%d", &cod);
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR7: listar todas as transações bancárias realizadas por certo cliente\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->numero_conta_tran==cod){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d\n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R8: listar todos os pagamentos realizados
void listar_pagamentos_realizados(Transacoes* inicio)
{
    Transacoes* p = inicio;
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR8: listar todos os pagamentos realizados\n");
    if(p == NULL)
        printf("lista vazia\n");
    while(p != NULL){
        if(p->tipo_transacao==4){
            printf("\n----------------------------------------------------------\n");
            printf("\nTIPO DE TRANSAÇÃO: %d \n(2 = SAQUE | 3 = TRANSFERÊNCIA | 4 = PAGAMENTO | 5 = DEPOSITO)\n", p->tipo_transacao);
            printf("\nCÓDIGO DA TRANSAÇÃO: %d\n", p->codigo_transacao);
            printf("\nCÓDIGO DA AGÊNCIA AONDE FOI EFETUADA A TRANSAÇÃO: %d\n",p->codigo_agencia_da_trans);
            printf("\nNÚMERO DA CONTA DA TRANSAÇÃO: %d\n", p->numero_conta_tran);
            printf("\nDATA DA TRANSAÇÃO: %d / %d / %d \n", p->dia, p->mes, p->ano);
            printf("\nVALOR DA TRANSACÃO: R$ %f", p->valor);
            printf("\n----------------------------------------------------------\n");
        }
        p = p->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R9: listar o nome dos clientes que não realizaram nenhuma transação bancária.
void listar_clientes_nao_realizaram_transacao(Clientes* cl, Transacoes* TR, Contas* CO)
{//*******************************************************************************************************************
    Transacoes* p = TR;
    Clientes* a = cl;
    Contas* c = CO;
    int cont=0;
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR9: listar o nome dos clientes que não realizaram nenhuma transação bancária.\n");
    if(p == NULL)
        printf("não tem transações realizadas\n");
    while(a != NULL){
        while(c !=  NULL){
            if(c->cpf_cliente_conta == a->cpf){
                while(p !=  NULL){
                    if(p->numero_conta_tran == c->numero_conta){
                        cont++;
                    }
                    p = p->prox;
                }
                p = TR;
            }
            c = c->prox;
        }
        c = CO;
        if(cont ==  0){
            printf("\nCPF DO CLIENTE: %d NOME DO CLIENTE: %s\n", a->cpf , a->nome);
        }
        a = a->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");
}

///R10: listar o nome dos clientes que têm o maior saldo em conta em cada agência.
void listar_cliente_maior_saldo_cada_agencia(Agencia* l, Clientes* c, Contas* CO)
{//*****************************************************************************************************************

    Agencia* a = l;
    Clientes* cl = c;
    Contas* co = CO;
    Clientes* pont = c;
    float valor=0, temp_valor=0;
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printf("\nR10: listar o nome dos clientes que têm o maior saldo em conta em cada agência.\n");
    while(a != NULL){
        while(cl !=  NULL){
            if(a->codigo_da_agencia == c->codigo_agencia){
                while(co != NULL){
                    if(co->cpf_cliente_conta == c->cpf){
                        valor  = co->saldo;
                        if(valor > temp_valor){
                            temp_valor = valor;
                            pont = cl;
                        }
                    }
                    co = co->prox;
                }
                co = CO;
            }
            cl = cl->prox;
        }
        cl = c;
        printf("\nAGÊNCIA CÓDIGO: %d AGÊNCIA NOME: %s", a->codigo_da_agencia,a->nome);
        printf("\nCPF DO CLIENTE: %d NOME DO CLIENTE: %s\n", pont->cpf, pont->nome);
        a = a->prox;
    }
    printf("\n");
    printf("\n////////////////////////////////////////////////////////////////////////\n");

}
