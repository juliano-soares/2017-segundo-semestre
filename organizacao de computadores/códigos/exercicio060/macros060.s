#*******************************************************************************
# macros060.s               Copyright (C) 2017 Giovani Baratto
# This program is free software under GNU GPL V3 or later version
# see http://www.gnu.org/licences
#
# Autor: Giovani Baratto (GBTO) - UFSM - CT - DELC
# e-mail: giovani.baratto@ufsm.br
# versão: 0.1
# Descrição: 
#
# Documentação:
# Assembler: MARS
# Revisões:
# Rev #  Data           Nome   Comentários
# 0.1    21/06/2017     GBTO   versão inicial 
#*******************************************************************************
#        1         2         3         4         5         6         7         8
#2345678901234567890123456789012345678901234567890123456789012345678901234567890
#           M     O                 #


################################################################################
.eqv        NUMERO_INSTRUCOES           16
.eqv        SERVICO_IMPRIME_STRING      4
.eqv        SERVICO_IMPRIME_CARACTER    11
.eqv        SERVICO_IMPRIME_NUMERO_HEXADECIMAL 34
.eqv        SERVICO_TERMINA_PROGRAMA    17
.eqv        BIT_MAIS_SIGNIFICATIVO      31
.eqv        PROGRAMA_EXECUTADO_SUCESSO  0
################################################################################

################################################################################
# Descrição: Esta macro imprime a string %str
# Uso      : imprime_string("teste")
.macro imprime_string (%str)
.data
str: .asciiz %str
.text
            li    $v0, SERVICO_IMPRIME_STRING
            la    $a0, str
            syscall
.end_macro
################################################################################

################################################################################
# Descrição: Esta macro imprime o caracter %char
# Uso      : imprime_caracter('c')
.macro imprime_caracter(%char)
.text
            li   $v0, SERVICO_IMPRIME_CARACTER
            li   $a0, %char
            syscall
.end_macro
################################################################################

################################################################################
# Descrição: Esta macro imprime o caracter espaço (ASCII 0x20)
# Uso      : imprime_espaco()
.macro imprime_espaco()
            imprime_caracter(' ')
.end_macro
################################################################################


################################################################################
# Descrição: Esta macro faz com que a saída de impressão pule para o início da
#            próxima linha
# Uso      : nova_linha();
.macro nova_linha()
            imprime_caracter('\n')
.end_macro
################################################################################


################################################################################
# Descrição: Esta macro coloca um argumento em $a0 e chama o procedimento 
#            procedimento_leia_instrucao. O argumento
# Uso      : leia_instrucao(instrucoes)
#            instrucoes é o rótulo com o endereço do vetor de instruções em 
#            linguagem de máquina
.macro leia_instrucao(%endereco_instrucoes)
.text
            la    $a0, %endereco_instrucoes # carregamos o endereço do vetor com as instruções
            jal   procedimento_leia_instrucao # lemos a próxima instrução a ser processada
.end_macro 
################################################################################


################################################################################
# Descrição: Esta macro coloca os argumentos em $a0, $a1, $a2 e $a3 e chama o 
#            procedimento procedimento_extrai_campo_instrucao. Nesta macro,
#            consideramos que a instrução em linguagem de máquina está armazenada
#            no endereço $sp+4.
#            $a0: a instrução que será decodificada (deve estar em $sp+4)
#            $a1: o endereço da variável que guardará o campo extraido
#            $a2: o bit mais significativo do campo
#            $a3: o bit menos significativo do campo
# Uso      : extrai_campo_instrucao(campo_opcode, 31, 26)
#            campo_opcode é o endereço para a variável que irá armazenar o valor 
#            do campo da instrução, entre 
.macro extrai_campo_instrucao(%campo, %bitmax, %bitmin)
.text
    # carregamos em $a0 a instrução
            lw    $a0, 4($sp)
    # o endereço da variável a ser guardado o campo em $a1
            la    $a1, %campo
    # os bits do campo nos registradores $a2 e $a3
            li    $a2, %bitmax
            li    $a3, %bitmin
    # chamamos o procedimento para extrair o campo e guardar na variável campo
            jal   procedimento_extrai_campo_instrucao
.end_macro
################################################################################



################################################################################
# Descrição: Esta macro coloca um argumento em $a0 e chama o procedimento 
#            procedimento_escreve_mnemonico. $a0 guarda o endereço da variável
#            que contém o campo opcode da instrução
# Uso      : escreve_mneumonico(campo_opcode)
#            campo_opcode é um rótulo (com o endereço) com o endereço da variável
#            que guarda o opcode da instrução
.macro escreve_mnemonico(%opcode)
.text
            la    $a0, %opcode
            jal   procedimento_escreve_mnemonico
.end_macro
################################################################################


################################################################################
.macro escreve_registrador(%reg)
# Descrição: Esta macro coloca um argumento em $a0 e chama o procedimento 
#            procedimento_escreve_registrador. $a0 guarda o endereço da variável 
#            com o endereço de um registrador(um valor numérico entre 0 e 31)
# Uso      : escreve_registrador(campo_rs)
#            campo_rs é um rótulo (com o endereço) com o endereço da variável 
#            que armazena o endereço de um registrador 
#   
.text
            la    $a0, %reg
            lw    $a0, 0($a0)
            jal   procedimento_escreve_registrador
.end_macro
################################################################################


################################################################################
# Descrição: Esta macro coloca um argumento em $a0 e chama o procedimento 
#            procedimento_escreve_valor_immediato16. $a0 guarda o endereço da 
#            variável que contém o campo com um valor imediato de 16 bits
# Uso      : escreve_valor_imediato16(campo_imm16)
#            campo_imm16 é um rótulo (com o endereço) com o endereço da variável
#            que armazena um valor imediato de 16 bits (em complemento de 2)
.macro escreve_valor_imediato16(%imm)
.text
            la    $a0, %imm
            lw    $a0, 0($a0)
            jal   procedimento_escreve_valor_immediato16
.end_macro
################################################################################


################################################################################
# Descrição: Esta macro coloca um argumento em $a0 e chama o procedimento 
#            procedimento_escreve_valor_immediato16_semsinal. $a0 guarda o 
#            endereço da variável que contém o campo com um valor imediato de 
#            16 bits
# Uso      : escreve_valor_imediato16_semsinal(campo_imm16)
#            campo_imm16 é um rótulo (com o endereço) com o endereço da variável
#            que armazena um valor imediato de 16 bits sem sinal
.macro escreve_valor_imediato16_semsinal(%reg)
.text
            la    $a0, %reg
            lw    $a0, 0($a0)
            jal   procedimento_escreve_valor_immediato16_semsinal
.end_macro
################################################################################
 
