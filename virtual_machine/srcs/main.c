/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/10/24 21:25:39 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		declare_winner(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < vm->champion_count)
	{
		if (vm->champions[i].id == vm->game.last_alive_champ)
		{
			ft_putstr("* ");
			ft_printf("THE WINNER IS: name:    %s\n", vm->champions[i].name);
			ft_putstr("*                ");
			ft_printf("comment: \"%s\"\n", vm->champions[i].comment);
			ft_putstr("*                ");
			ft_printf("id:      %d\n", vm->champions[i].id);
		}
		i++;
	}
	return ;
}

int			main(int argc, char **argv)
{
	t_vm	vm;

	init_vm(&vm, argc, argv);
	check_arguments(&vm);
	init_champions(&vm);
	load_champs(&vm);
	init_cursors(&vm);
	introduce_champions(&vm, vm.champions);
	game(&vm, &vm.game);
	declare_winner(&vm);
	return (1);
}
