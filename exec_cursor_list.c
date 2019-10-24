/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cursor_list.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/10/17 18:55:59 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** SET_OPCODE
** If the cursor already has an opcode and it's still the same,
** it returns (1) and exec_cursor will continue.
** If the opcode read from memory is not valid it will set waitcycles to 0 and
** save value.
** Also it will increase cursor position by 1 and return (0).
** This ends exec_cursor.
** If opcode is correct it will set the opcode and
** set wait_cycles according to opcode
** vm->wait[opcode - 1] is because opcode 1 is wait[0] and so on.
*/

int			set_opcode(t_vm *vm, t_cursor *cursor)
{
	int			opcode;

	opcode = vm->memory[cursor->position];
	if (cursor->opcode == opcode && VALID_OPCODE(opcode))
		return (1);
	if (!VALID_OPCODE(opcode))
	{
		cursor->opcode = opcode;
		cursor->wait_cycles = 0;
		cursor->position = modulo(cursor->position + 1, MEM_SIZE);
		return (0);
	}
	cursor->opcode = opcode;
	cursor->wait_cycles = vm->wait[opcode - 1];
	return (1);
}

void		reset_operation(t_cursor *cursor)
{
	cursor->operation.arg[0] = 0;
	cursor->operation.arg[1] = 0;
	cursor->operation.arg[2] = 0;
	cursor->operation.check[0] = 0;
	cursor->operation.check[1] = 0;
	cursor->operation.check[2] = 0;
	cursor->operation.check[3] = 0;
	return ;
}

/*
** MOVE_TO_NEXT_OPERATION (This might be good only if operation is succesfull)
** jump is the amount of bytes the cursor will jump.
** jump is initialized at 2 because of opcode and encoding byte.
** It will go into loop and check the kind of argument with operation.check[4]
** It will add the right byte value depending on the type of argument.
** If there is only 1 argument, it will stop after 1 loop
** We will decrease jump by 1 because of missing enc byte (if single arg op)
*/

void		move_to_next_operation(t_vm *vm, t_cursor *cursor)
{
	int			jump;
	int			i;

	jump = 2;
	i = 0;
	while (i < 4)
	{
		if (cursor->operation.check[i] == 1)
			jump += REG_CODE;
		if (cursor->operation.check[i] == 2)
			jump += vm->t_dir[cursor->opcode - 1];
		if (cursor->operation.check[i] == 3)
			jump += IND_SIZE;
		if (is_single_arg_op(cursor))
		{
			jump -= 1;
			break ;
		}
		i++;
	}
	cursor->position = modulo(cursor->position + jump, MEM_SIZE);
	return ;
}

void		exec_operation(t_vm *vm, t_cursor *cursor)
{
	if (cursor->opcode == 1)
		live_op(vm, cursor);
	if (cursor->opcode == 2)
		ld_op(cursor);
	else if (cursor->opcode == 4)
		add_op(cursor);
	else if (cursor->opcode == 5)
		sub_op(cursor);
	else if (cursor->opcode == 6)
		and_op(cursor);
	else if (cursor->opcode == 7)
		or_op(cursor);
	else if (cursor->opcode == 8)
		xor_op(cursor);
	else if (cursor->opcode == 12)
		fork_op(vm, cursor);
}

/*
** EXEC_CURSOR
** If set_opcode returns (0), we stop this function.
** The opcode was wrong at that memory adress.
** If wait cycles > 0, wait cycles -= 1.
** If wait cycles == 0, we read the code and execute it.
** After succesfully executing we go to the next operation and opcode 0
*/

void		exec_cursor(t_vm *vm, t_cursor *cursor)
{
	if (!set_opcode(vm, cursor))
		return ;
	if (cursor->wait_cycles > 0)
		cursor->wait_cycles -= 1;
	else if (cursor->wait_cycles == 0)
	{
		if (read_operation(vm, cursor))
		{
			exec_operation(vm, cursor);
			//ft_printf("exec operation = [%d]\n", cursor->opcode);
			//ft_printf("arg1 = %d, arg2 = %d, arg3 = %d\n", cursor->operation.arg[0], cursor->operation.arg[1], cursor->operation.arg[2]);
		}
		else
			ft_printf("operation, encoding byte or arguments were incorrect\n");
		move_to_next_operation(vm, cursor);
		reset_operation(cursor);
		cursor->opcode = 0;
	}
	return ;
}

/*
** EXEC_CURSOR_LIST
** This function will loop through linked list of cursor every cycle.
** If a cursor's last_live is not -1 (this means it's dead), it will go to exec_cursor.
*/

void		exec_cursor_list(t_vm *vm, t_cursor *cursor)
{
	while (cursor)
	{
		printf("cursor_id = %d, position = %d\n", cursor->id, cursor->position);
		if (cursor->last_live != -1)
			exec_cursor(vm, cursor);
		cursor = cursor->next;
	}
	return ;
}
