/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   longfork.c                           	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		lfork_op(t_vm *vm, t_cursor *cursor)
{
	t_cursor		*fork;
	int				position;

	position = cursor->operation.arg[0] + cursor->position;
	position = modulo(position, MEM_SIZE);
	fork = duplicate_cursor(cursor, position);
	add_to_cursor_list(vm, fork);
	return ;
}