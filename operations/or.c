/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:57:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:20:42 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			or_op(t_cursor *cursor)
{
	cursor->reg[cursor->operation.arg[2]] =
	cursor->operation.arg[0] | cursor->operation.arg[1];
	if (cursor->reg[cursor->operation.arg[2]] == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	return ;
}
