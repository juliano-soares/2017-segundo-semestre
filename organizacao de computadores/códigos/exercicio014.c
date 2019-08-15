#include <stdio.h>

/* copia a string s1 para a string s2 */
/* o final da string termina com um 0 */
void copiaString(char *s1, char *s2)
{
	char *tmp1;
	char *tmp2;
	tmp1 = s1;
	tmp2 = s2;
	while(*s1 != 0){
		*s2 = *s1;
		s2++;
		s1++;
	}
	*s2 = *s1;
	s1 = tmp1;
	s2 = tmp2;
}

char string1[] = "teste de uma string";
char string2[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    
int main(void)
{ 	
	copiaString(string1, string2);
	// printf("String2: %s\n", string2);
    return 0;
}
