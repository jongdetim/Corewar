/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lldi.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:57:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:20:42 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void		lldi(t_vm *vm, t_cursor *cursor)
{
	int	first_arg;
	int	second_arg;
	int	third_arg;
	int	pos;

	third_arg = THIRD_ARG;
	if (cursor->operation.check[0] == REG_CODE)
		first_arg = cursor->reg[FIRST_ARG - 1];
	else
		first_arg = FIRST_ARG;
	if (cursor->operation.check[1] == REG_CODE)
		second_arg = cursor->reg[SECOND_ARG - 1];
	else
		second_arg = SECOND_ARG;
	pos = cursor->position + first_arg + second_arg;
	(cursor->reg[third_arg - 1]) =
	vm->memory[ft_modulo(pos, MEM_SIZE)] << 24 |
	vm->memory[ft_modulo(pos + 1, MEM_SIZE)] << 16 |
	vm->memory[ft_modulo(pos + 2, MEM_SIZE)] << 8 |
	vm->memory[ft_modulo(pos + 3, MEM_SIZE)];
}
