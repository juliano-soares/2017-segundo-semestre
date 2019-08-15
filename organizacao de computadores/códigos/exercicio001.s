
.text
main: 
	# traduzindo a = b + c;
	# $s1 <- a
	# $s2 <- b
	# $s3 <- c
	# ...
	la	$t0, variavelB		# carregamos a variável b em $s2
	lw  $s2, 0($t0)			#
	la  $t0, variavelC		# carregamos a variável c em $s3
	lw  $s3, 0($t0)			#
	add $s1, $s2, $s3		# $s1 <- b + c = a
	la  $t0, variavelA		# salvamos $s1=b+c em a
	sw  $s1, 0($t0)			#

.data
variavelA: 	.space 	4
variavelB: 	.word 	1
variavelC: 	.word 	2