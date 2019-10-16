/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loadindex.c                         	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ldi(t_vm *vm, t_cursor *cursor)
{
	int	first_arg;
	int	second_arg;
	int	third_arg;
	int	pos;

	third_arg = cursor->operation.arg[2];
	if (cursor->operation.check[0] == T_REG)
		first_arg = cursor->reg[cursor->operation.arg[0] - 1];
	else
		first_arg = cursor->operation.arg[0];
	if (cursor->operation.check[1] == T_REG)
		second_arg = cursor->reg[cursor->operation.arg[1] - 1];
	else
		second_arg = cursor->operation.arg[1];
	pos = cursor->position + (modulo(first_arg + second_arg, IDX_MOD));
	(cursor->reg[third_arg - 1]) =
	vm->memory[modulo(pos + 3, MEM_SIZE)] << 24 |
	vm->memory[modulo(pos + 2, MEM_SIZE)] << 16 |
	vm->memory[modulo(pos + 1, MEM_SIZE)] << 8 |
	vm->memory[modulo(pos, MEM_SIZE)];
}
