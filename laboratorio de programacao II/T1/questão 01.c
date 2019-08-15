/*1. Implemente uma fun��o que indique se um ponto (x,y) est� localizado dentro ou fora de um
ret�ngulo. O ret�ngulo � definido por seus v�rtices inferior esquerdo (x0, y0) e superior direito
(x1, y1). A fun��o deve ter como valor de retorno 1, se o ponto estiver dentro do ret�ngulo, e 0
caso contr�rio, obedecendo ao prot�tipo: int dentro_ret (int x0, int y0, int x1, int y1, int x, int y);*/

#include<stdio.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)
{
    if(x >= x0 && x<=x1 && y >= y0 && y <= y1){
        return  1;
    }
    return 0;
}

int main()
{
    int x0, y0, x1, y1, x, y, a;
    printf("Digite o v�rtice inferior esquerdo (x0, y0) do retangulo");
    scanf("%d %d", &x0,&y0);
    printf("Digite o v�rtice superior direito (x1, y1) do retangulo");
    scanf("%d %d", &x1,&y1);
    printf("Digite a coordenada que deseja verificar se esta no retangulo:");
    scanf("%d %d", &x,&y);
    a = dentro_ret(x0, y0, x1, y1, x, y);
    if(a==1){
        printf("A coordenada esta no retangulo");
    } else {
        printf("A coordenada n�o esta no retangulo");
    }
    return 0;
}
