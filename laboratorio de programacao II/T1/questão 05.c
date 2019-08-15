/*5. Implemente uma fun��o que receba como par�metro um vetor de n�meros
reais (vet) de tamanho n e retorne quantos n�meros negativos est�o armazenados
neste vetor. Esta fun��o deve obedecer ao prot�tipo: int negativos (int n, float* vet);*/

#include<stdio.h>

int negativos (int n, float* vet)
{
    int i, cont=0;
    for(i=0; i<n; i++){
        if(vet[i]<0){
            cont++;
        }
    }
    return cont;
}

int main()
{
    int n, i, quant;
    printf("Digite a quantidade de n�meros que deseja inserir:\n");
    scanf("%d", &n);
    float vetor[n];
    printf("Digite os n�meros a inserir:\n");
    for(i=0; i<n; i++){
        scanf("%f", &vetor[i]);
    }
    quant = negativos(n, vetor);
    printf("A quantidade de negativos � %d\n", quant);
    return 0;
}
