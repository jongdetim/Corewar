/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:57:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:20:42 by tide-jon      ########   odam.nl         */
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
	fork->id = cursor->id;
	fork->carry = cursor->carry;
	fork->opcode = 0;
	fork->last_live = cursor->last_live;
	fork->wait_cycles = cursor->wait_cycles;
	reset_operation(fork);
	fork->next = NULL;
	return ;
}

t_cursor		*duplicate_cursor(t_cursor *cursor, int position)
{
	t_cursor	*fork;

	fork = malloc(sizeof(t_cursor));
	copy_cursor_variables(cursor, fork);
	fork->position = position;
	return (fork);
}

void			fork_op(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*fork;
	int			position;

	position = (cursor->operation.arg[0] % IDX_MOD) + cursor->position;
	position = ft_modulo(position, MEM_SIZE);
	fork = duplicate_cursor(cursor, position);
	add_to_cursor_list(vm, fork);
	return ;
}
