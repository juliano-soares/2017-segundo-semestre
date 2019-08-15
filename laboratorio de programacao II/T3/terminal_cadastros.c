#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "terminal_cadastro.h"

///cadastra

///***************cadastra um agencia****************///
void cadastrar_agencias(Agencia** l)
{
    int tem=1;///verifica se ja possui uma agencia com o mesmo nome
    int codigo_AGnovo;
    char* nome_AGnovo;
    char* end_AGnovo;
    char* geren_AGnovo;
    printf("Digite o codigo da nova agencia:\n");
    scanf("%d", &codigo_AGnovo);
    printf("Digite o nome da nova agencia:\n");
    nome_AGnovo = le_frases();
    tem = cadastro_nome_agencia_verif(*l, nome_AGnovo);
    if(tem == 0){
        printf("Digite o endereço:\n");
        end_AGnovo = le_frases();
        printf("Digite o nome do gerente:\n");
        geren_AGnovo = le_frases();
        Agencia_insere(l, nome_AGnovo, end_AGnovo, geren_AGnovo, codigo_AGnovo);
        printf("Cadastrado com sucesso!!!\n");
    }else{
        printf("ja possui esta agencia\n");
    }
}
///***************cadastra um clientes***************///
void cadastrar_clientes(Clientes** c, Agencia** l)
{
    int temp=1;///verifica se ja possui um cliente na mesma agencia agencia com o mesmo cpf;
    int temp1=0;///verifica se existe agencia para cadastrar cliente
    int cpf_NV;
    int codigo_agencia_NV;
    char* nome_cliente_NV;
    char* telefone_NV;
    printf("Digite o CPF do novo cliente:\n");
    scanf("%d", &cpf_NV);
    printf("Digite o nome do cliente:\n");
    nome_cliente_NV = le_frases();
    printf("Digite o telefone do cliente:\n");
    telefone_NV = le_frases();
    printf("Digite em qual agencia deseja cadastrar o novo cliente:\n");
    scanf("%d", &codigo_agencia_NV);
    temp = verifica_cpf_nesta_agencia(*c, cpf_NV, codigo_agencia_NV);
    temp1 = verifica_agencia_existe(*l, codigo_agencia_NV);
    if(temp == 0){
        if(temp1==1){
            Clientes_insere(c, nome_cliente_NV, telefone_NV, codigo_agencia_NV, cpf_NV);
            printf("Cadastrado com sucesso!!!\n");
        }
        else{
            printf("Agencia inexistente para cadastrar cliente!!!\n");
        }
    }
    else{
        printf("Ja existe uma conta deste cliente nesta agencia...\n");
    }
}
///***************cadastra um gerentes***************///
void  cadastrar_gerente(Gerente** g, Agencia** l)
{//********************verificar se ja existe um gerente com esses dados e não cadastrar outro
    int temp1=0;
    int temp=0;
    int cpf_nv;
    char* nome_nv;
    char* telefone_nv;
    int codigo_agencia_nv;
    printf("Digite o Código da agencia para cadastrar um gerente:\n");
    scanf("%d", &codigo_agencia_nv);
    printf("Digite o CPF do gerente:\n");
    scanf("%d", &cpf_nv);
    printf("Digite o nome do gerente:\n");
    nome_nv = le_frases();
    printf("Digite o telefone do gerente:\n");
    telefone_nv = le_frases();
    temp1 = verifica_agencia_existe(*l, codigo_agencia_nv);
    if(temp1==1){
        temp=verifica_agencia_gerente_igual(*l, nome_nv, codigo_agencia_nv);
        if(temp==1){
            printf("UMA VERIFICAÇÃO DE DADOS FOI EFETUADA\nOK OS DADOS BATEM INSERINDO GERENTE\n");
            Gerente_insere(g, nome_nv, telefone_nv, codigo_agencia_nv,cpf_nv);
            printf("Cadastro feito com sucesso\n");
        }else{
            printf("O nome do gerente com esta agencia não bate.\n");
            printf("Você deve inserir o mesmo nome cadastra no registro da agência.\n");
            printf("Ou editar a agência para inserir este novo gerente a ela.\n");
        }
    }else{
        printf("Agencia inexistente para cadastrar o gerente!!!\n");
    }
}


///verificaçõesa

///***************verifica se ja tem o nome na agencia****************///
int cadastro_nome_agencia_verif (Agencia* inicio, char* v)
{
   Agencia* p = inicio;
   while(p!=NULL){
       if (strcmp(p->nome, v) == 0)
          return 1; /* retorna "1" se achou o elemento */
       p=p->prox;
   }
   return 0;/* retorna "0" se não achou o elemento */
}
///***************verifica se ja tem o nome do clientes nesta agencia*///
int verifica_cpf_nesta_agencia(Clientes* inicio, int cpf_NV, int codigo_agencia_NV)
{
    Clientes* p = inicio;
    while(p!=NULL){
        if(p->codigo_agencia == codigo_agencia_NV){
            if(p->cpf == cpf_NV){
                return 1;/* retorna "1" se achou o elemento */
            }
        }
        p=p->prox;
    }
    return 0;/* retorna "0" se não achou o elemento */
}
///***************verifica se existe agencia para o cliente novo******///
int verifica_agencia_existe(Agencia* inicio,int codigo_agencia_ver)
{
    Agencia* p = inicio;
    while(p!=NULL){
        if(p->codigo_da_agencia == codigo_agencia_ver)
            return 1;/* retorna "1" se achou o elemento */
        p=p->prox;
    }
    return 0;/* retorna "0" se não achou o elemento */
}
///***************verifica se gerente condiz com agencia************///
int verifica_agencia_gerente_igual(Agencia* inicio, char* nome, int codigo_agencia_ver)
{
    int temp=0;
    Agencia* p = inicio;
    while(p!=NULL){
        if(p->codigo_da_agencia == codigo_agencia_ver){
            temp=strcmp(p->nome_gerente, nome);
            if(temp==0){
                return 1;/*retorna "1" se a agencia e o gerente bate*/
            }
        }
        p=p->prox;
    }
    return 0; /*se não encontrou dados que batem*/
}
///**************verifica se existe este cliente pelo cpf***********///
int verifica_cliente_existe(Clientes* inicio, int cpf_ver)
{
    Clientes* c = inicio;
    while(c!=NULL){
        if(c->cpf == cpf_ver){
            return 1;/*retorna "1" se a cpf igual e retorna que existe cliente*/
        }
        c=c->prox;
    }
    return 0;/*retorna "0" se nenhum cpf bateu retorna que não existe cliente*/
}
