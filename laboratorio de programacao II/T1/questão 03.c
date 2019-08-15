/*3. Implemente uma fun��o que retorne o n-�simo termo da s�rie da Fibonacci. A s�rie de
Fibonacci � dada por: 1 1 2 3 5 8 13 21..., isto �, os dois primeiros termos s�o iguais a 1 e cada
termo seguinte � a soma dos dois termos anteriores. Esta fun��o deve obedecer ao prot�tipo:
int fibonacci (int n);*/

///obs: Valores muito altos passa o tamanho de uma variavel int

#include <stdio.h>
                                         
int fibonacci(int n)
{
   if(n == 1 || n == 2)
       return 1;
   else
       return fibonacci(n - 1) + fibonacci(n - 2); 
} 

int main(void)
{
	int numero;
	printf("Digite o n�mero que deseja encontrar seu correspondente na s�rie de fibonacci:\n");
	scanf("%d", &numero);
	printf("%d\n", fibonacci(numero));
	return 0;
}
