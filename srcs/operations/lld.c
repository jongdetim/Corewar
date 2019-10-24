/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lld.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:50:59 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:19:55 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void		lld(t_cursor *cursor)
{
	int value;

	value = FIRST_ARG;
	cursor->reg[SECOND_ARG - 1] = value;
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
