UFSM - CURSO DE CI�NCIA DA COMPUTA��O

programa para a aula de Estruturas de Dados - Trabalho pr�tico 2 - prof. Antonio Candia

PROGRAMA FEITO POR: JULIANO LEONARDO SOARES

ANO: 2017 2� SEMESTRE
#####################################################################################################
RESUMINDO O PROGRAMA:
o programa consiste em 4 arquivos
1� arquivo
main.c
� o arquivo principal de execu��o do programa.
ele esta todo comentado.

Mas resumirei bem rapimente e bem por cima a representa��o interna utilizada, bem como 
do algoritmo de busca, e o porqu� destas escolhas.
Eu criei o programa basicamente desta forma 
-abertura do arquivo
-fiz uma fun��o para contar as linhas que precisarei ler do arquivo
para facilitar na manipula��o do mesmo.
-e caso arquivo sem linhas fecha o programa pois n�o ha dados a serem inseridos.
-caso ao contrario continua a execu��o.
-crio o grafo com numero de vertices necessario (numero de vertices = n� linhas do arquivo)
(como o arquivo tem a formata��o de que cada linha o primeiro nome seria um vertice e os
subseguintes seriam as arestas de este nome tem).
-crio um vetor de ponteiro para os vertices (n� de ponteiro = n� de linhas).
-apos as cria��es dos ponteiros
-come�o a leitura dos vertices
 *le primeira linha salva o primeiro nomele segunda linha e vai para proxima ate terminar 
arquivo.
-apos isto leio as arestas
 *vai lendo caracter por caracter ate ';' e 1� = 0 se 1� == 1 salva como vertice entrada;
  acha o ponteiro deste vertice de entrada;
  depois de achar vertice de entrada come�a a ler a segunda palavra ate ';' leu salva ;
  acha o ponteiro deste vertice de chegada;
  apos achado os dois vertices insere a aresta entre os dois;
  na ultima palavra sera '\n';
  caso encontre '\n' passa para a proxima linha e recome�a a inser��o dos vertices;
  caso a  primeira palavra ja seja '\n' ou terminar o arquivo para a inser��o e procegue a execu��o;
-apos isto abro o menu de intera��o com o usuario do programa com as seguintes op��es
----------------------------------------------------------------------------------------------------
1�-imprime todo o grafo = chama uma fun��o que imprime todo o grafo 
----------------------------------------------------------------------------------------------------
2�-imprime o grafo de um vertice = chama uma fun��o que imprime o grafo apartir de um vertice
especificado pelo usuario (os vertices devem ser escritos da mesma forma que inseridos caso
contrario emite uma mensagem de n�o encontrado ou nomenclatura errada).
----------------------------------------------------------------------------------------------------
3�-busca menor caminho = pede o primeiro vertice e pede o segundo vertice e chama a busca
*como funciona a busca de menor caminho
resumidamente ele pega o primeiro nome adiciona a uma lista
apos verifica na matriz a possibilidade de ter um caminho para o destino case sim
adiciona a lista esta possibilidade e assim por diante
caso contrario n�o ha possibilidades retorna que n�o ha conec��o
caso ha possibilidade e encontre a conec��o ele imprime toda a lista que � a sequencia
para o caminho entre os dois.
-----------------------------------------------------------------------------------------------------
4�-sair = finaliza o programa
-----------------------------------------------------------------------------------------------------
O TIPO DE ESTRUTURA QUE RESOLVI USAR FOI O DE MATRIZ DE INCID�NCIA
O USO DESTE TIPO DE ESTRUTURA SE DEU POR CAUSA DO MODO DO ARQUIVO PARA INSER��O DOS DADOS
a formata��o do arquivo fez com que eu usas-se esta estrutura, pois me pareceu uma das melhores e mais 
faceis formas de colocar em pr�tica.
a primeira palavra de cada linha seria uma linha e coluna da matriz
a matriz basicamente toda com zero
apos as primeiras palavras de cada linha seria o boleano de ativado de vertice x vertice 
#####################################################################################################
2� arquivo
grafo.c
Neste arquivo s�o feita as fun��es que posteriormente seram usadas duante a execu��o
#####################################################################################################
3� arquivo
grafo.h
Neste arquivo s�o declaradas as fun��es do arquivo grafo.c para o uso na main.c
#####################################################################################################
4� arquivo
amizades.txt
este arquivo � um teste j� incluso com o programa
caso deseja mudar segue abaixo.

#####################################################################################################
COMO INSERIR UM ARQUIVO DIFERENTE:
-para inserir um arquivo diferente do existente ele
deve ser inserido dentro da pasta do programa com o
nome de amizades.txt.
-ou deve-se modificar o nome dentro do programa na fun��o
main nas linhas que tem  --fp = fopen( "amizades.txt", "r" );-- deve-se 
trocar o "amizades.txt" pelo nome desejado entre aspas.
***linhas n� 125, 158, 180;

ex:
*quero adicionar o arquivo meu_grafo.txt

fp = fopen( "amizades.txt", "r" ); troco por-> fp = fopen( "meu_grafo.txt", "r" );

#####################################################################################################
RESTRI��ES E PROBLEMAS COM O PROGRAMA;

formata��o do arquivo de entrada:
o arquivo deve seguir restritamente a formata��o do exemplo
exemplo:

todos os nomes devem ser separados por ponto e virgula ( ; ).
sendo o ultimo nome n�o deve ter virgula no final.
todos nomes devem ser colocados em uma linha como primeiro nome mesmo que n�o tenha aresta.
todas as palavras devem iniciar uma vez uma linha.

*-modelo correto todos nomes iniciam pelo menos uma vez e se Nairo tem Ana  o mesmo deve valer Ana Tem Nairo
e mesmo o primeiro nome que n�o tem subseguinte deve conter virgula
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

*-ERRO possui um nome que n�o iniciou a uma linha e esta vinculado um - Duda vincula Jorge - mas Jorge N�O VINCULA Duda
Nairo;Duda;Ana
Ana;Nairo;Beatriz
Duda;Nairo;Jorge
Beatriz;Ana

*-ERRO o programa ira ler com uma unica palavra e n�o ira conseguir imprimir o grafo pois falta 
a virgula no final de cada 1� palavra
NairoDudaAna
AnaNairoBeatriz
DudaNairo
BeatrizAna 

*-ERRO mesmo com espa�o o programa ira ler com uma unica palavra e n�o ira conseguir imprimir o grafo pois falta 
a virgula no final de cada 1� palavra
Nairo Duda Ana
Ana Nairo Beatriz
Duda Nairo
Beatriz Ana

tamanho das palavras:
o arquivo deve ter palavras com o numero de letras inferior a 50 caracteres para n�o ocasionar overflow
nas variaveis.
