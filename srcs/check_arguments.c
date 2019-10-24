/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int			check_for_champion(char *arg)
{
	int			i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '.' && arg[i + 1] == 'c')
			break ;
		i++;
	}
	if (arg[i] != '.')
		return (0);
// ! i would replace this with ft_strcmp, because then it also works in cases like: file.cor.bat.gif :-)
	if (arg[i] == '.' && ft_strncmp(arg + i, ".cor", 4))
		input_error(arg, 0);
	return (1);
}

void		check_number_for_flag(t_vm *vm, int i)
{
	int			j;
	static int	n_flag = 0;

	j = 0;
	if (NO_NUMBER_AFTER_FLAG)
		input_error(vm->argv[i], 4);
	while (vm->argv[i + 1][j])
	{
		if (!ft_isdigit(vm->argv[i + 1][j]))
			input_error(vm->argv[i], 4);
		j++;
	}
	if (!ft_strcmp("-n", vm->argv[i]))
	{
		vm->n_flag[n_flag] = ft_atoi(vm->argv[i + 1]);
		if (!(vm->n_flag[n_flag] >= 1 || vm->n_flag[n_flag] <= 4))
			input_error(vm->argv[i], 4);
		n_flag++;
	}
	if (!ft_strcmp("-dump", vm->argv[i]))
		vm->dump_flag = ft_atoi(vm->argv[i + 1]);
	if (!ft_isint(vm->argv[i + 1], -1) || vm->dump_flag < 0)
		input_error(vm->argv[i], 4);
	return ;
}

int			check_for_flag(t_vm *vm, int i)
{
	if (vm->argv[i][0] != '-')
		input_error(vm->argv[i], 3);
	if (!ft_strcmp("-n", vm->argv[i]))
	{
		check_number_for_flag(vm, i);
		if (NO_CHAMP_AFTER_N_FLAG)
			input_error(vm->argv[i], 5);
	}
	else if (!ft_strcmp("-dump", vm->argv[i]))
		check_number_for_flag(vm, i);
	else
		input_error(vm->argv[i], 1);
	return (1);
}

/*
** CHECK_DUPLICATE_N_FLAGS
*/

void		check_duplicate_n_flags(t_vm *vm)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		if (vm->n_flag[i] > vm->champion_count)
			input_error("-n", 6);
		j = 0;
		while (j < 4)
		{
			if (vm->n_flag[j] == vm->n_flag[i] &&
							vm->n_flag[i] > 0 && i != j)
				input_error("-n", 7);
			j++;
		}
		i++;
	}
	return ;
}

void		check_arguments(t_vm *vm)
{
	int				i;

	i = 1;
	if (vm->argc == 1)
		display_help();
	while (i < vm->argc)
	{
		if (!ft_strcmp("-help", vm->argv[i]))
			display_help();
		else if (check_for_champion(vm->argv[i]))
			vm->champion_count++;
		else if (check_for_flag(vm, i))
			i++;
		i++;
	}
	check_duplicate_n_flags(vm);
	if (vm->champion_count > 4)
		input_error(NULL, 2);
	if (!vm->champion_count)
		input_error(NULL, 2);
	return ;
}
