/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/10/14 17:18:48 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** INIT_WAIT_CYCLES
** Set all the wait cycles for the corresponding opcodes (-1).
*/

void		init_wait_cycles(t_vm *vm)
{
	vm->wait[0] = 10;
	vm->wait[1] = 5;
	vm->wait[2] = 5;
	vm->wait[3] = 10;
	vm->wait[4] = 10;
	vm->wait[5] = 6;
	vm->wait[6] = 6;
	vm->wait[7] = 6;
	vm->wait[8] = 20;
	vm->wait[9] = 25;
	vm->wait[10] = 25;
	vm->wait[11] = 800;
	vm->wait[12] = 10;
	vm->wait[13] = 50;
	vm->wait[14] = 1000;
	vm->wait[15] = 2;
	return ;
}

/*
** INIT_T_DIR
** Set all the t_dir sizes for the corresponding opcodes (-1).
*/

void		init_t_dir_and_n_flag(t_vm *vm)
{
	vm->t_dir[0] = 4;
	vm->t_dir[1] = 4;
	vm->t_dir[2] = 4;
	vm->t_dir[3] = 4;
	vm->t_dir[4] = 4;
	vm->t_dir[5] = 4;
	vm->t_dir[6] = 4;
	vm->t_dir[7] = 4;
	vm->t_dir[8] = 2;
	vm->t_dir[9] = 2;
	vm->t_dir[10] = 2;
	vm->t_dir[11] = 2;
	vm->t_dir[12] = 4;
	vm->t_dir[13] = 2;
	vm->t_dir[14] = 2;
	vm->t_dir[15] = 4;
	vm->n_flag[0] = 0;
	vm->n_flag[1] = 0;
	vm->n_flag[2] = 0;
	vm->n_flag[3] = 0;
	return ;
}

void		init_vm(t_vm *vm, int argc, char **argv)
{
	vm->memory = malloc(sizeof(unsigned char) * MEM_SIZE + 1);
	vm->champion_count = 0;
	vm->champions = NULL;
	vm->dump_flag = -1;
	vm->argc = argc;
	vm->argv = argv;
	vm->cursors = NULL;
	vm->game.cycles = 0;
	vm->game.check = 0;
	vm->game.cycles_to_die = CYCLE_TO_DIE;
	vm->game.nbr_live = 0;
	vm->game.last_alive_champ = 0;
	init_wait_cycles(vm);
	init_t_dir_and_n_flag(vm);
	return ;
}

/*
** DECREASE_CYCLES_TO_DIE
** If the amount of lives exected is >= 21. We decrease cycles to die by 50.
** Everytime the amount of lives is < 21, we increment check by 1.
** If check = 10, we decrease cycles to die by 50 and set check back to 0.
** If after decreasing cycles to die, it becomes less than 0, we set it to 1.
** This means there will be just 1 cycle before death.
*/

void		decrease_cycles_to_die(t_game *game, int *cycles)
{
	if (game->nbr_live >= NBR_LIVE)
		game->cycles_to_die -= CYCLE_DELTA;
	else
	{
		if (game->check == 10)
		{
			game->cycles_to_die -= CYCLE_DELTA;
			game->check = 0;
<<<<<<< HEAD
			return ;
=======
>>>>>>> 458ad14c041df0c13c2157a2be5de84eea3858f5
		}
		game->check += 1;
	}
	if (game->cycles_to_die < 0)
		game->cycles_to_die = 1;
	*cycles = game->cycles_to_die;
	return ;
}

/*
** can a player die? (?:AYU)
**	while (cursor)
**	{
**		if (cursor->live == 0)
**		{
**			delete_cursor
**		}
**	}
*/
void		check_dead_cursor_or_players(t_vm *vm)
{
	int			i;
	t_cursor 	*cursor;

	i = 0;
	cursor = vm->cursors;
	while (i < vm->champion_count)
	{
		if (vm->champions[i].last_live <= vm->game.cycles - vm->game.cycles_to_die)
			vm->champions[i].last_live = -1;
		i++;
	}
	while (cursor)
	{
		if (cursor->last_live <= vm->game.cycles - vm->game.cycles_to_die)
			cursor->last_live = -1;
		cursor = cursor->next;
	}
	return ;
}
<<<<<<< HEAD
/*
 ** remove champ check
 */
=======

>>>>>>> 458ad14c041df0c13c2157a2be5de84eea3858f5
int			alive_champ_and_cursor(t_vm *vm)
{
	int			i;
	int			champ;
	int			n_cursor;
	t_cursor	*cursor;

	i = 0;
	n_cursor = 0;
	champ = 0;
	cursor = vm->cursors;
	while (i < vm->champion_count)
	{
		if (vm->champions[i].last_live != -1)
			champ += 1;
		i++;
	}
	while (cursor)
	{
		if (cursor->last_live > vm->game.cycles - vm->game.cycles_to_die)
			n_cursor += 1;
		cursor = cursor->next;
	}
	if (!champ || !n_cursor)
		return (0);
	return (1);
}

void		game(t_vm *vm, t_game *game)
{
	int			cycles_to_die;

	cycles_to_die = game->cycles_to_die;
	while (cycles_to_die && !dump_check(*vm) && alive_champ_and_cursor(vm))
	{
		exec_cursor_list(vm, vm->cursors);
		cycles_to_die -= 1;
		game->cycles += 1;
		if (vm->dump_flag > 0)
			vm->dump_flag -= 1;
		if (cycles_to_die == 0)
		{
			check_dead_cursor_or_players(vm);
			decrease_cycles_to_die(game, &cycles_to_die);
		}
	}
	return ;
}

int			modulo(int a, int b)
{
	int		result;

	if (b < 0)
		return (modulo(-a, -b));
	result = a % b;
	if (result >= 0)
		return (result);
	return (result + b);
}

int			main(int argc, char **argv)
{
	t_vm		vm;

	init_vm(&vm, argc, argv);
	check_arguments(&vm);
	init_champions(&vm);
	load_champs(&vm);
	init_cursors(&vm);
	int i = 0;
	while (i < vm.champion_count)
	{
		ft_printf("id = %d, filename = %s\n", vm.champions[i].id, vm.champions[i].filename);
		i++;
	}
	game(&vm, &vm.game);
	if (dump_check(vm))
		dump_flag(vm.memory);
	return (1);
<<<<<<< HEAD
}
=======
}
>>>>>>> 458ad14c041df0c13c2157a2be5de84eea3858f5
