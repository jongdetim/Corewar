#ifndef COREWAR_H
# define COREWAR_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "op.h"
#include "libft/libft.h"

# define NO_CHAMP_AFTER_N_FLAG i + 2 == vm->argc
# define NO_NUMBER_AFTER_FLAG i + 1 == vm->argc

# define BYTE(byte, i) !!((byte << i) & 0x80)
# define SINGLE_ARG_OP cursor->opcode == 1 || cursor->opcode == 9 || \
					cursor->opcode == 12 || cursor->opcode == 15 || \
					cursor->opcode == 16
# define VALID_OPCODE(x) (x >= 1 && x <= 16)
# define VALID_REG(x) (x >= 1 && x <= REG_NUMBER)

# define CHECK_LIVE(x) (x[0] == 2 && !x[1] && !x[2])
# define CHECK_LD(x) (x[0] > 1 && x[1] == 1 && !x[2])
# define CHECK_ST(x) (x[0] == 1 && (x[1] == 1 || x[1] == 3) && !x)
# define CHECK_ADD(x) (x[0] == 1 && x[1] == 1 && x[2] == 1)
# define CHECK_SUB(x) (x[0] == 1 && x[1] == 1 && x[2] == 1)
# define CHECK_AND(x) (x[0] > 0 && x[1] > 0 && x[2] == 1)
# define CHECK_OR(x) (x[0] > 0 && x[1] > 0 && x[2] == 1)
# define CHECK_XOR(x) (x[0] > 0 && x[1] > 0 && x[2] == 1)
# define CHECK_ZJMP(x) (x[0] == 2 && !x[1] && !x[2])
# define CHECK_LDI(x) (x[0] > 0 && x[1] > 0 && x[1] < 3 && x[2] == 1)
# define CHECK_STI(x) (x[0] == 1 && x[1] > 0 && x[2] > 0 && x[2] < 3)
# define CHECK_FORK(x) (x[0] == 2 && !x[1] && !x[2])
# define CHECK_LLD(x) (x[0] > 1 && x[1] == 1 && !x[2])
# define CHECK_LLDI(x) (x[0] > 0 && x[1] > 0 && x[1] < 3 && x[2] == 1)
# define CHECK_LFORK(x) (x[0] == 2 && !x[1] && !x[2])
# define CHECK_AFF(x) (x[0] == 1 && !x[1] && !x[2])


typedef struct 		s_champion
{
	char			*filename;
	char			*name;
	char			*comment;
	int				id;
	int				size;
}					t_champion;

typedef struct 		s_operation
{
	int				check[4];
	int				arg[3];
}					t_operation;

typedef struct 		s_cursor
{
	int				id;
	int				carry;
	int				opcode;
	int				last_live;
	int				wait_cycles;
	int				position;
	int				reg[16];
	t_operation		operation;
	void			*next;
}					t_cursor;

typedef struct 		s_game
{
	int				cycles;
	int				cycles_to_die;
	int				check;
	int				nbr_live;
}					t_game;

typedef struct 		s_vm
{
	int				argc;
	char			**argv;
	t_champion		*champions;
	t_game			game;
	t_cursor		*cursors;
	unsigned char 	*memory;
	int				champion_count;
	int				dump_flag;
	int				n_flag[4];
	int				wait[16];
	int				t_dir[16];
}					t_vm;

/*
** error.c
*/
void				display_help(void);
void				input_error(char *arg, int choice);

/*
** input_check.c
*/
void				check_argv(t_vm *vm);

/*
** init_champions.c
*/
void				init_champions(t_vm *vm);

/*
** init_cursor.c
*/
int					calc_starting_position(t_vm *vm, int player_id);
void				init_cursors(t_vm *vm);

/*
** exec_cursor.c
*/
void				exec_cursor_list(t_vm *vm, t_cursor *cursor);

/*
** read_operation.c
*/
int					read_operation(t_vm *vm, t_cursor *cursor);

void				load_champs(t_vm *vm);
short				reverse16(short value);
int					reverse32(int value);

int					save_arguments(t_vm *vm, t_cursor *cursor);
#endif


