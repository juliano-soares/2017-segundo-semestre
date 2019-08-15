
.text
main: 
	# a = b + c + d + e;
	# $s1 <- a
	# $s2 <- b
	# $s3 <- c
	# $s4 <- d
	# $s5 <- e
	# carregamos uma copia dos valores da variáveis nos registradores
	la	$t0, variavelB	# carregamos b em $s2
	lw  $s2, 0($t0)		#
	la  $t0, variavelC	# carregamos c em $s3
	lw  $s3, 0($t0)		#
	la  $t0, variavelD	# carregamos d em $s4
	lw  $s4, 0($t0)		#
	la  $t0, variavelE	# carregamos e em $s5
	lw  $s5, 0($t0)		#
	# fazemos a soma de b+c+d+e
	add $t0, $s2, $s3	# $t0 = b + c
	add $t1, $s4, $s5	# $t1 <- d + e
	add $s1, $t0, $t1	# $s1 <-(b + c) + (d + e)
	# guardamos o resultado da soma na variável a, na memória
	la  $t0, variavelA
	sw  $s1, 0($t0)
	# ...

.data
variavelA: 	.space 	4
variavelB: 	.word 	1
variavelC: 	.word 	2
variavelD: 	.word 	3
variavelE: 	.word 	4