/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   and.c                               	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** AND_OP
** The value at operation.arg[2] will be the registry we save the value in
** after the and, or or xor operation on argument 1 and 2. 
** We save this variables in the variable [registry].
** We do this because if we call get_registry_argument, all the arguments that are of type
** registry will be initialized with the actual value in the registry. This would mean we lose 
** the registry number we have to save the output in.
** We call get_indirect_arg_idx_mod which will check if the arguments are of type indirect. 
** If so, it will % IDX_MOD and read 4 bytes from the address. The value read will be stored
** in the operation.arg[x]. The previous value at operation.arg[x] was the amount of bytes
** we need to look back or forward.
*/

void			and_op(t_vm *vm, t_cursor *cursor)
{
	int			registry;

	registry = cursor->operation.arg[2] - 1;
	get_registry_argument(cursor);
	get_indirect_arg_idx_mod(vm, cursor);
	cursor->reg[registry] =
		cursor->operation.arg[0] & cursor->operation.arg[1];
	printf("argument[1] = %d, argument[2] = %d\n", cursor->operation.arg[0], cursor->operation.arg[1]);
	printf("value at registry[%d] after AND = [%d]\n", registry + 1, cursor->reg[registry]);
	if (cursor->reg[registry] == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	return ;
}
