/*6. Implemente uma função que receba como parâmetro um vetor de números
inteiros (vet) de tamanho n e inverta a ordem dos elementos armazenados neste
vetor. Esta função deve obedecer ao protótipo: void inverte (int n, int* vet);*/

#include <stdio.h>

void inverte (int n, int* vet)
{
    int i, aux;
    for(i=0; i<n/2; i++){
        aux = vet[i];
        vet[i] = vet[n-1-i];
        vet[n-1-i] = aux;
    }
    return;
}

int main()
{
	int i, quant;
    printf("Digite a quantidade de números que deseja inserir:\n");
    scanf("%d", &quant);
    int vet[quant];
    for(i=0; i<quant; i++){
    	scanf("%d", &vet[i]);
	}
    inverte (quant, vet);
    printf("Os números invertidos é:\n");
    for(i=0; i<quant; i++){
        printf("%d - ", vet[i]);
    }
    return 0;
}
