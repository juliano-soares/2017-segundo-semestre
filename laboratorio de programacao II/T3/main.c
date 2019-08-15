#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "imprime_terminal_main.h"
#include "listas.h"
#include "terminal_admBanco.h"


int main()
{
    setlocale(LC_ALL,"");
	///cria as listas
	Agencia* l;
    Agencia_cria(&l);
    Clientes* c;
    Clientes_cria(&c);
    Gerente* g;
    Gerente_cria(&g);
    Contas* CO;
    Contas_cria(&CO);
    Transacoes* TR;
    Transacoes_cria(&TR);
    ///**************
	int opcao;
	do{
		imprime_nome_do_banco();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:///terminaladam
                    terminal_admBanco(l, c, g, CO, TR);
				break;
			case 2:///sair
				break;
			default:
				printf("valor invalido\n");
		}
	}while(opcao!=2);
	/*
        lembrar de destruir todas listas
    */
	return 0;
}
