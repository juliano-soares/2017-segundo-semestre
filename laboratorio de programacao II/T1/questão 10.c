/*10. Implemente uma função que receba uma string como parâmetro e desloque os seus caracteres
uma posição para a direita. Por exemplo, a string “casa” seria alterada para “acas”. Repare que o
último caractere vai para o início da string. Esta função deve obedecer ao protótipo: void
roda_string (char* str).*/

///obs: se palavra maior que 50 caracteres causa erro.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  

char roda_string(char* str)
{
	int a, b;
	char aux[50];
	b=strlen(str)-1;
	for(a=0;str[a]!='\0';a++){
    	aux[b]=str[a]; 
       	b--;      
    }
    aux[a]='\0';
    strcpy(str,aux); 
	
}

int main()
{
    char string[50];
    printf("Digite a frase que pretendes que invertida: ");
    gets(string);
	roda_string(string);
    printf("\n\nA frase inversa e:\n%s\n\n",string);
	return 0;
}
