/*2. Implemente uma fun��o para testar se um n�mero inteiro
� primo ou n�o. Esta fun��o deve obedecer ao prot�tipo
a seguir e ter como valor de retorno 1 se n for primo e 0
caso contr�rio: int primo (int n);*/

#include <stdio.h>

int primo(int n)
{
    int i, cont=0;
    for(i=1; i<=n; i++){
        if(n%i==0){
            cont++;
        }if(cont>=3){
           return 1;
        }
    }
    return 0;
}

int main(void)
{
    int numero, confirmacao;
    printf("Digite o numero que deseja verificar se � primo ou n�o:\n");
    scanf("%d", &numero);
    confirmacao=primo(numero);
    if(confirmacao==0){
        printf("� um numero primo\n");
    }else{
        printf("nao � um numero primo\n");
    }
    return 0;
}
