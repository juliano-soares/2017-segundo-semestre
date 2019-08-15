/*9. Implemente uma função que receba uma string como parâmetro e altere
nela as ocorrências de caracteres maiúsculos para minúsculos. Esta função
deve obedecer ao protótipo: void minúsculo (char* str);*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

void minusculo (char* str)
{
	int i;
	for (i = 0; i<strlen(str); ++i) {
		if (str[i]>=65 && str[i]<= 90){
			str[i]+=32;
		}
	}
}

int main()
{
    char string[50];
    printf("Digite a palavra que deseja passar todos os caracteres para minúsculo:\n");
    gets(string);
    minusculo (string);
    printf("A palavra em minúsculo é: %s\n", string);
    return 0;
}
