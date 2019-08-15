/*7. Implemente uma fun��o que permita a avalia��o de polin�mios. Cada polin�mio � definido por
um vetor que cont�m seus coeficientes. Por exemplo, o polin�mio de grau 2, 3x2
+ 2x + 12, ter�
um vetor de coeficientes igual a v[]={12, 2, 3}. A fun��o deve obedecer ao prot�tipo: double
avalia (double* poli, int grau, double x);
Onde o par�metro poli � o vetor com os coeficientes do polin�mio, grau � o grau do polin�mio,
e x � o valor para o qual o polin�mio deve ser avaliado.*/

#include <stdio.h>
#include <stdlib.h>

double avalia (double* poli, int grau, double x)
{
    int i;
    double temp=0, termox=1;
    for(i=0; i<=grau; i++){
        temp = temp + poli[i] * termox;
            termox = termox *x;
    }
    return temp;
}

int main()
{
    double *v;
    int grau, i;
    double x, resp;
    printf("Digite o grau do polinomio:\n");
    scanf("%d", &grau);
    if(grau>0){
		v = (double *) malloc(grau * sizeof(double));
    	printf("Digite os seus coeficientes comessando pelo de menor grau:\n");
    	for(i=0; i<=grau; i++){
        	scanf("%lf", &v[i]);
    	}
    	printf("Digite o valor de X:\n");
    	scanf("%lf", &x);
    	resp = avalia (v, grau, x);
    	printf("A resposta �: %lf\n", resp);
    	free(v);
	}else {
		printf("Grau menor ou igual a 0 n�o permitido!\n");
	}
    return 0;
}
