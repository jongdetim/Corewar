#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmeulenb <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 15:06:49 by tmeulenb      #+#    #+#                  #
#    Updated: 2019/11/04 15:06:50 by tmeulenb      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

CW_NAME =		corewar

ASM_NAME = 		asm

DIS_ASM_NAME =	dis_asm


all :
				@ make dis_asm && make asm && make corewar

corewar :
				@ make -C ./virtual_machine

asm :
				@ make -C ./assembler

dis_asm :
				@ make -C ./disassembler

test :
				@ cp -r ./resources/test_asm ./assembler
				@ cp -r ./resources/test_dis_asm ./disassembler
				
clean :
				@ make clean -C ./virtual_machine
				@ make clean -C ./assembler
				@ make clean -C ./disassembler

fclean :
				@ rm -f dis_asm
				@ rm -f asm
				@ rm -f corewar
				@ make fclean -C ./virtual_machine
				@ make fclean -C ./assembler
				@ make fclean -C ./disassembler

re : fclean all

.PHONY: clean fclean all re corewar asm dis_asm
