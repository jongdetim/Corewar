/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                              	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** Operation was read from memory.
** Encoding bytes are stored in cursor->operation->check[0 to 2]
** Argument bytes are stored in cursor->operation->arg[0 to 2]
**
** 1. Updates when cursor last reported alive.
** 2. If cursor's r1 == Argument1, set player and cursor as last reported alive.
*/

/*
**	wasn't tested!
**
** vm->game.last_alive_champ = vm->champions[i].id;//champ_reported alive
**
**	//cursor reported alive in current cycle
**	cursor->last_live = vm->game.cycles;
**
**	//number of lives reported increased
**	vm->game.nbr_live++;
**	//at the end of each cycle nmbr_live will be reset to zero
*/

void    live_op(t_vm *vm, t_cursor *cursor)
{
    int i;

	i = 0;
	while (i < 4)
	{
		if (cursor->operation.arg[0] == vm->champions[i].id)
		{
			vm->game.last_alive_champ = vm->champions[i].id;
			
		}
		i++;
	}
	cursor->last_live = vm->game.cycles;
	vm->game.nbr_live++;
	printf("last_live = cycle[%d]\n", cursor->last_live);
	printf("amount of lives = %d\n", vm->game.nbr_live);
}
