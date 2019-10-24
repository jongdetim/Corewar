/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                             	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** ZJMP
** If carry == 0, don't jump!
** If carry == 1, calculate new position by argument % IDX_MOD + old position.
** modulo is used to calculate the actual position in memory.
*/

void		zjmp_op(t_vm *vm, t_cursor *cursor)
{
	int			position;

	printf("cursor [%d] is trying to exectute zjmp\n", cursor->id);
	if (!cursor->carry)
	{
		move_to_next_operation(vm, cursor);
		return ;
	}
	printf("position before jump = %d\n", cursor->position);
	position = (cursor->operation.arg[0] % IDX_MOD) + cursor->position;
	cursor->position = modulo(position, MEM_SIZE);
	printf("position after jump = %d\n", cursor->position);
	return ;
}
