#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "terminal_excluir.h"
#include "funcao_listas.h"
#include "imprime_terminal_excluir.h"

///***************excluir uma agencia***************///
/*FALTA IMPRIMIR TRANSSAÇÕES ANTES DE EXCLUIR*/
void excluir_agencias(Agencia** inicio, Clientes** inicio_c, Gerente** inicio_g, Contas** inicio_CO, Transacoes** inicio_TR)
{
    int codigo_agencia_exc;
    int opcao;
    imprime_excluir_terminal();
    scanf("%d", &codigo_agencia_exc);
    Agencia* temp = Agencia_busca(*inicio, codigo_agencia_exc);
    if(temp!=NULL){
        imprime_confirmacao_excluir();
        printf("Código da agência: %d | Nome da agência: %s | Endereço: %s | Nome gerente: %s", temp->codigo_da_agencia,temp->nome, temp->endereco, temp->nome_gerente);
        printf("\n");
        do{
            digita_sim_nao();
            scanf("%d", &opcao);
            switch(opcao){
                case 1:///ok quero excluir
                    clientes_relacionados_a_agencia();
                    imprime_clientes_de_uma_agencia(*inicio_c, codigo_agencia_exc);
                    imprime_contas_de_uma_agencia(*inicio_CO, codigo_agencia_exc);
                    imprime_transacoes_de_uma_agencia(*inicio_TR, codigo_agencia_exc);
                    do{
                        certeza_que_sim_ou_nao();
                        scanf("%d", &opcao);
                        switch(opcao){
                            case 1:///ok sim realmente quero excluir
                                Agencia_retira (inicio, codigo_agencia_exc);
                                retira_todos_os_clientes_vinculado_agencia(inicio_c, codigo_agencia_exc);
                                retira_gerente_agencia(inicio_g,codigo_agencia_exc);///ERRO NO RETIRAR GERENTER VINCULADOS
                                retira_todas_transacoes_apartir_agencia(inicio_TR, codigo_agencia_exc);///ainda nao implementada
                                retira_todas_contas_apartir_agencia(inicio_CO, codigo_agencia_exc);
                                printf("REMOÇÃO FEITA COM SUCESSO!!!\n");
                                return;
                            case 2:///sair
                                break;
                            default:
                                printf("opção invalida\n");
                        }
                    }while(opcao!=2);
                    break;
                case 2:///sair
                    break;
                default:
                    printf("valor invalido\n");
            }
        }while(opcao!=2);
    }else{
        printf("Não existe esta agência!!!\n");
    }
}

///***************excluir um gerente****************///
void excluir_gerentes(Gerente** inicio)//*********************************erro na chamada retira
{
    /*excluir gerente recebe cpf do gerente
    localiza sua agencia
    remove gerente*/
    int cpf;
    int opcao;
    imprime_excluir_gerente();
    scanf("%d", &cpf);
    Gerente* temp = Gerente_busca(*inicio, cpf);
    if(temp!=NULL){
        ///buscar gerente imprimir
        printf("\n A conta do gerente:\n");
        printf("Código da agência: %d | Cpf: %d | Nome: %s | Telefone: %s\n", temp->codigo_agencia, temp->cpf, temp->nome, temp->telefone);
        do{//PEDE A CONFIRMAÇÃO PARA DELETAR
            imprime_deletar_gerente_confirmacao();
            scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    retira_gerente_da_agencia(inicio, cpf);
                    ///deixa sem cadastrar novo gerente
                    return;
                case 2://sair
                    break;
                default:
                    printf("Opção invalida.\n");
            }
        }while(opcao!=2);
    }else{
        printf("Não existe este gerente!!!\n");
    }
}

///*******excluir um cliente de todas agencias******///
void deletar_cliente_all_agencias(Clientes** inicio_c,Contas** inicio_CO, Transacoes** inicio_TR)//********************erro na chamada retira
{
    int cpf_ver;
    int opcao;
    imprime_deleta_cliente_all_agencia_cpf();
    scanf("%d", &cpf_ver);

    Clientes_busca_imprime_cliente_allcontas(*inicio_c, cpf_ver);//FAZ A BUSCA DO CLIENTE E IMPRIME O MESMO CLIENTE SO QUE EM VÁRIAS AGENCIAS
    ///imprime as CONTAS do cliente
    imprime_deletar_cliente_all_agencia_transacoes();//imprime junto todas as transações do cliente
    ///FUNÇÃO PARA IMPRIMIR CONTAS DO CLIENTE.
    imprime_contas_de_um_cliente(inicio_CO,cpf_ver);
    do{//PEDE A CONFIRMAÇÃO PARA DELETAR
        imprime_deletar_cliente_all_agencia_confirmacao();
        scanf("%d", &opcao);
        switch(opcao){
            case 1://chama retirar o cliente de todas agencias
                retira_todos_cliente(inicio_c, cpf_ver);
                retira_todas_contas(inicio_CO, cpf_ver);
                ///manterei as transações pois é para a administração do banco
                return;
            case 2://sair
                break;
            default:
                printf("Opção invalida.\n");
        }
    }while(opcao!=2);
}

///********excluir um cliente de uma agencias*******///
void deletar_cliente_1agencia(Clientes** inicio_c,Contas** inicio_CO, Transacoes** inicio_TR)//**********************erro na chamada retira
{
    int cpf_ver;
    int codigo_agencia_ver;
    int opcao;
    imprime_deleta_cliente_uma_agencia_cpf();
    scanf("%d", &cpf_ver);
    imprime_deleta_cliente_uma_agencia_codigo();
    scanf("%d", &codigo_agencia_ver);
    ///verifica se cliente existe se não printa não existe e retorna
    Clientes* temp = Clientes_busca_AGespecifica(*inicio_c, cpf_ver, codigo_agencia_ver);
    if(temp!=NULL){
        ///buscar cliente imprimir
        printf("\n A conta do cliente:\n");
        printf("Código da agência: %d | Cpf: %d | Nome: %s | Telefone: %s\n", temp->codigo_agencia, temp->cpf, temp->nome, temp->telefone);
        ///imprimir transações do cliente
        imprime_deletar_cliente_uma_agencia_conta();
        ///chama função ixibir conta do cliente nesta agencia
        imprime_conta_cliente_especifico_agencia_espcifica(inicio_CO, cpf_ver, codigo_agencia_ver);
        do{//PEDE A CONFIRMAÇÃO PARA DELETAR
            imprime_deletar_cliente_uma_agencia_confirmacao();
            scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    retira_cliente_vinculado_agencia(inicio_c, codigo_agencia_ver, cpf_ver);
                    //chama retirar a conta do cliente desta agencia
                    retira_todas_contas_apartir_clientes(inicio_CO, cpf_ver);
                    ///manterei as transações pois é para a administração do banco
                    return;
                case 2://sair
                    break;
                default:
                    printf("Opção invalida.\n");
            }
        }while(opcao!=2);
    }else{
        printf("Não existe este cliente!!!\n");
    }
}

///***************excluir um cliente****************///
void excluir_clientes(Clientes** inicio_c,Contas** inicio_CO, Transacoes** inicio_TR)
{
    int opcao;
    do{
        imprime_deletar_cliente();
        scanf("%d", &opcao);
        switch(opcao){
            case 1://apagar o cliente de todas agencias
                deletar_cliente_all_agencias(inicio_c, inicio_CO, inicio_TR);
                break;
            case 2://apagar o cliente de uma agencia
                deletar_cliente_1agencia(inicio_c, inicio_CO, inicio_TR);
                break;
            case 3://sair
                break;
            default:
                printf("Opção invalida!!!\n");
        }
    }while(opcao!=3);

}


