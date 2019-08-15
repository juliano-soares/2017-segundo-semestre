#*******************************************************************************
# tabelas060.s               Copyright (C) 2017 Giovani Baratto
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


.data

# vetor com alguns mneumonicos, para os opcodes 0x00 a 0x0F
mneumonicos:
            .ascii "Ins R"          # opcode = 0x00
            .ascii "op 01"          # opcode = 0x01
            .ascii "    j"          # opcode = 0x02
            .ascii "  jal"          # opcode = 0x03
            .ascii "  beq"          # opcode = 0x04
            .ascii "  bne"          # opcode = 0x05
            .ascii " blez"          # opcode = 0x06
            .ascii " bgtz"          # opcode = 0x07
            .ascii " addi"          # opcode = 0x08
            .ascii "addiu"          # opcode = 0x09
            .ascii " slti"          # opcode = 0x0A
            .ascii "sltiu"          # opcode = 0x0B
            .ascii " andi"          # opcode = 0x0C
            .ascii "  ori"          # opcode = 0x0D
            .ascii " xori"          # opcode = 0x0E
            .ascii "  lui"          # opcode = 0x0F 


# os endereços (palavras) devem estar alinhadas nos endereços de memória, na 
# execução das instruções lw e sw
.align 2                            
# vetor de ponteiros para as strings com os nomes dos registradores do 
# processador MIPS                             
registradores:
            .word r_zero
            .word r_at
            .word r_v0
            .word r_v1
            .word r_a0    
            .word r_a1    
            .word r_a2    
            .word r_a3     
            .word r_t0     
            .word r_t1    
            .word r_t2    
            .word r_t3    
            .word r_t4    
            .word r_t5     
            .word r_t6    
            .word r_t7  
            .word r_s0  
            .word r_s1  
            .word r_s2 
            .word r_s3 
            .word r_s4  
            .word r_s5  
            .word r_s6  
            .word r_s7  
            .word r_t8 
            .word r_t9 
            .word r_k0  
            .word r_k1 
            .word r_gp  
            .word r_sp  
            .word r_fp  
            .word r_ra  

# tabela com as strings com os nomes dos registradores do processador MIPS
registradores_valores:
r_zero:    .asciiz "$zero"
r_at  :    .asciiz "$at"
r_v0  :    .asciiz "$v0"
r_v1  :    .asciiz "$v1"
r_a0  :    .asciiz "$a0"
r_a1  :    .asciiz "$a1"
r_a2  :    .asciiz "$a2"
r_a3  :    .asciiz "$a3"
r_t0  :    .asciiz "$t0"
r_t1  :    .asciiz "$t1"
r_t2  :    .asciiz "$t2"
r_t3  :    .asciiz "$t3"
r_t4  :    .asciiz "$t4"
r_t5  :    .asciiz "$t5"
r_t6  :    .asciiz "$t6"
r_t7  :    .asciiz "$t7"
r_s0  :    .asciiz "$s0"
r_s1  :    .asciiz "$s1"
r_s2  :    .asciiz "$s2"
r_s3  :    .asciiz "$s3"
r_s4  :    .asciiz "$s4"
r_s5  :    .asciiz "$s5"
r_s6  :    .asciiz "$s6"
r_s7  :    .asciiz "$s7"
r_t8  :    .asciiz "$t8"
r_t9  :    .asciiz "$t9"
r_k0  :    .asciiz "$k0"
r_k1  :    .asciiz "$k1"
r_gp  :    .asciiz "$gp"
r_sp  :    .asciiz "$sp"
r_fp  :    .asciiz "$fp"
r_ra  :    .asciiz "$ra"

