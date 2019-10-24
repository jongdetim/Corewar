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

/*
** GET_VALUE_AT_ADDRESS
** Reads 4 bytes from a certain position in memory.
** Stores these 4 bytes into an integer.
** The bytes are read as big endian and stored in little endian.
*/

int				get_value_at_address(t_vm *vm, int pos)
{
	int			value;

	value = (int)(vm->memory[MOD(pos)] << 24 | vm->memory[MOD(pos + 1)] << 16 |
				vm->memory[MOD(pos + 2)] << 8 | vm->memory[MOD(pos + 3)]);
	return (value);
}

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
