/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:44:14 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:18:47 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ld_op(t_vm *vm, t_cursor *cursor)
{
	int value;

	get_indirect_arg_idx_mod(vm, cursor);
	value = cursor->operation.arg[0];
	cursor->reg[cursor->operation.arg[1] - 1] = value;
	printf("value at registry[%d]: [%d]\n", cursor->operation.arg[1], cursor->reg[cursor->operation.arg[1] - 1]);
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	return ;
}
