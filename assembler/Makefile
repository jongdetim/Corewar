# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/04 13:29:01 by jheeresm       #+#    #+#                 #
#    Updated: 2019/10/29 15:30:15 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ASM_NAME =		asm

ASM_FILES =		main parser tools tokens analyze analyze_help check_arguments \
				endian output get_coding_oct output_help

ASM_SRC =		$(ASM_FILES:%=srcs/%.c)

LIBFT =			libft/libft.a

ASM_OBJ =		$(ASM_SRC:.c=.o)

FLAGS =			-g -Wall -Wextra -Werror

all : $(ASM_NAME)

$(ASM_NAME) : $(ASM_OBJ) $(LIBFT)
				@ gcc $(FLAGS) -o $@ $(ASM_OBJ) -L ./libft/ -lft
				@ cp -r ./asm ../.
				@ echo "\033[32mASSEMBLER READY\033[0m"

$(LIBFT) :
	 			@ make -C ./libft/

srcs/%.o : srcs/%.c includes/assembler.h includes/op.h
				@ gcc $(FLAGS) $< -c -o $@

clean :
				@ make clean -C ./libft/ && rm -f $(ASM_OBJ)

fclean :
				@ make fclean -C ./libft/ && rm -f $(ASM_NAME) && \
				rm -f $(ASM_OBJ)

re : fclean all

.PHONY: clean fclean all re
