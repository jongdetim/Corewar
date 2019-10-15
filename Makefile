# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/04 13:29:01 by jheeresm       #+#    #+#                 #
#    Updated: 2019/10/14 18:53:39 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CW_NAME =		corewar

CW_FILES =		main check_arguments input_error init_champion exec_cursor_list read_operation \
				save_arguments init_cursors load_champs endianness dump_flag operations/fork

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
				@ make clean -C ./libft/ && rm -f $(CW_OBJ)

fclean :
				@ make fclean -C ./libft/ && rm -f $(CW_NAME) && \
				rm -f $(CW_OBJ)

re : fclean all

.PHONY: clean fclean all re
