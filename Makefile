# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/04 13:29:01 by jheeresm       #+#    #+#                 #
#    Updated: 2019/10/17 19:40:13 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CW_NAME =		corewar

CW_FILES =		main check_arguments input_error init_champion exec_cursor_list \
				read_operation save_arguments init_cursors load_champs \
				endianness dump_flag operations/fork operations/lfork \
				operations/zjmp operations/add operations/aff operations/and \
				operations/ld operations/ldi operations/live operations/lld \
				operations/lldi operations/or operations/st operations/sti \
				operations/sub operations/xor

CW_SRC =		$(CW_FILES:%=%.c)

LIBFT =			libft/libft.a

CW_OBJ =		$(CW_SRC:.c=.o)

FLAGS =			-g -Wall -Wextra -Werror

all : $(CW_NAME)

$(CW_NAME) : $(CW_OBJ) $(LIBFT)
				@ gcc $(FLAGS) -o $@ $(CW_OBJ) -L ./libft/ -lft
				@ echo "\033[32mCorewar READY\033[0m"

$(LIBFT) :
	 			@ make -C ./libft/

%.o : %.c corewar.h
				@ gcc $(FLAGS) $< -c -o $@

clean :
				@ if [ `ls -1 *.o 2>/dev/null | wc -l ` -gt 0 ] || \
				[ `ls -1 libft/*.o 2>/dev/null | wc -l ` -gt 0 ]; then \
				make clean -C ./libft/; \
				rm -f $(CW_OBJ); else\
				echo "\033[33mNOTHING TO CLEAN\033[0m"; fi

fclean :
				@ make fclean -C ./libft/ && rm -f $(CW_NAME) && \
				rm -f $(CW_OBJ)

re : fclean all

.PHONY: clean fclean all re
