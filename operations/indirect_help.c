/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indirect_help.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/10/17 19:01:34 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			get_indirect_arg_idx_mod(t_vm *vm, t_cursor *cursor)
{
	int			i;
	int			position;

	i = 0;
	while (i < 4)
	{
		if (cursor->operation.check[i] == 3)
		{
			position = cursor->position += cursor->operation.arg[i] % IDX_MOD;
			position = ft_modulo(position, MEM_SIZE);
			cursor->operation.arg[i] = get_value_at_address(vm, position);
		}
		i++;
	}
	return ;
}

void			get_indirect_arg_mem_size(t_vm *vm, t_cursor *cursor)
{
	int			i;
	int			position;

	i = 0;
	while (i < 4)
	{
		if (cursor->operation.check[i] == 3)
		{
			position = cursor->position += cursor->operation.arg[i] % IDX_MOD;
			position = ft_modulo(position, MEM_SIZE);
			cursor->operation.arg[i] = get_value_at_address(vm, position);
		}
		i++;
	}
	return ;
}
