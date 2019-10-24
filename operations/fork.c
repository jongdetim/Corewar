/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                              	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			copy_cursor_variables(t_cursor *cursor, t_cursor *fork)
{
	int			i;

	i = 0;
	while (i < REG_NUMBER)
	{
		fork->reg[i] = cursor->reg[i];
		i++;
	}
	fork->carry = cursor->carry;
	fork->opcode = 0;
	fork->last_live = cursor->last_live;
	fork->wait_cycles = 0;
	reset_operation(fork);
	fork->next = NULL;
	return ;
}

t_cursor		*duplicate_cursor(t_cursor *cursor, int position)
{
	t_cursor 		*fork;
	static int		id = 4;

	fork = malloc(sizeof(t_cursor));
	copy_cursor_variables(cursor, fork);
	fork->id = id;
	fork->position = position;
	id += 1;
	return (fork);
}

void			fork_op(t_vm *vm, t_cursor *cursor)
{
	t_cursor		*fork;
	int				position;

	position = (cursor->operation.arg[0] % IDX_MOD) + cursor->position;
	position = modulo(position, MEM_SIZE);
	fork = duplicate_cursor(cursor, position);
	add_to_cursor_list(vm, fork);
	return ;
}