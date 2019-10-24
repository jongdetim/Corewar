/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lfork.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:57:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:20:42 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		lfork_op(t_vm *vm, t_cursor *cursor)
{
	t_cursor		*fork;
	int				position;

	position = cursor->operation.arg[0] + cursor->position;
	position = ft_modulo(position, MEM_SIZE);
	fork = duplicate_cursor(cursor, position);
	add_to_cursor_list(vm, fork);
	return ;
}
