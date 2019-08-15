.text 
main: 
    # ...
    # traduzindo o seguinte trecho de código em C
    # i = 1;
    # j = 2;
    # k = 0;
    # a[k] = a[i] + a[j]
    # ...  
    # vamos supor que i,j e k já estejam em registradores
    # $s0 <- i
    # $s1 <- j
    # $s2 <- k
    li $s0, 1    # i = 1
    li $s1, 2    # j = 2
    li $s2, 0    # k = 0
    # a[k] = a[i] + a[j];     
    la $t0, vetorA        # $t0 <- endereço base do vetor a 
    # carregamos a[i]    
    add $t1, $s0, $s0    # $t1 <- i*2
    add $t1, $t1, $t1    # $t1 <- i*4
    # ou sll $t1, $s0, 2
    add $t1, $t0, $t1    # $t1 <- endereço de a[i]
    lw $t2, 0($t1)        # $t2 <- a[i]
    # carregamos a[j]
    sll $t1, $s1, 2        # $t1 <- j*4
    add $t1, $t0, $t1    # $t1 <- endereço de a[j]
    lw $t3, 0($t1)        # $t3 <- a[j]
    # fazemos a soma de a[i] com a[j]
    add $t4, $t2, $t3    # $t4 <- a[i]+a[j]
    # armazenado o resultado em a[k]
    mul $t1, $s2, 4     # $t1 <- k * 4
    # ou sll $t1, $s2, 2
    add $t1, $t0, $t1    # $t1 <- endereço de a[k]
    sw $t4, 0($t1)        # a[k] <- a[i] + a[j]
    # ... 
.data 
vetorA: .word 0,1,2,3,4,5,6,7,8,9
