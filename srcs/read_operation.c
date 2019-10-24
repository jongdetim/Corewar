/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_operation.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** IS_SINGLE_ARG_OP
** determines if the operation has a single argument or not.
** Unfortuntly this did not fit in a #define.
*/

int			is_single_arg_op(t_cursor *cursor)
{
	if (cursor->opcode == 1 || cursor->opcode == 9 ||
	cursor->opcode == 12 || cursor->opcode == 15 || cursor->opcode == 16)
		return (1);
	return (0);
}

/*
** READ_ENCODINGBYTE
** The byte has 8 bits, we read per 2 bits.
** 01 = register, 10 is direct, 11 is indirect.
** We check which on of the above it is and put it in check[x].
** Later on check will be used for:
** - Checking if the argument types are correct for an opcode.
** - Check how much bytes to read for the arguments.
*/

void		read_encodingbyte(t_cursor *cursor, unsigned char byte)
{
	int				i;
	int				x;

	i = 1;
	x = 0;
	while (i < 8)
	{
		if (BYTE(byte, (i - 1)) == 0 && BYTE(byte, i) == 0)
			cursor->operation.check[x] = 0;
		else if (BYTE(byte, (i - 1)) == 0 && BYTE(byte, i) == 1)
			cursor->operation.check[x] = 1;
		else if (BYTE(byte, (i - 1)) == 1 && BYTE(byte, i) == 0)
			cursor->operation.check[x] = 2;
		else if (BYTE(byte, (i - 1)) == 1 && BYTE(byte, i) == 1)
			cursor->operation.check[x] = 3;
		ft_printf("[%d]", cursor->operation.check[x]);
		x++;
		i += 2;
	}
	ft_printf("\n");
	return ;
}

/*
** RIGHT_ENCODING_FOR_OP
** This function will compare the arguments we got in read_encodingbyte
** with the actual possible arguments for every opcode defined in the header.
** Return (1) means it is correct. Return (0) means incorrect,
*/

int			right_encoding_for_op(int operation, int *check)
{
	if ((operation == 1 && CHECK_LIVE(check)) ||
	(operation == 2 && CHECK_LD(check)) ||
	(operation == 3 && CHECK_ST(check)) ||
	(operation == 4 && CHECK_ADD(check)) ||
	(operation == 5 && CHECK_SUB(check)) ||
	(operation == 6 && CHECK_AND(check)) ||
	(operation == 7 && CHECK_OR(check)) ||
	(operation == 8 && CHECK_XOR(check)) ||
	(operation == 9 && CHECK_ZJMP(check)) ||
	(operation == 10 && CHECK_LDI(check)) ||
	(operation == 11 && CHECK_STI(check)) ||
	(operation == 12 && CHECK_FORK(check)) ||
	(operation == 13 && CHECK_LLD(check)) ||
	(operation == 14 && CHECK_LLDI(check)) ||
	(operation == 15 && CHECK_LFORK(check)) ||
	(operation == 16 && CHECK_AFF(check)))
		return (1);
	return (0);
}

/*
** READ_AND_CHECK_ENCODINGBYTE
** If the operation has a single argument, we return (1).
** This means the read was 'succesfull'.
** We read the encoding byte and put the type of arguments in a int[4].
** int[i] == 1 > register, int[i] == 2 > direct, int[i] == 3 > indirect.
** We match the type of arguments against the
** possible arguments types for the opcode.
** These argument types are defined in the header for all 16 operations.
** If the arguments are not correct, we return (0).
*/

int			read_and_check_encoding(t_cursor *cursor, unsigned char byte)
{
	if (is_single_arg_op(cursor))
		return (1);
	read_encodingbyte(cursor, byte);
	if (!right_encoding_for_op(cursor->opcode, cursor->operation.check))
		return (0);
	return (1);
}

/*
** READ_OPERATION
** Read_and_check_encoding will check if encodingbyte matches opcode.
** If it is not, the return is (0) and
** the operation is not going to be executed and we skip to next operations.
**
** Check_and_save_arguments will read the arguments from memory and
** store them in struct operation.
** If an argument is incorrect,
** the return is (0) and the operation will also not be executed.
** If the arguments are CORRECT,
** it will return (1) with the proper arguments set into struct operation.
*/

int			read_operation(t_vm *vm, t_cursor *cursor)
{
	if (!read_and_check_encoding(cursor, vm->memory[cursor->position + 1]))
		return (0);
	if (!save_arguments(vm, cursor))
		return (0);
	return (1);
}
