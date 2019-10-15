/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setindex.c                         	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		sti(t_vm *vm, t_cursor *cursor)
{
	int	first_arg;
	int second_arg;
	int	third_arg;
	int	i;

	first_arg = cursor->reg[cursor->operation.arg[0] - 1];
	if (cursor->operation.check[1] == T_REG)
		second_arg = cursor->reg[cursor->operation.arg[1] - 1];
	else if (cursor->operation.check[1] == T_DIR)
		second_arg = cursor->operation.arg[1];
	else if (cursor->operation.check[1] == T_IND)
		second_arg = vm->memory[modulo(cursor->position +
		(cursor->operation.arg[1] % IDX_MOD), MEM_SIZE)];
	if (cursor->operation.check[2] == T_REG)
		third_arg = cursor->reg[cursor->operation.arg[2]];
	else if (cursor->operation.check[2] == T_DIR)
		third_arg = cursor->operation.arg[2];
	i = 0;
	while (i < 4)
	{
		vm->memory[modulo(cursor->position +
		((second_arg + third_arg) % IDX_MOD) + i, MEM_SIZE)] = (char)first_arg;
		first_arg >> 8;
		i++;
	}
}
