/*7. Implemente uma função que permita a avaliação de polinômios. Cada polinômio é definido por
um vetor que contém seus coeficientes. Por exemplo, o polinômio de grau 2, 3x2
+ 2x + 12, terá
um vetor de coeficientes igual a v[]={12, 2, 3}. A função deve obedecer ao protótipo: double
avalia (double* poli, int grau, double x);
Onde o parâmetro poli é o vetor com os coeficientes do polinômio, grau é o grau do polinômio,
e x é o valor para o qual o polinômio deve ser avaliado.*/

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
    	printf("A resposta é: %lf\n", resp);
    	free(v);
	}else {
		printf("Grau menor ou igual a 0 não permitido!\n");
	}
    return 0;
}
