void inserir()
{
    int sair = 0;
    int tipo = 0;
    int opcao;
    char* idnovo;
    int tcheg, texc;
    printf("\nDIGITE O ID DO PROCESSO:\n");
    idnovo = le_frases();
    printf("\nDIGITE O TEMPO DE CHEGADA:\n");
    scanf("%d", &tcheg);
    printf("\nDIGITE O TEMPO DE EXECUÇÃO:\n");
    scanf("%d", &texc);
    printf("\nESCOLHA O TIPO DE EXECUÇÃO:\n");
    printf("\n 1 - SISTEMA\n 2 - USUÁRIO\N");
    scanf("%d", &opcao);
    do{
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
                printf("\nTIPO NÃO PERMITIDO!\n");
        }
    }while(sair!=1);
    inserir();
}

void imprime_fila_execucao()
{

}

void imprime_pilha_auxiliar()
{

}

