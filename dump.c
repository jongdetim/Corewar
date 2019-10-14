/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dump.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 15:12:13 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/10/14 15:12:14 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			dump_check(t_vm vm)
{
	if (vm.dump_flag == 0 || vm.game.cycles < vm.dump_flag)
		return (0);
	else
		return (1);
}

void		dump(unsigned char *mem)
{
	int i;

	i = 0;
	ft_putstr("# ");
	while (i < MEM_SIZE)
	{
		ft_printf("%02X", mem[i]);
		if ((i + 1) % 8 == 0)
			ft_putstr(" #\n# ");
		else if ((i + 1) % 4 == 0)
			ft_putchar('	');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
