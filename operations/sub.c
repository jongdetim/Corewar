/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sub.c                               	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** SUB_OP
** At first the value at cursor->operation.arg[x] will be the registry number.
** After we call get_registry_argument this value will be what is inside reg[registry_number].
** That's why we save the registry number of the 3rd argument. We need to know the actual registry
** to put the outcome of (argument1 - argument2) in.
*/

void			sub_op(t_cursor *cursor)
{
	int			registry;

	registry = cursor->operation.arg[2] - 1;
	get_registry_argument(cursor);
	cursor->reg[registry] =
			cursor->operation.arg[0] - cursor->operation.arg[1];
	printf("value at registry[%d] after SUB = [%d]\n", registry + 1, cursor->reg[registry]);
	if (cursor->reg[registry] == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	return ;
}

