/*2. Implemente uma função para testar se um número inteiro
é primo ou não. Esta função deve obedecer ao protótipo
a seguir e ter como valor de retorno 1 se n for primo e 0
caso contrário: int primo (int n);*/

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
    printf("Digite o numero que deseja verificar se é primo ou não:\n");
    scanf("%d", &numero);
    confirmacao=primo(numero);
    if(confirmacao==0){
        printf("é um numero primo\n");
    }else{
        printf("nao é um numero primo\n");
    }
    return 0;
}
