UFSM - CURSO DE CIÊNCIA DA COMPUTAÇÃO

programa para a aula de Estruturas de Dados - Trabalho prático 2 - prof. Antonio Candia

PROGRAMA FEITO POR: JULIANO LEONARDO SOARES

ANO: 2017 2° SEMESTRE
#####################################################################################################
RESUMINDO O PROGRAMA:
o programa consiste em 4 arquivos
1° arquivo
main.c
É o arquivo principal de execução do programa.
ele esta todo comentado.

Mas resumirei bem rapimente e bem por cima a representação interna utilizada, bem como 
do algoritmo de busca, e o porquê destas escolhas.
Eu criei o programa basicamente desta forma 
-abertura do arquivo
-fiz uma função para contar as linhas que precisarei ler do arquivo
para facilitar na manipulação do mesmo.
-e caso arquivo sem linhas fecha o programa pois não ha dados a serem inseridos.
-caso ao contrario continua a execução.
-crio o grafo com numero de vertices necessario (numero de vertices = n° linhas do arquivo)
(como o arquivo tem a formatação de que cada linha o primeiro nome seria um vertice e os
subseguintes seriam as arestas de este nome tem).
-crio um vetor de ponteiro para os vertices (n° de ponteiro = n° de linhas).
-apos as criações dos ponteiros
-começo a leitura dos vertices
 *le primeira linha salva o primeiro nomele segunda linha e vai para proxima ate terminar 
arquivo.
-apos isto leio as arestas
 *vai lendo caracter por caracter ate ';' e 1° = 0 se 1° == 1 salva como vertice entrada;
  acha o ponteiro deste vertice de entrada;
  depois de achar vertice de entrada começa a ler a segunda palavra ate ';' leu salva ;
  acha o ponteiro deste vertice de chegada;
  apos achado os dois vertices insere a aresta entre os dois;
  na ultima palavra sera '\n';
  caso encontre '\n' passa para a proxima linha e recomeça a inserção dos vertices;
  caso a  primeira palavra ja seja '\n' ou terminar o arquivo para a inserção e procegue a execução;
-apos isto abro o menu de interação com o usuario do programa com as seguintes opções
----------------------------------------------------------------------------------------------------
1°-imprime todo o grafo = chama uma função que imprime todo o grafo 
----------------------------------------------------------------------------------------------------
2°-imprime o grafo de um vertice = chama uma função que imprime o grafo apartir de um vertice
especificado pelo usuario (os vertices devem ser escritos da mesma forma que inseridos caso
contrario emite uma mensagem de não encontrado ou nomenclatura errada).
----------------------------------------------------------------------------------------------------
3°-busca menor caminho = pede o primeiro vertice e pede o segundo vertice e chama a busca
*como funciona a busca de menor caminho
resumidamente ele pega o primeiro nome adiciona a uma lista
apos verifica na matriz a possibilidade de ter um caminho para o destino case sim
adiciona a lista esta possibilidade e assim por diante
caso contrario não ha possibilidades retorna que não ha conecção
caso ha possibilidade e encontre a conecção ele imprime toda a lista que é a sequencia
para o caminho entre os dois.
-----------------------------------------------------------------------------------------------------
4°-sair = finaliza o programa
-----------------------------------------------------------------------------------------------------
O TIPO DE ESTRUTURA QUE RESOLVI USAR FOI O DE MATRIZ DE INCIDÊNCIA
O USO DESTE TIPO DE ESTRUTURA SE DEU POR CAUSA DO MODO DO ARQUIVO PARA INSERÇÃO DOS DADOS
a formatação do arquivo fez com que eu usas-se esta estrutura, pois me pareceu uma das melhores e mais 
faceis formas de colocar em prática.
a primeira palavra de cada linha seria uma linha e coluna da matriz
a matriz basicamente toda com zero
apos as primeiras palavras de cada linha seria o boleano de ativado de vertice x vertice 
#####################################################################################################
2° arquivo
grafo.c
Neste arquivo são feita as funções que posteriormente seram usadas duante a execução
#####################################################################################################
3° arquivo
grafo.h
Neste arquivo são declaradas as funções do arquivo grafo.c para o uso na main.c
#####################################################################################################
4° arquivo
amizades.txt
este arquivo é um teste já incluso com o programa
caso deseja mudar segue abaixo.

#####################################################################################################
COMO INSERIR UM ARQUIVO DIFERENTE:
-para inserir um arquivo diferente do existente ele
deve ser inserido dentro da pasta do programa com o
nome de amizades.txt.
-ou deve-se modificar o nome dentro do programa na função
main nas linhas que tem  --fp = fopen( "amizades.txt", "r" );-- deve-se 
trocar o "amizades.txt" pelo nome desejado entre aspas.
***linhas n° 125, 158, 180;

ex:
*quero adicionar o arquivo meu_grafo.txt

fp = fopen( "amizades.txt", "r" ); troco por-> fp = fopen( "meu_grafo.txt", "r" );

#####################################################################################################
RESTRIÇÕES E PROBLEMAS COM O PROGRAMA;

formatação do arquivo de entrada:
o arquivo deve seguir restritamente a formatação do exemplo
exemplo:

todos os nomes devem ser separados por ponto e virgula ( ; ).
sendo o ultimo nome não deve ter virgula no final.
todos nomes devem ser colocados em uma linha como primeiro nome mesmo que não tenha aresta.
todas as palavras devem iniciar uma vez uma linha.

*-modelo correto todos nomes iniciam pelo menos uma vez e se Nairo tem Ana  o mesmo deve valer Ana Tem Nairo
e mesmo o primeiro nome que não tem subseguinte deve conter virgula
todo primeiro nome deve conter uma virgula no final
Nairo;Duda;Ana
Ana;Nairo;Beatriz
Duda;Nairo
Beatriz;Ana
juliano;

*-ERRO possui virgula no final da linha o programa pode inserir lixo
Nairo;Duda;Ana;
Ana;Nairo;Beatriz
Duda;Nairo
Beatriz;Ana;

*-ERRO possui um nome que não iniciou a uma linha e esta vinculado um - Duda vincula Jorge - mas Jorge NÃO VINCULA Duda
Nairo;Duda;Ana
Ana;Nairo;Beatriz
Duda;Nairo;Jorge
Beatriz;Ana

*-ERRO o programa ira ler com uma unica palavra e não ira conseguir imprimir o grafo pois falta 
a virgula no final de cada 1° palavra
NairoDudaAna
AnaNairoBeatriz
DudaNairo
BeatrizAna 

*-ERRO mesmo com espaço o programa ira ler com uma unica palavra e não ira conseguir imprimir o grafo pois falta 
a virgula no final de cada 1° palavra
Nairo Duda Ana
Ana Nairo Beatriz
Duda Nairo
Beatriz Ana

tamanho das palavras:
o arquivo deve ter palavras com o numero de letras inferior a 50 caracteres para não ocasionar overflow
nas variaveis.
