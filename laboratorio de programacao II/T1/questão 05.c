/*5. Implemente uma função que receba como parâmetro um vetor de números
reais (vet) de tamanho n e retorne quantos números negativos estão armazenados
neste vetor. Esta função deve obedecer ao protótipo: int negativos (int n, float* vet);*/

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
    printf("Digite a quantidade de números que deseja inserir:\n");
    scanf("%d", &n);
    float vetor[n];
    printf("Digite os números a inserir:\n");
    for(i=0; i<n; i++){
        scanf("%f", &vetor[i]);
    }
    quant = negativos(n, vetor);
    printf("A quantidade de negativos é %d\n", quant);
    return 0;
}
