/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
<<<<<<< HEAD:srcs/operations/operation_help.c
/*   operation_help.c      	             	            :+:    :+:            */
=======
/*   indirect_help.c                                    :+:    :+:            */
>>>>>>> c7f765ce4afe1fd3c5a95e1241bff73cb3f1b1fe:srcs/operations/indirect_help.c
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/10/17 19:01:34 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

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
	while (i < 3)
	{
		if (cursor->operation.check[i] == IND_CODE)
		{
<<<<<<< HEAD:srcs/operations/operation_help.c
			position = cursor->position + (cursor->operation.arg[i] % IDX_MOD);
			position = modulo(position, MEM_SIZE);
=======
			position = cursor->position += cursor->operation.arg[i] % IDX_MOD;
			position = ft_modulo(position, MEM_SIZE);
>>>>>>> c7f765ce4afe1fd3c5a95e1241bff73cb3f1b1fe:srcs/operations/indirect_help.c
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
	while (i < 3)
	{
		if (cursor->operation.check[i] == IND_CODE)
		{
<<<<<<< HEAD:srcs/operations/operation_help.c
			position = cursor->position + (cursor->operation.arg[i] % IDX_MOD);
			position = modulo(position, MEM_SIZE);
=======
			position = cursor->position += cursor->operation.arg[i] % IDX_MOD;
			position = ft_modulo(position, MEM_SIZE);
>>>>>>> c7f765ce4afe1fd3c5a95e1241bff73cb3f1b1fe:srcs/operations/indirect_help.c
			cursor->operation.arg[i] = get_value_at_address(vm, position);
		}
		i++;
	}
	return ;
}

void			get_registry_argument(t_cursor *cursor)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (cursor->operation.check[i] == REG_CODE)
			cursor->operation.arg[i] =
					cursor->reg[cursor->operation.arg[i] - 1];
		i++;
	}
	return ;
}
