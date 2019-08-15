#################################################################
# 1° trabalho da disciplina de organizacao de computadores
#
# Aluno: juliano soares
#
#################################################################

.text
.globl      main
main:		
            addiu $sp, $sp, 12  # alocamos na pilha espaco para as variaveis
            # abertura do arquivo de leitura
            la    $a0, arquivoEntrada # $a0 <- endereco da string com o nome do arquivo
            li    $a1, 0 # flags: 0  - leitura
            li	  $a2, 0 # modo - atualmente eh ignorado pelo servico
            #chamamos o servico 13 para a abertura do arquivo
            li    $v0, 13	
            syscall   
            sw    $v0, 0($sp)   # gravamos o descritor do arquivo
            slt   $t0, $v0, $zero # verificamos se houve um erro na abertura do arquivo
            bne   $t0, $zero, erroAberturaArquivoLeitura
            #  fazemos um contador igual a 8
            li    $t0, 8 
            sw    $t0, 8($sp)
            # enquanto nao chegamos no final do arquivo executamos o laco lacoLeiaPalavra
            j     verificaFinalArquivo            
lacoLeiaPalavra:
            # convertemos a palavra se a leitura foi correta
	    lw    $t4, 4($sp)
            srl   $t3, $t4, 26
            beqz  $t3, instR # ve se a instrucao eh do tipo R
            beq   $t3, 0x02, instJfJ # ve se a instrucao eh do tipo J
            beq   $t3, 0x03, instJfJal # ve se a instrucao eh do tipo J
            beq   $t3, 0x08, instIfAddi # ve se a instrucao eh do tipo I
            beq   $t3, 0x04, instIfBeq # ve se a instrucao eh do tipo I
            beq   $t3, 0x05, instIfBne # ve se a instrucao eh do tipo I
            beq   $t3, 0x23, instIfLw # ve se a instrucao eh do tipo I
            beq   $t3, 0x2b, instIfSw # ve se a instrucao eh do tipo I
            beq   $t3, 0x20, instIfLb # ve se a instrucao eh do tipo I
            beq   $t3, 0x28, instIfSb # ve se a instrucao eh do tipo I
            beq   $t3, 0x24, instIfLi # ve se a instrucao eh do tipo I
            beq   $t3, 0x09, instIfAddiu # ve se a instrucao eh do tipo I
            
            j     verificaFinalArquivo # se nao for nenhuma passa para a proxima instrucao
            
decrementaContador:
            # decrementamos o contador
            lw    $t0, 8($sp)
            addiu $t0, $t0, -1
            sw    $t0, 8($sp)
            # se contador=0 (imprimimos 8 palavras) gera uma nova linha
            #bne   $t0, $zero, imprimeEspaco
            # faz contador igual a 8
            li    $t0, 8
            sw    $t0, 8($sp)
            j     verificaFinalArquivo
                      
imprimeFimDeLinha:
	    li    $a0, '\n'
            li    $v0, 11
            syscall
            
verificaFinalArquivo:
            # lemos uma palavra do arquivo
            lw    $a0, 0($sp)   # $a0 <- descritor do arquivo
            addiu $a1, $sp, 4   # $a1 <- endereco do buffer de entrada 
            li    $a2, 4        # $a2 <- numero de caracteres lidos
            li    $v0, 14
            syscall
            # verificamos se foram lidos 4 bytes
            slti  $t0, $v0, 4
            beq   $t0, $zero, lacoLeiaPalavra
            # terminamos o programa
            li    $a0, 0 # 0 <- programa terminou de forma normal
            li    $v0, 17 # servico exit2 - termina o programa
	    syscall
	    
instR:	    
	    sll   $t3, $t4, 24 # shift para a esquerda para isolar os 6 bits
	    srl   $t3, $t3, 24 # shift para a direita para isolar o numero novamente
	    
	    beq   $t3, 0x21, faddu # pula para o procedimento da funcao
	    beq   $t3, 0x20, fadd  # até achar a funcao correspondente
	    beq   $t3, 0x24, fand 
	    beq   $t3, 0x08, fjr 
	    beq   $t3, 0x25, for 
	    beq   $t3, 0x02, fsrl 
	    beq   $t3, 0x22, fsub 
	    beq   $t3, 0x23, fsubu 
	    beq   $t3, 0x0c, fsyscall 
	    
	    j     verificaFinalArquivo # se nao for nenhuma, pula para a proxima instrucao

faddu: 
	    la    $a0, msgAddu # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	    
fadd: 
	    la    $a0, msgAdd # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	 
fand: 
	    la    $a0, msgAnd # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	   
fjr: 
	    la    $a0, msgJr # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do registrador
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador
	    jal   verificaReg # verifica o primeiro registrador a ser impresso 
            j     imprimeFimDeLinha
	    
for: 
	    la    $a0, msgOr # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	    
fsll: 
	    la    $a0, msgSll # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	    
fsrl: 
	    la    $a0, msgSrl # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	    
fsub: 
	    la    $a0, msgSub # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	  
fsubu: 
	    la    $a0, msgSubu # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 16 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do segundo registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do segundo registrador da operacao
	    jal   verificaReg # verifica o terceiro registrador a ser impresso
	    j     imprimeFimDeLinha
	    
fsyscall: 
	    la    $a0, msgSyscall # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    j     imprimeFimDeLinha	
	    
instJfJ:
	    la    $a0, msgJ # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    j     verificaInst # vai para a funcao que acha o endereco 
	    
instJfJal:
	    la    $a0, msgJal # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    j     verificaInst # vai para a funcao que acha o endereco 
instIfAddi:
	    la    $a0, msgAddi # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    j     verificaImediate # vai para a funcao que acha o valor imediato
	    
instIfBeq:
	    la    $a0, msgBeq # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    j     verificaLabel # vai para a funcao que acha o endereco
	    
instIfBne:
	    la    $a0, msgBne # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    j     verificaLabel # vai para a funcao que acha o endereco
	    
instIfLw:
	    la    $a0, msgLw # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
            sll   $t3, $t4, 16 # shift para achar os bits do valor imediato
	    srl   $t3, $t3, 16 # shift para achar os bits do valor imediato
            jal   verificaImediate2 # vai para a funcao que printa o valor imediato
            li    $a0, '('
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do registrador de origem
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador de origem
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ')'
            li    $v0, 11
            syscall
            j     imprimeFimDeLinha
	    
instIfSw:
	    la    $a0, msgSw # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
            sll   $t3, $t4, 16 # shift para achar os bits do valor imediato
	    srl   $t3, $t3, 16 # shift para achar os bits do valor imediato
            jal   verificaImediate2 # vai para a funcao que printa o valor imediato
            li    $a0, '('
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do registrador de origem
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador de origem
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ')'
            li    $v0, 11
            syscall
	    j     imprimeFimDeLinha
	    
instIfLb:
	    la    $a0, msgLb # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
            sll   $t3, $t4, 16 # shift para achar os bits do valor imediato
	    srl   $t3, $t3, 16 # shift para achar os bits do valor imediato
            jal   verificaImediate2 # vai para a funcao que printa o valor imediato
            li    $a0, '('
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do registrador de origem
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador de origem
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ')'
            li    $v0, 11
            syscall
            j     imprimeFimDeLinha
	    
instIfSb:
	    la    $a0, msgSb # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
            sll   $t3, $t4, 16 # shift para achar os bits do valor imediato
	    srl   $t3, $t3, 16 # shift para achar os bits do valor imediato
            jal   verificaImediate2 # vai para a funcao que printa o valor imediato
            li    $a0, '('
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do registrador de origem
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador de origem
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ')'
            li    $v0, 11
            syscall
	    j     imprimeFimDeLinha
	    
instIfLi:
	    la    $a0, msgLi # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    j     verificaImediate # vai para a funcao que acha ovalor imediato

instIfAddiu:
	    la    $a0, msgAddiu # imprime a mensagem da instrucao
	    li    $v0, 4
	    syscall
	    sll   $t3, $t4, 11 # shift para achar os bits do registrador destino
	    srl   $t3, $t3, 27 # shift para achar os bits do registrador destino
	    jal   verificaReg # verifica o primeiro registrador a ser impresso
	    li    $a0, ','
            li    $v0, 11
            syscall
	    sll   $t3, $t4, 6 # shift para achar os bits do primeiro registrador da operacao
	    srl   $t3, $t3, 27 # shift para achar os bits do primeiro registrador da operacao
	    jal   verificaReg # verifica o segundo registrador a ser impresso 
	    li    $a0, ','
            li    $v0, 11
            syscall
	    j     verificaImediate # vai para a funcao que acha ovalor imediato
	    
verificaInst:
	    sll   $t3, $t4, 6 # shift para achar os bits do endereco
	    srl   $t3, $t3, 6 # shift para achar os bits do endereco
	    
	    add   $a0, $t3, $zero # imprime o endereco
            li    $v0, 34
            syscall
            j     imprimeFimDeLinha
            
verificaLabel:
	    sll   $t3, $t4, 16 # shift para achar os bits do endereco
	    srl   $t3, $t3, 16 # shift para achar os bits do endereco
	    
	    add   $a0, $t3, $zero 
            li    $v0, 34
            syscall
            j     imprimeFimDeLinha
       
verificaImediate:
	    sll   $t3, $t4, 16 # shift para achar os bits do valor imediato
	    srl   $t3, $t3, 16 # shift para achar os bits do valor imediato
	    
	    add   $a0, $t3, $zero # imprime o valor
            li    $v0, 1
            syscall
            j     imprimeFimDeLinha
            
verificaImediate2:
	    add   $a0, $t3, $zero # imprime o valor
            li    $v0, 1
            syscall
            
            jr    $ra
	    
verificaReg:	    
	    beq   $t3, 0x00, reg0 # reconhece o registrador e pula para o procedimento
	    beq   $t3, 0x01, reg1 # $at
	    beq   $t3, 0x02, reg2 # $v0
	    beq   $t3, 0x03, reg3 # $v1
	    beq   $t3, 0x04, reg4 # $a0
	    beq   $t3, 0x05, reg5 # $a1
	    beq   $t3, 0x06, reg6 # $a2
	    beq   $t3, 0x07, reg7 # $a3
	    beq   $t3, 0x08, reg8 # $t0
	    beq   $t3, 0x09, reg9 # $t1
	    beq   $t3, 0x0a, reg10 # $t2
	    beq   $t3, 0x0b, reg11 # $t3
	    beq   $t3, 0x0c, reg12 # $t4
	    beq   $t3, 0x0d, reg13 # $t5
	    beq   $t3, 0x0e, reg14 # $t6
	    beq   $t3, 0x0f, reg15 # $t7
	    beq   $t3, 0x10, reg16 # $s0
	    beq   $t3, 0x11, reg17 # $s1
	    beq   $t3, 0x12, reg18 # $s2
	    beq   $t3, 0x13, reg19 # $s3                	 	    	                	            
	    beq   $t3, 0x14, reg20 # $s4
	    beq   $t3, 0x15, reg21 # $s5
	    beq   $t3, 0x16, reg22 # $s6
	    beq   $t3, 0x17, reg23 # $s7
	    beq   $t3, 0x1d, reg29 # $sp
	    beq   $t3, 0x1f, reg31 # $ra
	    
	    j     verificaFinalArquivo # se não for nenhum 
	    
reg0:
	    la    $a0, msg0 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	  
reg1:
	    la    $a0, msg1 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	      
reg2:
	    la    $a0, msg2 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr     $ra
	    
reg3:
	    la    $a0, msg3 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg4:
	    la    $a0, msg4 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg5:
	    la    $a0, msg5 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg6:
	    la    $a0, msg6 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg7:
	    la    $a0, msg7 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    	    
reg8:
	    la    $a0, msg8 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg9:
	    la    $a0, msg9 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg10:
	    la    $a0, msg10 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg11:
	    la    $a0, msg11 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg12:
	    la    $a0, msg12 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg13:
	    la    $a0, msg13 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg14:
	    la    $a0, msg14 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    	    	    	    	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      	    	    	    	      	      	    	      	      	    	    	      	      	    	      	      
reg15:
	    la    $a0, msg15 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg16:
	    la    $a0, msg16 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg17:
	    la    $a0, msg17 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg18:
	    la    $a0, msg18 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg19:
	    la    $a0, msg19 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg20:
	    la    $a0, msg20 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg21:
	    la    $a0, msg21 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg22:
	    la    $a0, msg22 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg23:
	    la    $a0, msg23 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg29:
	    la    $a0, msg29 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	    
reg31:
	    la    $a0, msg31 # imprime o registrador
	    li    $v0, 4
	    syscall
	    jr    $ra
	        	     	    	 	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	     	    	 	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    	    
erroAberturaArquivoLeitura:
            la    $a0, mensagemErroAberturaArquivo # $a0 <- endereco da string com mensagem de erro
            li    $v0, 4 # servico 4: impressao de string
            syscall # fazemos uma chamada ao sistema: fazemos a impressao da string, indicando o erro.
            li    $a0, 1 # valor diferente de 0: o programa terminou com erros
            li    $v0, 17 #servico exit2 - termina o programa	
            syscall
                            
                            
.data
arquivoEntrada: # nome do arquivo de entrada
.asciiz           "exercicio12.dump" 
mensagemErroAberturaArquivo: # mensagem de erro se o arquivo nao pode ser aberto
.asciiz           "Erro na abertura do arquivo de entrada\n"
msgAddu: .asciiz "addu "
msgAdd: .asciiz "add "
msgAnd: .asciiz "and "
msgJr: .asciiz "jr "
msgOr: .asciiz "or "
msgSll: .asciiz "sll "
msgSrl: .asciiz "srl "
msgSub: .asciiz "sub "
msgSubu: .asciiz "subu "
msgSyscall: .asciiz "syscall"
msgJ: .asciiz "j "
msgJal: .asciiz "jal "
msgAddi: .asciiz "addi "
msgBeq: .asciiz "beq "
msgBne: .asciiz "bne "
msgLw: .asciiz "lw "
msgSw: .asciiz "sw "
msgLb: .asciiz "lb "
msgSb: .asciiz "sb "
msgLi: .asciiz "li "
msgLa: .asciiz "la "
msgAddiu: .asciiz "addiu "
msg0: .asciiz "$zero"
msg2: .asciiz "$at"
msg1: .asciiz "$v0"
msg3: .asciiz "$v1"
msg4: .asciiz "$a0"
msg5: .asciiz "$a1"
msg6: .asciiz "$a2"
msg7: .asciiz "$a3"
msg8: .asciiz "$t0"
msg9: .asciiz "$t1"
msg10: .asciiz "$t2"
msg11: .asciiz "$t3"
msg12: .asciiz "$t4"
msg13: .asciiz "$t5"
msg14: .asciiz "$t6"
msg15: .asciiz "$t7"
msg16: .asciiz "$s0"
msg17: .asciiz "$s1"
msg18: .asciiz "$s2"
msg19: .asciiz "$s3"
msg20: .asciiz "$s4"
msg21: .asciiz "$s5"
msg22: .asciiz "$s6"
msg23: .asciiz "$s7"
msg29: .asciiz "$sp"
msg31: .asciiz "$ra"

