/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:57:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:20:42 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		aff(t_cursor *cursor)
{
	ft_printf("%c", (char)(cursor->reg[cursor->operation.arg[0] - 1]));
}
