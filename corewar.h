#ifndef COREWAR_H
# define COREWAR_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"

# define NO_CHAMP_AFTER_N_FLAG i + 2 == vm->argc
# define NO_NUMBER_AFTER_FLAG i + 1 == vm->argc

typedef struct 		s_champion
{
	char			*filename;
	char			*name;
	char			*comment;
	int				id;

}					t_champion;

typedef struct 		s_vm
{
	int				argc;
	char			**argv;
	int				champion_count;
	int				dump_flag;
	int				n_flag[4];
	t_champion		*champions;
}					t_vm;

/*
** error.c
*/
void				display_help(void);
void				input_error(char *arg, int choice);

/*
** input_check.c
*/
void				check_arguments(t_vm *vm);

/*
** init_champions.c
*/
void				init_champions(t_vm *vm);

#endif