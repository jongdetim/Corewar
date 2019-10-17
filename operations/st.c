/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set.c                               	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		st(t_vm *vm, t_cursor *cursor)
{
	int	first_arg;
	int second_arg;
	int	i;
	int buff;

	first_arg = cursor->operation.arg[0];
	second_arg = cursor->operation.arg[1];
	if (cursor->operation.check[1] == REG_CODE)
		cursor->reg[second_arg - 1] = cursor->reg[first_arg - 1];
	else if (cursor->operation.check[1] == IND_CODE)
	{
		i = 0;
		buff = cursor->reg[first_arg - 1];
		while (i < 4)
		{
			vm->memory[modulo(cursor->position + (modulo(second_arg,IDX_MOD))
												+ i, MEM_SIZE)] = (char)buff;
			buff >> 8;
			i++;
		}
	}
}
