/*3. Implemente uma função que retorne o n-ésimo termo da série da Fibonacci. A série de
Fibonacci é dada por: 1 1 2 3 5 8 13 21..., isto é, os dois primeiros termos são iguais a 1 e cada
termo seguinte é a soma dos dois termos anteriores. Esta função deve obedecer ao protótipo:
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
	printf("Digite o número que deseja encontrar seu correspondente na série de fibonacci:\n");
	scanf("%d", &numero);
	printf("%d\n", fibonacci(numero));
	return 0;
}
