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
void    live(t_vm *vm, t_cursor *cursor)
{
   if (cursor->operation.arg[0] == cursor->reg[1])
   {
       //champ_reported alive
       vm->game.last_alive_champ == cursor->reg[1];//r1 == cursor->reg[1]?
   }
   //cursor reported alive in current cycle
   cursor->last_live = vm->game.cycles_to_die;
   //number of lives reported increased
   vm->game.nbr_live++;
   //at the end of each cycle nmbr_live will be reset to zero
   //cursor reported alive
}