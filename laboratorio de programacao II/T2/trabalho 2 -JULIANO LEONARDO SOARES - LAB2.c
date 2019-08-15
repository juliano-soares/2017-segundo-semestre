/*
	programa: caça palavras (ou melhor serie de caracteres)
	criado por: JULIANO LEONARDO SOARES;
	turma: laboratório de programação 2;
		o programa consiste em criar uma matriz dinamicamente de caracteres aleatorios e
	mostrar ao usuario podendo assim o usuario fazer uma busca nesta matriz e procurar a
	serie de caracteres que deseja;
	* a busca é feita da seguinte maneira primeiramente ela chama a função de uma 
	direção a ser buscada ex:horizontal direta; e assim essa função procura na matriz
	o primeiro caractere da serie passada pelo usuario achando na matriz a função passa
	a comparar os outros caracteres na direção usada na função ex: da esquerda para direita;
	apos comparar se igual imprime na tela as coordenadas onde começa a serie e onde termina.
	* problemas: 1-como a matriz so gera caracteres em maiusculo as series buscadas devem ser 
				 escritas em maiusculo.
				 2-o sistema pede a quantidade de caracteres que o usuario deseja buscar (se 
				 digitado algo diferente de numeros o programa trava).
			 	 3-se o usuario criar uma matriz muito grande ao imprimir ou fazer as buscas 
				 o programa pode demorar ou não haver espaço suficiente pera alocar a matriz.
				 4-pode ser um problema mas para mim eu quis deixar aparecer todas as aparições 
				 da serie caso ocorrer mais de uma vez na matriz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char **Alocar_matriz (int linha, int coluna)///aloca a matriz na memoria seguindo o n° de linhas e colunas
{
  int   i;    /* variavel auxiliar      */
  if (linha < 1 || coluna < 1) { /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return NULL;
  }
  printf("1");
  char **matrix = (char **) malloc(linha * sizeof(char *)); /* aloca as linhas da matriz */
  if (matrix == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return NULL;
  }
  printf("2");
  for ( i = 0; i < linha; i++ ) { /* aloca as colunas da matriz */
    matrix[i] = (char*) malloc(sizeof(char) * coluna);
    if (matrix[i] == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      return NULL;
    }
  }
  printf("3");
  return matrix; /* retorna o ponteiro para a matriz */
}

char **Liberar_matriz_real (int linha, int coluna, char **matrix)///libera a area da memoria que a matriz esta alocada
{
  int  i;  /* variavel auxiliar */
  if (matrix == NULL) return (NULL);
  if (linha < 1 || coluna < 1) {  /* verifica parametros recebidos */
     printf ("** Erro: Parametro invalido **\n");
     return matrix;
  }
  for (i=0; i<linha; i++) free (matrix[i]); /* libera as linhas da matriz */
  free (matrix);      /* libera a matriz */
  return NULL; /* retorna um ponteiro nulo */
}

void insere_letras_rand(char **matriz, int linhas, int colunas)///insere na matriz as letras
{
    srand(time(NULL));
    int i, j;
    int aux;
    for(i=0; i<linhas; i++){
    	for(j=0; j<colunas; j++){
            aux = (65 + rand() % (91-65));
    		matriz [i][j] = aux;
		}
	}
}

void escreve_matriz(char **matriz, int linhas, int colunas)///desenha a matriz no painel
{
	int i, j;
    for(i=0; i<linhas; i++){
    	for(j=0; j<colunas; j++){
    		printf("%c", matriz[i][j]);
    		if(j<colunas -1){
                printf(" | ");
    		}
		}
		printf("\n");
	}
}

int horizontal_direta(char *palavra,char **matriz, int linha, int coluna) ///(da esquerda para direita)
{
	int i, j, k;
    int encontrada=0, cont=0;
    int coord[4];
    int aux=0;
    int tam=strlen(palavra);
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(palavra[aux] == matriz[i][j]){
                coord[0]=i;//coordenada inicial linha
                coord[1]=j;//coordenada inicial coluna
                coord[2]=i;//coordenada final linha
                coord[3]=j+tam-1;//coordenada final coluna
                for(k=1; palavra[k]!='\0'; k++){
                    if((palavra[k]==matriz[i][k+j])&& (k+j<= coluna)){
                            cont++;
                    }else{
                        break;
                    }
                }if(cont==tam-1){
                    encontrada = 1;

                }if(encontrada==1){
                    printf("Palavra encontrada!!\n");
                    printf("HORIZONTAL DIRETA!!\n");
                    printf("Direcao da esquerda para direita!!\n");
                    printf("comeca na linha: %d coluna: %d\n", coord[0],coord[1]);
                    printf("termina na linha: %d coluna: %d\n\n\n", coord[2],coord[3]);
                    return encontrada;
                }
            }
        }
    }
    return encontrada;
}

int horizontal_reversa(char *palavra,char **matriz, int linha, int coluna) /// (da direita para esquerda)
{
	int i, j=0, k;
    int encontrada=0, cont=0;
    int coord[4];
    int aux=0;
    int tam=strlen(palavra);
    char palavra_inv[tam+1];
    for(i=tam-1; i>=0; i--){
        palavra_inv[j]=palavra[i];
        j++;
    }
    palavra_inv[j]='\0';
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(palavra_inv[aux] == matriz[i][j]){
                coord[0]=i;//coordenada inicial linha
                coord[1]=j;//coordenada inicial coluna
                coord[2]=i;//coordenada final linha
                coord[3]=j+tam-1;//coordenada final coluna
                for(k=1; palavra_inv[k]!='\0'; k++){
                    if((palavra_inv[k]==matriz[i][k+j])&& (k+j<= coluna)){
                            cont++;
                    }else{
                        break;
                    }
                }if(cont==tam-1){
                    encontrada = 1;

                }if(encontrada==1){
                    printf("Palavra encontrada!!\n");
                    printf("HORIZONTAL REVERSA!!\n");
                    printf("Direcao da direita para esquerda!!\n");
                    printf("comeca na linha: %d coluna: %d\n", coord[2],coord[3]);
                    printf("termina na linha: %d coluna: %d\n\n\n", coord[0],coord[1]);
                    return encontrada;
                }
            }
        }
    }
    return encontrada;
}

int vertical_direta(char *palavra,char **matriz, int linha, int coluna) ///(de cima para baixo)
{
	int i, j, k=1;
    int encontrada=0, cont=0;
    int coord[4];
    int aux=0;
    int tam=strlen(palavra);
    for(i=0; i<coluna; i++){
        for(j=0; j<linha; j++){
            if(palavra[aux] == matriz[j][i]){
                coord[0]=j;//coordenada inicial linha
                coord[1]=i;//coordenada inicial coluna
                coord[2]=j+tam-1;//coordenada final linha
                coord[3]=i;//coordenada final coluna
                for(k=1; palavra[k]!='\0' && j+k < linha; k++){
                    if(palavra[k]== matriz[j+k][i]){
                        cont++;
                    }else{
                        break;
                    }

                }
                if(cont==tam-1){
                    encontrada = 1;
                }if(encontrada==1){
                    printf("Palavra encontrada!!\n");
                    printf("VERTICAL DIRETA!!\n");
                    printf("Direcao de cima para baixo!!\n");
                    printf("comeca na linha: %d coluna: %d\n", coord[0],coord[1]);
                    printf("termina na linha: %d coluna: %d\n\n\n", coord[2],coord[3]);
                    return encontrada;
                }
            }
        }
    }
    return encontrada;
}

int vertical_reversa(char *palavra,char **matriz, int linha, int coluna) ///(de baixo para cima)
{
	int i, j=0, k;
    int encontrada=0, cont=0;
    int coord[4];
    int aux=0;
    int tam=strlen(palavra);
    char palavra_inv[tam+1];
    for(i=tam-1; i>=0; i--){
        palavra_inv[j]=palavra[i];
        j++;
    }
    palavra_inv[j]='\0';
    for(i=0; i<coluna; i++){
        for(j=0; j<linha; j++){
            if(palavra_inv[aux] == matriz[j][i]){
                coord[0]=j+tam-1;//coordenada inicial linha
                coord[1]=i;//coordenada inicial coluna
                coord[2]=j;//coordenada final linha
                coord[3]=i;//coordenada final coluna
                for(k=1; palavra_inv[k]!='\0' && j+k<linha; k++){
                    if(palavra_inv[k]==matriz[j+k][i]){
                            cont++;
                    }else{
                        break;
                    }
                }if(cont==tam-1){
                    encontrada = 1;
                }if(encontrada==1){
                    printf("Palavra encontrada!!\n");
                    printf("VERTICAL REVERSA!!\n");
                    printf("Direcao de baixo para cima!!\n");
                    printf("comeca na linha: %d coluna: %d\n", coord[0],coord[1]);
                    printf("termina na linha: %d coluna: %d\n\n\n", coord[2],coord[3]);
                    return encontrada;
                }
            }
        }
    }
    return encontrada;
}

int diagonal_direta(char *palavra,char **matriz, int linha, int coluna) ///(de cima para baixo) **  \ esquerda para direita 
{
	int aux=0;
    int i, j=0, k=1, cont=0;
    int encontrada=0;
    int coord[4];
    int tam=strlen(palavra);
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(palavra[aux] == matriz[i][j]){
                int p=i+1, q=j+1;
                for(k=1; palavra[k]!='\0' && p<linha && q<coluna; k++){
                    if(palavra[k]==matriz[p][q]){
                        cont++;
                    }else{
                        break;
                    }
                    p++;
                    q++;
                }
            }if(cont == tam-1){
                encontrada = 1;
                coord[0]=i;//coordenada inicial linha
                coord[1]=j;//coordenada inicial coluna
                coord[2]=i+tam-1;//coordenada final linha
                coord[3]=j+tam-1;//coordenada final coluna
            }cont=0;
        }
    }if(encontrada==1){
        printf("Palavra encontrada!!\n");
        printf("DIAGONAL DIRETA!!\n");
        printf("Direcao de cima para baixo!!\n");
        printf("Direcao da esquerda para direita!!\n");
        printf("comeca na linha: %d coluna: %d\n", coord[0],coord[1]);
        printf("termina na linha: %d coluna: %d\n\n\n", coord[2],coord[3]);
    }
    return encontrada;
}

int diagonal_direta_inv(char *palavra,char **matriz, int linha, int coluna) /// (de cima para baixo) ** \ direita para esquerda 
{
	int aux=0;
    int i, j=0, k, cont=0;
    int encontrada=0;
    int coord[4];
    int tam=strlen(palavra);
    char palavra_inv[tam+1];
    for(i=tam-1; i>=0; i--){
        palavra_inv[j]=palavra[i];
        j++;
    }
    palavra_inv[j]='\0';
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(palavra_inv[aux] == matriz[i][j]){
                int p=i+1, q=j+1;
                for(k=1; palavra_inv[k]!='\0' && p<linha && q<coluna; k++){
                    if(palavra_inv[k]==matriz[p][q]){
                        cont++;
                    }else{
                        break;
                    }
                    p++;
                    q++;
                }
            }if(cont == tam-1){
                encontrada = 1;
                coord[0]=i;//coordenada inicial linha
                coord[1]=j;//coordenada inicial coluna
                coord[2]=i+tam-1;//coordenada final linha
                coord[3]=j+tam-1;//coordenada final coluna
            }cont=0;
        }
    }if(encontrada==1){
        printf("Palavra encontrada!!\n");
        printf("DIAGONAL DIRETA INVERTIDA!!\n");
        printf("Direcao de cima para baixo!!\n");
        printf("Direcao da direita para esquerda!!\n");
        printf("comeca na linha: %d coluna: %d\n", coord[2],coord[3]);
        printf("termina na linha: %d coluna: %d\n\n\n", coord[0],coord[1]);
    }
    return encontrada;
}

int diagonal_reversa(char *palavra,char **matriz, int linha, int coluna) ///(de baixo para cima) ** / esquerda para direita 
{
	int i, j, aux=0, encontrada=0, k;
	int coord[4], cont=0;
	int tam=strlen(palavra);
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(palavra[aux]==matriz[i][j]){
				int p=i+1, q=j-1;
				for(k=1; palavra[k]!='\0' && p<linha && q>=0;k++){
					if(palavra[k]==matriz[p][q]){
						cont++;
                    	}else{
                        	break;
                   		}
                    	p++;
                   		q--;
				}
			}if(cont == tam-1){
                encontrada = 1;
                coord[0]=i+tam-1;//coordenada inicial linha
                coord[1]=tam-1-j;//coordenada inicial coluna
                coord[2]=i;//coordenada final linha
                coord[3]=j;//coordenada final coluna
                
            }cont=0;
        }
    }if(encontrada==1){
        printf("Palavra encontrada!!\n");
        printf("DIAGONAL DIRETA REVERSA!!\n");
        printf("Direcao de cima para baixo!!\n");
        printf("Direcao da direita para esquerda!!\n");
        printf("comeca na linha: %d coluna: %d\n", coord[2],coord[3]);
        printf("termina na linha: %d coluna: %d\n\n\n", coord[0],coord[1]);
    }
    return encontrada;
}

int diagonal_reversa_inv(char *palavra,char **matriz, int linha, int coluna) ///(de baixo para cima) ** / esquerda para direita 
{
	int i, j=0, aux=0, encontrada=0, k;
	int coord[4], cont=0;
	int tam=strlen(palavra);
	char palavra_inv[tam+1];
    for(i=tam-1; i>=0; i--){
        palavra_inv[j]=palavra[i];
        j++;
    }
    palavra_inv[j]='\0';
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(palavra_inv[aux]==matriz[i][j]){
				int p=i+1, q=j-1;
				for(k=1; palavra_inv[k]!='\0' && p<linha && q>=0;k++){
					if(palavra_inv[k]==matriz[p][q]){
						cont++;
                    	}else{
                        	break;
                   		}
                    	p++;
                   		q--;
				}
			}if(cont == tam-1){
                encontrada = 1;
                coord[0]=i;//coordenada inicial linha
                coord[1]=j;//coordenada inicial coluna
                coord[2]=i+tam-1;//coordenada final linha
                coord[3]=tam-1-j;//coordenada final coluna
                
            }cont=0;
        }
    }if(encontrada==1){
        printf("Palavra encontrada!!\n");
        printf("DIAGONAL DIRETA REVERSA INVERTIDA!!\n");
        printf("Direcao de cima para baixo!!\n");
        printf("Direcao da esquerda para direita!!\n");
        printf("comeca na linha: %d coluna: %d\n", coord[2],coord[3]);
        printf("termina na linha: %d coluna: %d\n\n\n", coord[0],coord[1]);
    }
    return encontrada;
}

void busca_na_matriz(char **matriz, int linha, int coluna)///função principal de busca
{
    int i, j=0;
    int n_letras;
    printf("Digite o numero de letras da palavra que deseja procurar:");
    scanf("%d", &n_letras);
    char palavra[n_letras+1];
    printf("Digite a palavra para a busca: \n");
    scanf("%s", palavra);
    horizontal_direta(palavra, matriz, linha, coluna);   ///    -->
    horizontal_reversa(palavra, matriz, linha, coluna);  ///    <--
    vertical_direta(palavra, matriz, linha, coluna);     ///    vertical cima -- baixo
    vertical_reversa(palavra, matriz, linha, coluna);    ///    vertical baixo -- cima
    diagonal_direta(palavra, matriz, linha, coluna);     ///    \  de cima para baixo
    diagonal_direta_inv(palavra, matriz, linha, coluna); ///    \ de baixo para cima
    diagonal_reversa(palavra, matriz, linha, coluna);    ///    / de cima para baixo
    diagonal_reversa_inv(palavra, matriz, linha, coluna);///    / de baixo para cima
}

int main()
{
    int opcao;
    char **mat;            ///matriz a ser alocada
    int   linha, coluna;   /// numero de linhas e colunas da matriz
    ///pede dados para usuario do tamanho da matriz
    do{///fica no loop ate que a matriz seja alocada corretamente
    	printf("Digite o numero de linhas da matriz:");
    	scanf("%d", &linha);
    	printf("Digite o numero de colunas da matriz:");
    	scanf("%d", &coluna);
    	///chama a função para alocar
    	mat = Alocar_matriz(linha, coluna);	
	}while(mat==NULL);
    ///chama a função para inserir aleatoriamente as letras
    insere_letras_rand(mat, linha, coluna);
    do{
        printf("\n1.-Mostrar matriz\n2.-Buscar palavra\n3.-Sair\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                escreve_matriz(mat, linha, coluna);
                break;
            case 2:
                busca_na_matriz(mat, linha, coluna);
                break;
            case 3:
                printf("\nfechando o caca palavras.\n");
                break;
            default:
                 printf("\nEntrada invalida.\n");
                 break;
        }
    }while(opcao!=3);
    Liberar_matriz_real (linha, coluna, mat);
    return 0;
}
