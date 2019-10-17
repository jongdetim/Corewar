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

void		ld_op(t_cursor *cursor)
{
	int value;

	value = cursor->operation.arg[0] % IDX_MOD;
	cursor->reg[cursor->operation.arg[1] - 1] = value;
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
