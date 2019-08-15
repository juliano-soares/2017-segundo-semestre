#*******************************************************************************
# exercicio060.s               Copyright (C) 2017 Giovani Baratto
# This program is free software under GNU GPL V3 or later version
# see http://www.gnu.org/licences
#
# Autor: Giovani Baratto (GBTO) - UFSM - CT - DELC
# e-mail: giovani.baratto@ufsm.br
# versão: 0.1
# Descrição: Converte um conjunto de instruções em linguagem de máquina para 
#            instruções em linguagem de montagem
# Documentação:
# Assembler: MARS
# Revisões:
# Rev #  Data           Nome   Comentários
# 0.1    06/10/2017     GBTO   versão inicial 
#*******************************************************************************
#        1         2         3         4         5         6         7         8
#2345678901234567890123456789012345678901234567890123456789012345678901234567890
#           M     O                 #

.include "macros060.s"              # inclua o arquivo macros060.s neste arquivo
.include "tabelas060.s"             # inclua o arquivo tabelas060.s neste arquivo

.text
.globl      main

################################################################################
main:
# Procedimento principal do programa. Este procedimento lê um conjunto de 
# intruções em linguagem de máquina e escreve a correspondente instrução em
# linguagem de montagem. Foi atribuído o valor 0x00400000 para o endereço da
# primeira instrução a ser decodificada.
#
#  Retorno: O programa retorna 0, indicando que foi executado com sucesso
#
#  Variáveis internas:
#           $s0: armazena a instrução que está sendo processada
################################################################################
# prólogo
# corpo do procedimento
            imprime_string("Endereço   Código     Instrução\n")
laco_instrucoes:
            leia_instrucao(instrucoes) # leia uma instrução da tabela de instruções
            beq   $v1, $zero, fim_programa # se $v1=0 não existem mais instruções
            move  $s0, $v0          # movemos a instrução para o registrador $s0
            jal   escreve_endereco  # escrevemos o endereço da instrução
            imprime_espaco()
            move  $a0, $s0          # $a0 guarda a instrução a ser processada
            jal   escreve_instrucao_linguagem_maquina
            imprime_espaco()
            move  $a0, $s0          # $a0 guarda a instrução a ser processada
            jal   encontre_campos_instrucao # extraimos os campos da instrução em $a0
            jal   escreve_instrucao # escrevemos a instrução
            jal   incrementa_endereco
            j     laco_instrucoes   # busque a próxima instrução para ser processada
fim_programa:
# epílogo   
            li    $v0, SERVICO_TERMINA_PROGRAMA # serviço para terminar o programa
            li    $a0, PROGRAMA_EXECUTADO_SUCESSO # retornamos com um código indicando sucesso
            syscall                 # realizamos uma chamada ao sistema
################################################################################


################################################################################
escreve_instrucao_linguagem_maquina:

# Descrição: Este procedimento escreve uma string hexadecimal (uma palavra de
# 4 bytes) da isntrução em linguagem de máquina.

# Argumentos:
#           $a0: instrução em liguagem de máquina (4 bytes)
# Retorno:
#           Não há
################################################################################
# prólogo
# corpo do procedimento
            # usamos um serviço do sistema para imprimir a instrução como um 
            # número hexadecimal
            li   $v0, SERVICO_IMPRIME_NUMERO_HEXADECIMAL # escolhemos o serviço
            syscall                 # fazemos a chamada ao seviço SERVICO_IMPRIME_NUMERO_HEXADECIMAL
# epílogo   
            jr   $ra                # retornamos ao procedimento chamador
################################################################################


################################################################################
procedimento_leia_instrucao:

# Este procedimento lê uma instrução da tabela instrucoes
#
# Argumentos:
#           $a0: endereço da tabela com as instruções que serão processadas
#
# Retorno:
#           $v0: instrução lida da tabela de instrucoes
#           $v1: retorna 0 se não existem mais instruções a serem processadas.
#                retorna 1 quando uma nova instrução for lida da tabela instrucoes
################################################################################
# prólogo
# corpo do procedimento
            # $v1 = 0 -> indica que não existe instrução a ser processada
            li    $v1, 0
            # carregamos o número da instrução a ser processada (0 a 15)
            la    $t0, instrucao    # carregamos o endereço da variável instrucao
            lw    $t0, 0($t0)       # carregamos o valor da variável instrucao
            # se o número da instrução é maior que 15, terminaram as instruções
            slti  $t1, $t0, NUMERO_INSTRUCOES # $t1 = 1 se existe instrução a ser processada
            beq   $t1, $zero, fim_leia_instrucao # se terminaram instruções vá para fim_leia_instrucao
leia_instrucao_memoria:            
            li    $v1, 1            # $v1=1 indica que existe uma instrução a ser processada
            sll   $t2, $t0, 2       # deslocamento $t2 = 4 * índice (número da instrução)
            addu  $t3, $t2, $a0     # $t1 é o endereço efetivo da instrução no vetor de instruções
            lw    $v0, 0($t3)       # carregamos a instrução a ser executada
            addi  $t0, $t0, 1       # incrementamos o número da instrução a ser processada
            la    $t1, instrucao    # armazenamos na variável instrucao
            sw    $t0, 0($t1)       #
fim_leia_instrucao:
# epílogo
            jr    $ra               # retornamos ao procedimento chamador
################################################################################            


################################################################################
encontre_campos_instrucao:

# Este procedimento extrai os todos os campos de uma instrução e armazena em
# variáveis (campo_opcode, campo_rs etc)

# Argumentos
#           $a0: instrução a ser processada
#
# Valores de retorno:
#           Este procedimento não retorna nenhum valor
################################################################################
# prólgo
            addiu $sp, $sp, -8      # ajustamos a pilha para receber 2 itens
            sw    $a0, 4($sp)       # armazenamos $a0 (instrução) na pilha
            sw    $ra, 0($sp)       # armazenamos o endereço de retorno
# corpo do procedimento            
            # extraimos os campos da instrução
            #                      endereço da variável, 
            #                      |             bit mais significativo do campo,
            #                      |             |    bit menos significativo do campo
            #                      v             v    v
            extrai_campo_instrucao(campo_opcode, 31, 26)
            extrai_campo_instrucao(campo_rs,     25, 21)
            extrai_campo_instrucao(campo_rt,     20, 16)
            extrai_campo_instrucao(campo_rd,     15, 11)
            extrai_campo_instrucao(campo_shamt,  10,  6)
            extrai_campo_instrucao(campo_funct,   5,  0)
            extrai_campo_instrucao(campo_imm16,  15,  0)
            extrai_campo_instrucao(campo_imm26,  25,  0)
# epílogo            
            lw    $ra, 0($sp)       # restauramos o endereço de retorno
            addiu $sp, $sp, 8       # restauramos a pilha
            jr    $ra               # retornamos ao procedimento chamador
################################################################################


################################################################################
procedimento_extrai_campo_instrucao:

# Este procedimento extrai o campo contido entre os bits em $a2 e $a3 e guarda
# na variável com o endereço em $a1

# argumentos:
#           $a0: instrução 
#           $a1: endereço da variável que guarda o campo extraido
#           $a2: bit mais significativo do campo
#           $a3: bit menos significativo do campo
#
# retorno:
#           $v0: campo extraido da instrução
################################################################################
# prólogo
# corpo do procedimento
            # deslocamos a instrução para a esquerda, eliminando os campos 
            # indesejáveis à direita do campo a ser isolado
            li    $t0, BIT_MAIS_SIGNIFICATIVO 
            sub   $t1, $t0, $a2     # calculamos o número de bits a deslocar
            sllv  $a0, $a0, $t1     # realizamos um deslocamento lógico para a esquerda
            # deslocamos para a direita a instrução, eliminando os campos 
            # indesejáveis à direita do campo a ser isolado e colocando este campo
            # nos bits menos significativos
            add   $t1, $t1, $a3     # calculamos o número de bits a deslocar
            srlv  $v0, $a0, $t1     # realizamos um deslocamento lógicos para a direita
            # armazenamos o campo na variável com endereço em $a1
            sw    $v0, 0($a1)      
# epílogo
            jr    $ra               # retornamos ao procedimento chamador
################################################################################


################################################################################
escreve_instrucao:

# Este procedimento escreve uma instrução no formato <mneumônicos> <parâmetros>
# O procedimento utiliza a variável campo_opcode para chamar um procedimento
# para escrever a correspondente instrução
################################################################################
# prologo
            addiu $sp, $sp, -4      # ajustamos a pilha para receber um item
            sw    $ra, 0($sp)       # armazenamos o endereço de retorno
# corpo do procedimento            
            la    $t0, tabela_procedimentos # carregamos a tabela com os endereços dos procedimentos
            la    $t1, campo_opcode # carregamos o opcode da instrução
            lw    $t1, 0($t1)
            # verificamos pelo opcode se a instrução pode ser processada
            # se opcode está entre 0 e 15, processamos a instrução, senão emitimos
            # uma mensagem de erro
            slti  $t2, $t1, 16      # $t2 = 1 se 0<$t1<15
            bne   $t2, $zero, executa_escreve_instrucao
            imprime_string("Instrução desconhecida\n")
            j     fim_escreve_instrucao
executa_escreve_instrucao:
            # Usando o opcode, escolhemos um endereço da tabela tabela_procedimentos
            sll   $t1, $t1, 2       # 
            addu  $t0, $t0, $t1     #
            lw    $t0, 0($t0)       # carregamos o endereço do procedimento
            jr    $t0               # chamamos o procedimento
# epílogo
fim_escreve_instrucao:
            lw    $ra, 0($sp)       # restauramos o endereço de retorno
            addiu $sp, $sp, 4       # restauramos a pilha     
            jr    $ra               # retornamos ao procedimento chamador
################################################################################            
      

################################################################################            
procedimento_tipoR: 
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução com opcode 0x00 (instrução tipo R). 
#
# To Do:
#           implementar este procedimento
#
# Argumentos:
#           Não há
# Retorno:
#           Não há  
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            imprime_string("Instrução tipoR: Não implementada\n")
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################            
            

            
################################################################################            
procedimento_opcode01:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução com opcode 0x01. 
#
# To Do:
#           implementar este procedimento
#
# Argumentos:
#           Não há
# Retorno:
#           Não há            
################################################################################            
# prologo
            addiu $sp, $sp, -4      # ajusta a pilha para receber 1 item
            sw    $ra, 0($sp)       # armazena na pilha o endereço de retorno
# corpo do procedimento            
            imprime_string("Instrução com opcode 01: instrução nao implementada\n")
# epílogo
            lw    $ra, 0($sp)       # restaura o endereço de retorno
            addiu $sp, $sp, 4       # restaura a pilha        
            jr    $ra               # retorna ao procedimento chamador
################################################################################



################################################################################
procedimento_j:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução j. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            jal imprime_endereco_instrucao_j
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################


################################################################################
imprime_endereco_instrucao_j:
################################################################################            
# prologo
# corpo do procedimento
            # carregamos o valor imediato da instrucao j
            la    $t0, campo_imm26
            lw    $t1, 0($t0)
            # multiplicamos por 4
            sll   $t1, $t1, 2
            # carregamos o endereço da instrução (valor de PC)
            la    $t0, endereco
            lw    $t2, 0($t0)
            # concatenamos os 4 bits mais significativos de PC com os 28 do
            # campo_imm26 delocado de 2 bits para a esquerda
            lui   $t3, 0xf000
            and   $t2, $t2, $t3
            nor   $t3, $t3, $zero
            and   $t1, $t1, $t3
            or    $a0, $t1, $t2
            # imprimimos o endereço
            li    $v0, SERVICO_IMPRIME_NUMERO_HEXADECIMAL
            syscall
# epílogo
            jr    $ra               # retornamos ao procedimento chamador
################################################################################
           
           
################################################################################           
procedimento_jal:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução jal. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ') 
            jal imprime_endereco_instrucao_j
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################




################################################################################
procedimento_beq:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução beq. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ') 
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            imprime_string(" # desvia para o endereço ")
            jal   imprime_endereco_relativo_PC
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################



################################################################################
procedimento_bne:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução bne. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ') 
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            imprime_string(" # desvia para o endereço ")            
            jal   imprime_endereco_relativo_PC
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################



################################################################################
procedimento_blez:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução blez. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ') 
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            imprime_string(" # desvia para o endereço ")            
            jal   imprime_endereco_relativo_PC
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################


################################################################################
procedimento_bgtz:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução bgtz. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ') 
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            imprime_string(" # desvia para o endereço ")            
            jal   imprime_endereco_relativo_PC
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################                  

################################################################################
procedimento_addi:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução addi. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################



################################################################################                  
procedimento_addiu:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução addiu. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################                  

################################################################################
procedimento_slti:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução slti. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################                  

################################################################################
procedimento_sltiu:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução sltiu. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################                  

################################################################################
procedimento_andi:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução andi. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16_semsinal(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################
                  
################################################################################
procedimento_ori:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução ori. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16_semsinal(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################                  



################################################################################
procedimento_xori:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução xori. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_registrador(campo_rs)
            imprime_string(", ")
            escreve_valor_imediato16_semsinal(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################                  



################################################################################
procedimento_lui:
#
# Descrição: Este procedimento imprime o mneumônico e os agrumentos para a 
#            Instrução lui. 
#
# Argumentos:
#           Não há
# Retorno:
#           Não há 
################################################################################            
# prologo
            addiu $sp, $sp, -4
            sw    $ra, 0($sp)
# corpo do procedimento            
            escreve_mnemonico(campo_opcode)
            imprime_caracter(' ')
            escreve_registrador(campo_rt)
            imprime_string(", ")
            escreve_valor_imediato16_semsinal(campo_imm16)
            nova_linha()
# epílogo
            lw    $ra, 0($sp)
            addiu $sp, $sp, 4            
            jr    $ra
################################################################################


################################################################################
escreve_endereco:
# Descrição: Este procedimento faz a leitura da variaável global endereco e 
#            imprime como um valor hexadecimal.
#
# Argumentos:
#           Não há
# Retorno:
#           Não há
################################################################################
# prologo
# corpo do procedimento
            la    $t0, endereco     # carrega o endereço da variável com o endereço da instrução
            lw    $a0, 0($t0)       # carrgea o valor do endereço da instrução a ser decodificada
            li    $v0, SERVICO_IMPRIME_NUMERO_HEXADECIMAL # serviço para impressão hexadecimal
            syscall                 # faz uma chamada ao serviço para imprimir um valor hexadecimal
# epílogo
            jr     $ra              # retorma ao procedimento chamador
################################################################################



################################################################################
incrementa_endereco:
# Descrição: Este procedimento lê a variável endereco e incrementa o seu valor.
#            A variável endereco guarda o endereço atual da instrução que será
#            decodificada. O valor da variável é incrementada por 4.
#
# Argumentos:
#           Não há
# Retorno:
#           Não há
################################################################################
# prologo
# corpo do procedimento
            la     $t0, endereco    # carregamos o endereço da variável endereço
            lw     $t1, 0($t0)      # carregamos o valor de endereco
            addiu  $t1, $t1, 4      # incrementamos o valor da variável por 4
            sw     $t1, 0($t0)      # atualizamos o valor da variável incrementada
# epílogo
            jr     $ra              # retornamos ao procedimento chamador
################################################################################


################################################################################
procedimento_escreve_mnemonico:
# Descrição: Este procedimento escreve o mnemônico para um opcode
#
# Argumentos:
#           Não há
# Retorno:
#           Não há
################################################################################
# prólogo
            addiu $sp, $sp, -4      # ajustamos a pilha para receber um item
            sw    $ra, 0($sp)       # armazenamos o endereço de retorno
# corpo do procedimento        
             la    $t0, mneumonicos # $t0 <- endereço com as strings dos mnemônico
             la    $t1, campo_opcode # $t1 <- endereço da variável que armazena o opcode
             lw    $t1, 0($t1)      # $t1 <- opcode da instrução (age como índice)
             li    $t2, 5           # $t2 <- tamanho de um item no vetor dos mnemônico
             mul   $t1, $t1, $t2    # $t1 <- índice * tamanho_bytes_um_item_vetor
             addu  $t1, $t0, $t1    # $t1 <- endereço efetivo do elemento opcode no vetor mnemônico
             li    $t2, 5           # $t2 <- número de bytes da string no item no vetor mneumonicos
             li    $v0, SERVICO_IMPRIME_CARACTER # usamos um serviço do sistema para imprimir o caracter
loop_escreve_mnemonico:
             lb    $a0, 0($t1)      # $a0 <- um caractere do mneumônico
             syscall                # imprimimos o caractere chamando um serviço do sistema 
             addiu $t2, $t2, -1     # Decrementamos o número de caracteres impresso 
             addiu $t1, $t1, 1      # apontamos para o próximo caractere da string com o mnemônico
             bgtz  $t2, loop_escreve_mnemonico
# epílogo
            lw    $ra, 0($sp)       # restauramos o endereço de retorno
            addiu $sp, $sp, 4       # restauramos a pilha           
            jr $ra                  # retornamos ao procedimento chamador
################################################################################



################################################################################
procedimento_escreve_registrador:
# Descrição: Este procedimento escreve uma string com o nome de um registrador.
#
# Argumentos:
#           $a0: o endereço do registrador (um valor entre 0 e 31)
# Retorno:
#           Não há
################################################################################
# prologo
            addiu $sp, $sp, -4      # ajustamos a pilha para receber um item
            sw    $ra, 0($sp)       # armazenamos o endereço de retorno na pilha
# corpo do procedimento    
            la    $t0, registradores # $t0 <- endereço da tabela com ponteiros para os nomes dos registradores
            sll   $a0, $a0, 2       # $a0 é multiplicado por 4 (o endereço do registrador é usado como índice)
            addu  $t0, $t0, $a0     # $t0 <- endereço efetivo do ponteiro para o nome do registrador
            lw    $a0, 0($t0)       # $t1 endereço da string com o nome do registrador
            li    $v0, SERVICO_IMPRIME_STRING # imprimimos o nome do registrador com um serviço
            syscall                 # chamamos o serviço para imprimir a string com o nome do registrador
# epílogo
            lw    $ra, 0($sp)       # restauramos o endereço de retorno
            addiu $sp, $sp, 4       # restauramos a pilha                      
            jr    $ra               # retornamos ao procedimento chamador
################################################################################



################################################################################
procedimento_escreve_valor_immediato16:
# Descrição: Este procedimento imprime um valor imediato de 16 bits como uma 
#            string hexadecimal com 8 dígitos
#
# Argumentos:
#            $a0: número em complemento de dois de 16 bits. Este procedimento
#            não verifica se os bytes mais significativos são zeros.
# Retorno:
#           Não há
################################################################################
# prólogo
# corpo do procedimento
            andi  $t0, $a0, 0x8000  # verificamos se o número é negativo (bit 15=1)
            beq   $t0, $zero, numero_positivo # se o número é positivo não faça nada
numero_negativo:                    # se o número é negativo, faça a extensão do sinal
            lui   $t0, 0xFFFF       # na extensão do sinal os bits dos 2 bytes mais significativos são uns
            or    $a0, $a0, $t0     # faça os bits mais significativos iguais ao sinal
numero_positivo:
            li    $v0, SERVICO_IMPRIME_NUMERO_HEXADECIMAL # serviço para imprimir o valor imediato       
            syscall	                # chamamos o serviço do sistema para imprimir o valor imediato
# epílogo
            jr    $ra               # retornamos ao procedimento chamador
################################################################################


################################################################################
procedimento_escreve_valor_immediato16_semsinal:
# Descrição: Este procedimento imprime um valor imediato de 16 bits como uma 
#            string hexadecimal com 8 dígitos
#
# Argumentos:
#            $a0: número sem sinal de 16 bits. Este procedimento não verifica se 
#                 os bytes mais significativos são zeros.
# Retorno:
#           Não há
################################################################################
# prólogo
# corpo do procedimento
            li    $v0, SERVICO_IMPRIME_NUMERO_HEXADECIMAL # serviço para imprimir número hexadecimal
            syscall                 # chamamos o serviço do sistema
# epílogo
            jr    $ra               # retornamos ao procedimento chamador
################################################################################


################################################################################
imprime_endereco_relativo_PC:
# Descrição: Este procedimento imprime um endereço, relativo ao valor do PC. Um
#            valor imediato é multiplicado por 4 e somado ao PC+4
#
# Argumentos:
#           Não há
# Retorno:
#           Não há
################################################################################            
# prólogo
# corpo do procedimento
            # carregamos o valor imediato
            la    $t0, campo_imm16  # $t0 <- endereço da variável que armazena o campo imediato da instrução
            lw    $t1, 0($t0)       # $t1 <- campo imediato da instrução
            # extendemos o sinal
            andi  $t2, $t1, 0x8000  # se o número é negativo extenda o sinal com uns
            beq   $t2, $zero, numero_positivo2 # se positivo não faça nada
numero_negativo2:
            lui   $t2, 0xFFFF       # máscara com uns nos bits mais significativos
            or    $t1, $t1, $t2     # faça a extensão do sinal do número negativo
numero_positivo2:
            sll   $t1, $t1, 2       # multiplicamos o valor imediato por 4
            # adicionamos este valor a PC+4
            la    $t0, endereco     # carregamos o endereço de PC  
            lw    $t2, 0($t0)       # $t2 <- PC
            addiu $t2, $t2, 4       # $t2 <- PC + 4
            addu  $a0, $t2, $t1     # $a0 <- (PC+4) + imm16*4
            # imprimimos o valor
            li    $v0, SERVICO_IMPRIME_NUMERO_HEXADECIMAL # serviço para imprimir inteiro hexadecimal
            syscall                 # fazemos uma chamada ao sistema para imprimir inteiro hexadecimal
# epílogo
            jr    $ra               # retornamos ao procedimento chamador
################################################################################


.data
        
.align 2
instrucao: .word 0          # número da instrução que será processada
endereco:  .word 0x00400000 # endereco da instrução. Fazemos o endereço inicial igual a 0x00400000

    
.align 2    
instrucoes: 
.word       0x014b4820      # add $9,$10,$11        1        add $t1, $t2, $t3
            0x0520000e      # bltz $9,0x0000000e    2        bltz $t1, fim
            0x08100010      # j 0x00400040          3        j fim
            0x0c100010      # jal 0x00400040        4        jal fim
            0x1232000b      # beq $17,$18,0x0000000b5        beq $s1, $s2, fim
            0x1485000a      # bne $4,$5,0x0000000a  6        bne $a0, $a1, fim
            0x1ba00009      # blez $29,0x00000009   7        blez $sp, fim
            0x1fc00008      # bgtz $30,0x00000008   8        bgtz $fp, fim
            0x21e9ff9c      # addi $9,$15,0xffffff9c9        addi $t1, $t7, -100
            0x25e9ff9c      # addiu $9,$15,0xffffff910       addiu $t1, $t7, -100
            0x2949ff9c      # slti $9,$10,0xffffff9c11       slti $t1, $t2, -100
            0x2d49ff9c      # sltiu $9,$10,0xffffff912       sltiu $t1, $t2, -100
            0x3149ff00      # andi $9,$10,0x0000ff0013       andi $t1, $t2, 0xFF00
            0x354900ff      # ori $9,$10,0x000000ff 14       ori  $t1, $t2, 0x00FF
            0x39498000      # xori $9,$10,0x0000800015       xori $t1, $t2, 0x8000
            0x3c091234      # lui $9,0x00001234     16       lui  $t1, 0x1234

    
.align 2    
tabela_procedimentos:
.word       procedimento_tipoR      # opcode 00
            procedimento_opcode01   # opcode 01
            procedimento_j          # opcode 02
            procedimento_jal        # opcode 03
            procedimento_beq        # opcode 04
            procedimento_bne        # opcode 05
            procedimento_blez       # opcode 06
            procedimento_bgtz       # opcode 07
            procedimento_addi       # opcode 08
            procedimento_addiu      # opcode 09
            procedimento_slti       # opcode 0A
            procedimento_sltiu      # opcode 0B
            procedimento_andi       # opcode 0C
            procedimento_ori        # opcode 0D
            procedimento_xori       # opcode 0E
            procedimento_lui        # opcode 0F
            

.align 2
campo_opcode:   .space 4 
campo_rs:       .space 4
campo_rt:       .space 4
campo_rd:       .space 4
campo_shamt:    .space 4
campo_funct:    .space 4
campo_imm16:    .space 4
campo_imm26:    .space 4

            

            
