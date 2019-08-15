#*******************************************************************************
# exercicio047.s               Copyright (C) 2017 Giovani Baratto
# This program is free software under GNU GPL V3 or later version
# see http://www.gnu.org/licences
#
# Autor: Giovani Baratto (GBTO) - UFSM - CT - DELC
# e-mail: giovani.baratto@ufsm.br
# versão: 0.1
# Descrição: converte uma palavra para uma string hexadecimal.
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

.text
.globl      main

.eqv        SERVICO_IMPRIME_STRING   4  
.eqv        SERVICO_TERMINA_PROGRAMA 17

################################################################################
main:
# procedimento principal
################################################################################
# convertemos $a0 para uma string hexadecimal armazenada que é armazenada em
# uma variável com pelo menos 11 bytes
            # carregamos em $a0 o valor de teste 0x1234ABCD
            # li      $a0, 0x1234ABCD 
            lui   $a0, 0x1234             # $a0 <- 0x12340000
            ori   $a0, $a0, 0xABCD       # $a0 <- 0x1234ABCD
            # carregamos em $a1 o endereço do buffer
            la    $a1, buffer             # $a1 <- endereço do buffer
            jal   converte_string_hexadecimal
            # imprimimos a string com o valor hexadecimal
            li    $v0, SERVICO_IMPRIME_STRING   # serviço SERVICO_IMPRIME_STRING
            la    $a0, buffer               # $a0 <- endereço da string que será apresentada
            syscall                         # chamada ao serviço SERVICO_IMPRIME_STRING
            # terminamos o programa
            li    $v0, SERVICO_TERMINA_PROGRAMA # serviço SERVICO_TERMINA_PROGRAMA
            li    $a0, 0                       # programa executado com sucesso
            syscall                         # chamamos o serviço SERVICO_TERMINA_PROGRAMA
################################################################################    


################################################################################
converte_string_hexadecimal:
# Este procedimento converte uma palavra do registrador $a0 para uma string 
# hexadecimal. A string é armazenada em uma variável (string) com pelo menos 11 
# bytes. O endereço da variável é passado para o procedimento pelo registrador 
# $a1.

# Argumentos:
#           $a0 - valor que será convertido para uma string hexadecimal
#           $a1 - endereço da variável buffer que guardará a string hexadecimal 
#                 do valor
################################################################################
# prólogo
# corpo do programa
# armazenamos 0x no buffer para indicar que o número está representado em hexadecimal
            li    $t0, '0'                  # $t0 <- '0'
            sb    $t0, 0($a1)               # armazenamos '0' no buffer
            li    $t0, 'x'                  # $t0 <- 'x'
            sb    $t0, 1($a1)               # armzenamos 'x' no buffer
            addiu $a1, $a1, 2               # ajustamos o ponteiro do buffer
# para cada nibble encontramos o valor hexadeximal.
            lui   $t1, 0xF000               # $t1 = 0xF0000000
            li    $t2, 28                   # $t2 = 28
            la    $t4, hexadecimal          # $t4 = endereço de hexadecimal
laco_converte_string:
            and   $t3, $a0, $t1             # isolamos o nibble
            srlv  $t3, $t3, $t2             # deslocamos para o byte menos significativo da palavra
            add   $t3, $t4, $t3             # $t3 <- endereço do caracter hexadecimal do nibble
            lbu   $t3, 0($t3)               # $t3 <- caracter hexadecimal do nibble
            sb    $t3, 0($a1)               # armazenamos $t3 no buffer
            addiu $a1, $a1, 1               # incrementamos o ponteiro do buffer
            addiu $t0, $t0, -1              # decrementamos o contador $t0
            srl   $t1, $t1, 4               # ajustamos a máscara para o próximo nibble
            # repetimos estas operações até a máscara ser 0x00000000. Quando isto ocorre,
            # todos os nibbles foram verificados
            bne   $t1, $zero, laco_converte_string 
            lb    $zero, 0($a1)             # adicionamos um 0 no final da string
# epílogo
            jr    $ra                       # retornamos ao procedimento chamador
################################################################################


################################################################################
.data

buffer:           .space 11                 # buffer para a string hexadecimal
hexadecimal:      .ascii "0123456789ABCDEF" # vetor com os caracteres hexadecimais
################################################################################
