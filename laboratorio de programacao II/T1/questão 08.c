/*8. Implemente uma função que receba uma string como parâmetro e retorne
como resultado o número de vogais nessa string. Esta função deve obedecer ao
protótipo: int conta_vogais (char* str);*/

/// obs: so é valido para palavras ate 99 caracteres
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

int conta_vogais (char* str) 
{
	int i, cont=0;
	for (i = 0; i<strlen(str); ++i) {
		if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
			cont++;
		}
	}
	return cont;
}

int main()
{
	char string[100];
	int num;
	printf("digite a palavra de deseja ver o numero de vogais:\n");
	gets(string);
	num = conta_vogais(string);
	printf("O numero de vogais é: %d", num);
	return 0;
}
