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

<<<<<<< HEAD
/*
**	wasn't tested!
**
** vm->game.last_alive_champ = vm->champions[i].id;//champ_reported alive
** vm->champions[i].last_live = vm->game.cycles_to_die;//do we need it?(?:AYU)
**
**	//cursor reported alive in current cycle
**	cursor->last_live = vm->game.cycles;
**
**	//number of lives reported increased
**	vm->game.nbr_live++;
**	//at the end of each cycle nmbr_live will be reset to zero
*/

void    live_op(t_vm *vm, t_cursor *cursor)
=======
//wasn't tested!

void    live(t_vm *vm, t_cursor *cursor)
>>>>>>> 458ad14c041df0c13c2157a2be5de84eea3858f5
{
    int i;

	i = 0;
	while (i < 4)
	{
<<<<<<< HEAD
		if (cursor->operation.arg[0] == vm->champions[i].id)
		{
			vm->game.last_alive_champ = vm->champions[i].id;
		}
		i++;
	}
	cursor->last_live = vm->game.cycles;
	vm->game.nbr_live++;
=======
		if (cursor->operation.arg[0] == vm->champions[i].id)//-?(?:AYU)
		{
			//champ_reported alive
			vm->game.last_alive_champ = vm->champions[i].id;
			vm->champions[i].last_live = vm->game.cycles_to_die;//do we need it?(?:AYU)
		}
		i++;
	}
	//cursor reported alive in current cycle
	cursor->last_live = vm->game.cycles_to_die;
	//cursor->live++;//at the end of the cycle if (cursor->live == 0){delete cursor} (?:AYU)
	//number of lives reported increased
	vm->game.nbr_live++;
	//at the end of each cycle nmbr_live will be reset to zero
>>>>>>> 458ad14c041df0c13c2157a2be5de84eea3858f5
}
