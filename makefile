# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmeulenb <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 15:06:49 by tmeulenb       #+#    #+#                 #
#    Updated: 2019/11/06 23:18:31 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

VM_NAME =		vm

ASM_NAME = 		asm

DIS_ASM_NAME =	dis_asm


all : $(VM_NAME) $(ASM_NAME) $(DIS_ASM_NAME)

vm :
				@ make -C ./virtual_machine
				@ if [ ! -f ./corewar ]; then \
				ln -s ./virtual_machine/corewar ./corewar; fi

asm :
				@ make -C ./assembler
				@ if [ ! -f ./asm ]; then \
				ln -s ./assembler/asm ./asm; fi

dis_asm :
				@ make -C ./disassembler
				@ if [ ! -f ./dis_asm ]; then \
				ln -s ./disassembler/dis_asm ./dis_asm; fi

test :
				@ cp -r ./resources/test_asm ./assembler
				@ cp -r ./resources/test_dis_asm ./disassembler
				
clean :
				@ echo "virtual machine"
				@ make clean -C ./virtual_machine
				@ echo "assembler"
				@ make clean -C ./assembler
				@ echo "disassembler"
				@ make clean -C ./disassembler

fclean :
				@ rm -f dis_asm
				@ rm -f asm
				@ rm -f corewar
				@ echo "virtual machine"
				@ make fclean -C ./virtual_machine
				@ echo "assembler"
				@ make fclean -C ./assembler
				@ echo "disassembler"
				@ make fclean -C ./disassembler

re : fclean all

.PHONY: clean fclean all re corewar asm dis_asm