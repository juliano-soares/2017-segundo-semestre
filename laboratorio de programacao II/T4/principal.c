#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pilha.h"
#include "fila.h"

int tp;

void imprime_as_execucoes(Pilha* p, Fila* f)
{
    printf("\n\nFILA DE EXECUCAO \n");
    imprime_fila(f);
    printf("\nPILHA DE EXECUCAO\n");
    imprime(p);
}

Pilha * invertePilha(Pilha * p){
    Pilha * pilha_inv = pilha_cria();
    No* q = p->prim;
    while (q!=NULL) {
        No* t = q->prox;
        pilha_push(pilha_inv ,q->id, q->tipo, q->t_chegada, q->t_exec);
        q = t;
    }
    return pilha_inv;
}

void modifica_fila(Fila* f)
{
    int idt;
    int tipot;
    int tc;
    int te;
    NoF* q;
    Pilha* p = pilha_cria();
    ponto:
    q = f->ini;
    if(q->tipo != 1){ /* se não for tipo um o primeiro da fila*/
        /*armazena dados*/
        idt = q->id;
        tipot = q->tipo;
        tc = q->t_chegada;
        te = q->t_exec;
        /*insere na pilha*/
        pilha_push(p ,idt, tipot, tc, te);
        /*retira da fila*/
        fila_retira(f);
        /*faz nova verificação*/
        goto ponto;
    }
    printf("\n\nmovido para a pilha!!");
    imprime_as_execucoes(p, f);
    /*inverte a pilha*/
    Pilha * p2 = invertePilha(p);
    while(p2->prim != NULL){
        No* q = p2->prim;/*insere denovo na fila*/
        fila_insere(f, q->id, q->t_chegada, q->t_exec, q->tipo);
        pilha_pop(p2);
    }
    printf("\n\ninseriu na fila mas continua  na pilha e apos remove!!");
    imprime_as_execucoes(p, f);
    pilha_libera(p);/*libera a pilha de auxilia*/
    pilha_libera(p2);
}

void imprime_as_execucoes_fila(Fila* f)
{
    printf("\n\nFILA DE EXECUCAO \n");
    imprime_fila(f);
}

void executando_os_processos(Fila* f)
{
    int aux = 0;
    int aux2 = 0;
    printf("\n=====================================\n");
    printf("         FILA DE EXECUCAO INSERIDA\n");
    imprime_fila(f);
    printf("\n=====================================\n");
    do{
        aux2 = verifica_se_existe_exc_sistema(f);
        if((f->ini->tipo != 1) && (aux2 == 1)){
            modifica_fila(f);
        }
        aux = processa_comando_somente_primeiro_fila(f, tp);
        if(aux == 1){
            NoF* q = f->ini;
            q->t_exec-=tp;
            fila_insere(f, q->id, q->t_chegada, q->t_exec, q->tipo);
            printf("\nexecutado um ciclo em P%d\n", q->id);
            fila_retira(f);
        }if(aux == 0){
            printf("\nfinalizado P%d\n", f->ini->id);
            fila_retira(f);
        }
        imprime_as_execucoes_fila(f);
    }while(f->ini != NULL);
    printf("\n \n");
}

int inserir(Fila *f, int idn)
{
    int sair = 0;
    int tipo = 0;
    int opcao;
    int tcheg, texc;
    printf("\nDIGITE O TEMPO DE CHEGADA:\n");
    scanf("%d", &tcheg);
    printf("\nDIGITE O TEMPO DE EXECUCAO:\n");
    scanf("%d", &texc);
    printf("\nESCOLHA O TIPO DE EXECUCAO:\n");
    printf("\n1 - SISTEMA\n2 - USUARIO\n");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            tipo = 1;
            sair = 1;
            break;
        case 2:
            tipo = 2;
            sair = 1;
            break;
        default:
            printf("\nTIPO NAO PERMITIDO!\n");
    }
    if(sair == 1){
        fila_insere(f, idn, tcheg, texc, tipo);
    }
    return sair;
}

void menu_principal()
{
    int i, np, ok;
    int idnovo = 1;
    Fila* f = fila_cria();
    printf("MENU DE PROCESSOS:\n");
    printf("DIGITE O TEMPO DE CADA PROCESSO DO PROCESSADOR:\n");
    scanf("%d", &tp);
    printf("=====================================\n");
    printf("TP = %d\n", tp);
    printf("=====================================\n");
    printf("QUANTOS PROCESSOS DESEJA INSERIR:\n");
    scanf("%d", &np);
    for(i = 0; i<np; i++){
        printf("\nPROCESSO DE NUMERO %d:\n", i+1);
        ok = inserir(f, idnovo);
        if(ok != 1){
            printf("\nVOCE DIGITOU UM DADO INCORRETO CAUSANDO O ENCERRAMENTO DO PROGRAMA!!!!\n");
            return;
        }
        idnovo+=1;
    }
    printf("=====================================\n");
    printf("  INICIANDO O PROCESSOS EM EXECUCAO\n");
    printf("=====================================\n");
    executando_os_processos(f);
    printf("\nFILA DE PROCESSOS TERMINOU!!!\n");
}


