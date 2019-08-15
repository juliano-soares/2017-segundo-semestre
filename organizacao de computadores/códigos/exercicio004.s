.text
	# ...
	# a[2] = a[0] + a[1];
	la 	$t0, vetorA		# $t0 <- endereço base do vetor a
	lw 	$t1, 0($t0)		# $t1 <- a[0]
	lw 	$t2, 4($t0)		# $t2 <- a[1]
	add $t3, $t1, $t2	# $t3 <- a[0] + a[1]
	sw 	$t3, 8($t0)		# a[2] <- a[0] + a[1]
	# ...
.data
vetorA: .word 1,2,3,4,5,6,7,8,9,10

