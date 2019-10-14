/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_champion.c                     	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			check_n_flag_for_id(t_vm *vm, int id)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (vm->n_flag[i] == id)
			return (1);
		i++;
	}
	return (0);
}

void		give_champion_n_flag_id(t_vm *vm, int id)
{
	int			i;

	i = 1;
	while (i < vm->argc)
	{
		if (vm->argv[i] && vm->argv[i][0] - '0' == id)
		{
			vm->champions[id - 1].filename = ft_strdup(vm->argv[i + 1]);
			vm->champions[id - 1].id = -id;
			vm->argv[i + 1] = NULL;
			return ;
		}
		i++;
	}
	return ;
}

void		give_champion_id(t_vm *vm, int id)
{
	int			i;

	i = 1;
	while (i < vm->argc)
	{
		if (vm->argv[i] && ft_strstr(vm->argv[i], ".cor"))
		{
			vm->champions[id - 1].filename = ft_strdup(vm->argv[i]);
			vm->champions[id - 1].id = -id;
			vm->argv[i] = NULL;
			return ;
		}
		i++;
	}
	return ;	
}

void		give_champion_id_and_set_filename(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < vm->champion_count)
	{
		if (check_n_flag_for_id(vm, i + 1))
			give_champion_n_flag_id(vm , i+ 1);
		i++;
	}
	i = 0;
	while (i < vm->champion_count)
	{
		if (!check_n_flag_for_id(vm, i + 1))
			give_champion_id(vm , i + 1);
		i++;
	}
	return ;
}

void		init_champions(t_vm *vm)
{
	int			i;

	i = 0;
	vm->champions = ft_memalloc(sizeof(t_champion) * vm->champion_count);
	give_champion_id_and_set_filename(vm);
	while (i < vm->champion_count)
	{
		vm->champions[i].last_live = 0;
		i++;
	}
	return ;
}
