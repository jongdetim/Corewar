/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lld.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:50:59 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/16 20:12:49 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		lld(t_vm *vm, t_cursor *cursor)
{
	int value;

	value = cursor->operation.arg[0];
	cursor->reg[cursor->operation.arg[1] - 1] = value;
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
