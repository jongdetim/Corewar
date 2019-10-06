/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar.c                     	                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_vm(t_vm *vm, int argc, char **argv)
{
	vm->champion_count = 0;
	vm->champions = NULL;
	vm->dump_flag = 0;
	vm->argc = argc;
	vm->argv = argv;
}

int			main(int argc, char **argv)
{
	t_vm		vm;

	init_vm(&vm, argc, argv);
	check_arguments(&vm);
	init_champions(&vm);
	
	int i = 0;
	while (i < vm.champion_count)
	{
		ft_printf("id = %d, filename = %s\n", vm.champions[i].id, vm.champions[i].filename);
		i++;
	}
	return (1);
}