.text
.globl main

# Este programa copia a string1 na string2 e em seguida
# imprime a string2

###############################################################################
main:
###############################################################################
	# copia a string1 na string2	
	la		$a0, string1		# a0 <- *s1
	la 		$a1, string2		# a1 <- *s2
	jal		copiaString			# chama a função copiaString
	# imprime a string2
	li 		$v0, 4				# serviço 4 - imprime uma string
	la 		$a0, string2		# a0 <- endereço da string terminada com um zero (nulo)
	syscall						# chamada ao sistema
	li		$a0, 0				# main retorna 0
	li 		$v0, 17				# serviço 17 - término do programa
	syscall						# chamada ao sistema

###############################################################################	
copiaString:
###############################################################################
	addiu 	$sp, $sp, -8			# ajusta a pilha para receber 2 itens
	sw 		$a0, 4($sp)			# guarda *s1
	sw 		$a1, 0($sp)			# guarda *s0
	
LOOP:
	lb 		$t0, 0($a0)			# carrega um caracter de S1
	sb 		$t0, 0($a1)			# copia o byte para s2
	beq 	$t0, $zero, EXIT	# se for zero termina, vá para EXIT
	addi 	$a0, $a0, 1			# aponta para o proximo caracter de s1
	addi 	$a1, $a1, 1			# aponta para o proximo carcater de s2
	j LOOP						# repete este procedimento, vá para LOOP
EXIT:
	sb 		$t0, 0($a1)			# *s2 = 0
	lw 		$a1, 0($sp)			# restaura o valor de *s1
	lw 		$a0, 4($sp)			# restaura o valor de *s2
	addiu 	$sp, $sp, 8			# elimina 2 elementos da pilha
	jr 		$ra					# retorna para o procedimento chamador

.data
string1: .asciiz "teste de uma string\0xxxxxx"
string2: .asciiz "???????????????????????????"	
