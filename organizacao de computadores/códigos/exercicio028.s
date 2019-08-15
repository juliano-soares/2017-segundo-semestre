.text
.globl main

main:
	# carrega nos registradores os endereços dos dados
	la 	$s0, memory	# $s0 <- endereço de memory
	la 	$s1, dataw	# $s1 <- endereço de dataw
	la 	$s2, datah	# $s2 <- endereço de datah
	la 	$s3, datab	# $s3 <- endereço de datab
	# carrega da memória para registrador, com extensão do sinal
	lw	$t0, 0($s0)	# $t0 <- 0xABCDE080
	lh	$t1, 0($s0)	# $t1 <- 0XFFFFE080
	lb	$t2, 0($s0)	# $t2 <- 0xFFFFFF80
	lb	$t3, 1($s0)	# $t3 <- 0xFFFFFFE0
	lb	$t4, 2($s0)	# $t3 <- 0xFFFFFFCD
	lb	$t5, 3($s0)	# $t3 <- 0xFFFFFFAB
	# carrega da memória para registrador, sem extensão do sinal
	lhu	$t6, 0($s0)	# $t6 <- 0x0000E080
	lbu	$t7, 0($s0)	# $t7 <- 0x00000080
	# armazena conteúdo do registrador na memória
	sw 	$t0, 0($s1)	# mem[dataw] <- $t0
	sh	$t1, 0($s2)	# mem[datah] <- $t1
	sb	$t2, 0($s3)     # mem[datab] <- $t2
	

.data
 
memory:	.word 0xABCDE080	# a palavra 0xABCDE080 é armazenada no endereço memory, little enddian: 80E0CDAB
dataw:	.space 4		# reservamos 4 bytes
datah:	.space 2		# reservamos 2 bytes
datab:	.space 1		# reservamos 1 byte