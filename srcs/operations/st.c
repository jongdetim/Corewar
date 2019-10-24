/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 19:31:43 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/24 22:23:37 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void		st_op(t_vm *vm, t_cursor *cursor)
{
	int	first_arg;
	int second_arg;
	int	i;
	unsigned int buff;

	first_arg = FIRST_ARG;
	second_arg = SECOND_ARG;
	if (cursor->operation.check[1] == REG_CODE)
		cursor->reg[second_arg - 1] = cursor->reg[first_arg - 1];
	else if (cursor->operation.check[1] == IND_CODE)
	{
		i = 3;
		buff = cursor->reg[first_arg - 1];
		while (i >= 0)
		{
			vm->memory[ft_modulo(cursor->position + (second_arg % IDX_MOD)
											+ i, MEM_SIZE)] = (char)buff;
			buff = buff >> 8;
			i--;
		}
	}
}
