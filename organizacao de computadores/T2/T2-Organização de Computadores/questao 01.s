# Escreva um programa, em linguagem de montagem para o MIPS, que realize a divis„o de
# dois n˙meros de 32 bits, em ponto inteiro, sem sinal. A divis„o deve ser realizada com o
# segundo algoritmo da divis„o do livro do Patterson (Patterson e Hennessy, 2014) (figura 3.12).
# O programa deve permitir a entrada do dividendo e do divisor. A saÌda do programa deve
# apresentar o quociente e o resto da divis„o.

# nome: juliano leonardo soares
.text
.globl main

# inicio do programa
main:
	# mensagem inicial do programa
		jal mensagem_0
###############################################################################################################	
inicia:	
	# leitura do DIVIDENDO numero
		# $t1 - recebe 1∞ numero
		jal mensagem_1
	# verifica a resposta do usuario na caixa dialogo
		# se status  = -1: os dados de entrada n„o podem ser analisados ??corretamente
		beq $a1, -1, mensagem_6
		# se status  = -2: Cancel foi escolhido 
		beq $a1, -2, mensagem_7
		# se status  = -3: OK foi escolhido, mas nenhum dado foi inserido no campo
		beq $a1, -3, mensagem_8
	# carrega o inteiro lido em $t1
		la  $t1, 0($a0)		  
	#verifica se o numero DIVIDENDO È negativo
		la $t3, 0
		slt $t0, $t1, $t3
	# verifica retorno de slt em $t0 (este registrador sera usado para todas analises no programa)
		# se retorno igual 1 = negativo
		# se retorno igual 0 = n„o negativo
		beq $t0, 1, mensagem_3
	#verifica se o numero DIVIDENDO È igual a zero 
		beq $t1, 0, mensagem_9
###############################################################################################################		
	# leitura do DIVISOR numero
	# $t2 - recebe 2∞ numero
	jal mensagem_2
	# verifica a resposta do usuario na caixa dialogo
		# se status  = -1: os dados de entrada n„o podem ser analisados ??corretamente
		beq $a1, -1, mensagem_6
		# se status  = -2: Cancel foi escolhido 
		beq $a1, -2, mensagem_7
		# se status  = -3: OK foi escolhido, mas nenhum dado foi inserido no campo
		beq $a1, -3, mensagem_8
	# carrega o inteiro lido em $t2
		la  $t2, 0($a0)		  
	#verifica se o numero DIVIDENDO È negativo
		la $t3, 0
		slt $t0, $t2, $t3
	# verifica retorno de slt em $t0 (este registrador sera usado para todas analises no programa)
		# se retorno igual 1 = negativo
		# se retorno igual 0 = n„o negativo
		beq $t0, 1, mensagem_4
	#verifica se o numero DIVIDENDO È igual a zero 
		beq $t2, 0, mensagem_10
###############################################################################################################		
	# execuÁ„o da divis„o
	# laÁo
		
	    	la $s0, 0($t1)     	# carregamos em $t3 com o valor do dividendo
	    				# $t3 ser· o resto
            	la $t4, 0     		# carregamos em $t4 com o valor zero
					# $t4 ser· o quociente
            	j testa_condicao	# verificamos se a condi√ß√£o do la√ßo while √© verdadeira
instrucao_while:                # inicio das instru√ß√µes lo la√ßo while
            # $t3 = $t3 - divisor;      // decrementa a vari√°vel $t3
            	sub  $s0, $s0, $t2   # decrementamos a vari√°vel $t3
		add $t4, $t4, 1 # quociente recebe +1

testa_condicao:                 # testamos se a condi√ß√£o do la√ßo while √© verdadeira
            	la $t0, 1
	    	slt $a1, $s0, $t0 # verifica se resto < 1
           	beq $a1, 0, instrucao_while # se $a1 = 0 ainda n„o È menor que um
 		
	# saio da iteraÁ„o
	# verifica os resultados
		
	# se menor que zero corrige quociente e resto
		la $t0, 0
	    	slt $a1, $s0, $t0 # verifica se resto < 0
           	bne $a1, 0, corrige # se $a1 = 0 ainda n„o È menor que um
           	j s_corrige	
# corrige valores
corrige:
	add $s0, $s0, $t2
        sub $t4, $t4, 1
s_corrige:
        # imprime valores
          	jal imprimir
	# so finaliza o progrma com ordem do usuario
		j main
###############################################################################################################		
	# fim da execuÁ„o do programa
		j   fim	
###############################################################################################################	
	
# mensagens ao usuario
mensagem_0:## diz ao usuario resumo do programa e suas entradas
	li $v0, 50 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0; 
	la $a0, string0 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	# verifica a resposta do usuario na caixa dialogo
		# se status  = -1: os dados de entrada n„o podem ser analisados ??corretamente
		beq $a0, 0, inicia
		# se status  = -2: Cancel foi escolhido 
		beq $a0, 1, fim
		# se status  = -3: OK foi escolhido, mas nenhum dado foi inserido no campo
		beq $a0, 2, fim	
	jr $ra		# volta para o lugar de onde foi chamado
	
	## diz ao usuario tipos de entrada (Digite o Dividendo) 
	#le o que foi digitado pelo usuario
mensagem_1:
	li $v0, 51 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;  
	la $a0, string1 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jr $ra		# volta para o lugar de onde foi chamado
	
	## diz ao usuario tipos de entrada (Digite o divisor)
	#le o que foi digitado pelo usuario	
mensagem_2:
	li $v0, 51 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0; 
	la $a0, string2 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jr $ra		# volta para o lugar de onde foi chamado
	
mensagem_3:## Diz alerta de erro caso o usuario digite um valor negativo PARA O DIVIDENDO
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;  
	la $a0, string3 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_4:## Diz alerta de erro caso o usuario digite um valor negativo PARA O DIVISOR
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0; 
	la $a0, string4 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_5:## Diz alerta de erro caso o usuario digite um valor PARA O DIVISOR IGUAL A ZERO
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, string5 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_6:## Diz alerta de caso usuario digite um dados de entrada que n„o podem ser analisados ??corretamente
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, string6 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_7:## Diz alerta de cancelamento do usuario na caixa dialogo
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, string7 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_8:## Diz alerta de caso usuario n„o digite nada mas aperta ok
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, string8 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_9:## Diz alerta de caso usuario n„o digite nada mas aperta ok
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, string9 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim

mensagem_10:## Diz alerta de caso usuario n„o digite nada mas aperta ok
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, string10 # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jal fim
		
# manda imprimir os resultado
imprimir: # $a0 string # $a1 valor para syscall 56
	li $v0, 56 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;  
	la $a0, resto # carregar o endereÁo da string a ser impressa em $ a0
	la $a1, ($s0) # carregar o endereÁo da string a ser impressa em $ a1
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	li $v0, 56 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;  
	la $a0, quociente # carregar o endereÁo da string a ser impressa em $ a0
	la $a1, ($t4) # carregar o endereÁo da string a ser impressa em $ a1
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	jr $ra	# volta para o lugar de onde foi chamado
		
# finalizao programa
fim:	 
	li $v0, 55 # carregue o cÛdigo adequado da chamada do sistema para registrar $ v0;
	la $a0, stringfim # carregar o endereÁo da string a ser impressa em $ a0
	syscall # call sistema operacional para executar a operaÁ„o de impress„o
	li $v0, 10	# cÛdigo para encerrar o programa
	syscall		# executa a chamada do SO para encerrar
	
# dados
.data
# mensagens que aparecem ao usuario
string0:	.asciiz "ESTE … PROGRAMA DE DIVIS√O APENAS DE NUMEROS POSITIVOS\nENTRE 0 AT… 2^31-1\nDESEJA CONTINUAR?" # mensagem inicial do programa
string1: 	.asciiz "DIGITE O DIVIDENDO"				# mensagem sobre dividendo
string2: 	.asciiz "DIGITE O DIVISOR"				# mensagem sobre divisos
string3:	.asciiz "ERRO VOC  DIGITOU UM DIVIDENDO NEGATIVO"	# mensagem sobre erro de valores negativo
string4:	.asciiz "ERRO VOC  DIGITOU UM DIVISOR NEGATIVO"		# mensagem sobre erro de valores negativo
string5:	.asciiz "ERRO VOC  DIGITOU UM DIVISOR IGUAL A ZERO"	# mensagem sobre erro de valores negativo
string6:	.asciiz "VOC  DIGITOU UM DADO DE ENTRADA QUE N√O PODE SER ANALISADO CORRETAMENTE" # caso usuario digite um dados de entrada que n„o podem ser analisados ??corretamente
string7:	.asciiz "VOC  ESCOLHEU CANCELAR FINALIZANDO O PROGRAMA" # caso usuario escolha cancelar
string8:	.asciiz "VOC  N√O INSERIU DADOS"			# caso usuario n„o digite nada mas aperta ok
string9:	.asciiz "VOC  DIGITOU AO DIVIDENDO O VALOR = 0 (ZERO)\nZERO DIVIDIDO POR QUALQUER VALOR DA OS SEGUINTES RESULTADOS:\nQUOCIENTE = 0 (ZERO)\nRESTO = 0 (ZERO)" # caso usuario digitou zero ao dividendo
string10:       .asciiz "VOC  DIGITOU AO DIVISOR O VALOR = 0 (ZERO)\nSENDO DIVISOR IGUAL A ZERO\nO PROGRAMA N√O EXECUTAR TAL DIVIS√O!!" # caso divisor igual a zero
stringfim:	.asciiz "FINALIZANDO O PROGRAMA"			# mensagem sobre fim do programa
q_linha: 	.asciiz "\n"
resto: 		.asciiz "\nO RESTO …:\n"					# MENSAGEM RESTO
quociente: 	.asciiz "\nO QUOCIENTE …:\n"					# MENSAGEM quociente
