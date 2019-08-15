/*4. Implemente uma função que retorne a soma dos n primeiros números naturais ímpares.
Esta função deve obedecer ao protótipo: int soma_impares (int n); */

#include <stdio.h>
int soma_impares (int n)
{
    int i, soma=0, a=1;
    for(i=0; i<n; i++){
        soma = soma + a;
        a = a + 2;
    }
    return soma;
}

int main()
{
    int quant;
    printf("Digite a quantidade de números impares que deseja somar:\n");
    scanf("%d", &quant);
    printf("%d", soma_impares(quant));
    return 0;
}
