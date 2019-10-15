/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load.c                              	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ld_op(t_vm *vm, t_cursor *cursor)
{
	int value;


	if ((char)cursor->opcode & 0b01000000 > 0)
		value = vm->memory[cursor->position +
		modulo(cursor->operation.arg[0], IDX_MOD)];
	else
		value = cursor->reg[cursor->operation.arg[0]];
	cursor->reg[cursor->operation.arg[1]] = value;
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
