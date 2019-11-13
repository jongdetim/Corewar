/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/11/12 21:36:27 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** CHECK_NUMBER_FOR_FLAG
** Parses and validates flags.
** Checks if the flag has a number and if that number is valid.
** Stores flag info in vm.
*/

static void	check_number_for_flag(t_vm *vm, int i, t_flag flag)
{
	static int	n_flag = 0;

	if (NO_NUMBER_AFTER_FLAG)
		input_error(vm->argv[i], flag_nmbr);
	if (!ft_isint(vm->argv[i + 1], -1))
		input_error(vm->argv[i + 1], flag_nmbr);
	if (flag == n)
	{
		vm->n_flag[n_flag] = ft_atoi(vm->argv[i + 1]);
		if (!(1 <= vm->n_flag[n_flag] && vm->n_flag[n_flag] <= 4))
			input_error(vm->argv[i], flag_nmbr);
		n_flag++;
	}
	else if (flag == dump)
	{
		if (vm->dump_flag != -1)
			input_error(vm->argv[i], double_dump);
		vm->dump_flag = ft_atoi(vm->argv[i + 1]);
		if (vm->dump_flag < 0)
			input_error(vm->argv[i + 1], flag_nmbr);
	}
}

/*
** CHECK_DUPLICATE_N_FLAGS
*/

static void	check_duplicate_n_flags(t_vm *vm)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		if (vm->n_flag[i] > vm->champion_count)
			input_error("-n", n_too_big);
		j = i + 1;
		while (j < 4)
		{
			if (vm->n_flag[j] == vm->n_flag[i] &&
							vm->n_flag[i] > 0)
				input_error("-n", same_id);
			j++;
		}
		i++;
	}
	return ;
}

static int	check_for_flag(t_vm *vm, int i)
{
	if (vm->argv[i][0] != '-')
		input_error(vm->argv[i], bad_arg);
	if (!ft_strcmp("-n", vm->argv[i]))
	{
		check_number_for_flag(vm, i, n);
		if (NO_CHAMP_AFTER_N_FLAG)
			input_error(vm->argv[i], id_no_champ);
	}
	else if (!ft_strcmp("-dump", vm->argv[i]))
		check_number_for_flag(vm, i, dump);
	else
		input_error(vm->argv[i], bad_arg);
	return (1);
}

static int	check_for_champion(char *arg)
{
	size_t		len;

	len = ft_strlen(arg);
	if (len > 4 && ft_strcmp(arg + len - 4, ".cor") == 0)
		return (1);
	else
		return (0);
}

/*
** CHECK_ARGUMENTS
** Parses the arguments one by one.
** Then does a basic validation (more vaidation in validate chams)
*/

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
		else if (!ft_strcmp("-v", vm->argv[i]))
			vm->verbose = 1;
		else if (!ft_strcmp("-ncurses", vm->argv[i]))
			vm->visualizer = 1;
		else if (check_for_champion(vm->argv[i]))
			vm->champion_count++;
		else if (check_for_flag(vm, i))
			i++;
		else
			input_error(vm->argv[i], bad_flag);
		i++;
	}
	check_duplicate_n_flags(vm);
	if (vm->champion_count < 1 || vm->champion_count > 4)
		input_error(NULL, champ_nmbr);
}
