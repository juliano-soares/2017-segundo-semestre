/*9. Implemente uma fun��o que receba uma string como par�metro e altere
nela as ocorr�ncias de caracteres mai�sculos para min�sculos. Esta fun��o
deve obedecer ao prot�tipo: void min�sculo (char* str);*/

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
    printf("Digite a palavra que deseja passar todos os caracteres para min�sculo:\n");
    gets(string);
    minusculo (string);
    printf("A palavra em min�sculo �: %s\n", string);
    return 0;
}
