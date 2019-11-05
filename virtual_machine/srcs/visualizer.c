/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualizer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:11:11 by tide-jon       #+#    #+#                */
/*   Updated: 2019/11/04 21:54:52 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		fill_corewar_header(WINDOW *corewar_header)
{
	mvwprintw(corewar_header, 1, 5,
	"   ___                                 \
	 ");
	mvwprintw(corewar_header, 2, 5,
	"  / __\\___  _ __ _____      ____ _ _ __ ");
	mvwprintw(corewar_header, 3, 5,
	" / /  / _ \\| '__/ _ \\ \\ /\\ / / _` | '__|");
	mvwprintw(corewar_header, 4, 5,
	"/ /__| (_) | | |  __/\\ V  V / (_| | |   ");
	mvwprintw(corewar_header, 5, 5,
	"\\____/\\___/|_|  \\___| \\_/\\_/ \\__,_|_|   ");
	mvwprintw(corewar_header, 7, 11,
	"Ana Yundina     Jim heeresma\n\
	   Tim de Jong     Thijs Meulenbelt");
	wrefresh(corewar_header);
	return ;
}

static void		fill_game_variables(WINDOW *game_variables, t_vm *vm)
{
	int	i;

	i = 0;
	mvwprintw(game_variables, 2, 4, "total cycles:");
	mvwprintw(game_variables, 4, 4, "cycles to die:");

	start_color();
	
	while (i < vm->champion_count)
	{
		init_pair(i + 1, i + 1, COLOR_BLACK);
		wattron(game_variables, COLOR_PAIR(i + 1));
		mvwprintw(game_variables, 7 + i * 7, 4, "player");
		mvwprintw(game_variables, 7 + i * 7, 11, ft_itoa(vm->champions[i].id));
		wattroff(game_variables, COLOR_PAIR(i + 1));
		mvwprintw(game_variables, 7 + i * 7, 17, vm->champions[i].name);
		wattron(game_variables, A_ITALIC);
		mvwprintw(game_variables, 8 + i * 7, 4, "\"");
		wprintw(game_variables, vm->champions[i].comment);
		wprintw(game_variables, "\"");
		wattroff(game_variables, A_ITALIC);
		mvwprintw(game_variables, 12 + i * 7, 4, "last live:");
		i++;
	}
	
}

void	update_game_variables(WINDOW *game_variables, t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->champion_count)
	{
		mvwprintw(game_variables, 12 + i * 7, 24, ft_itoa(vm->champions[i].last_live));
		i++;
	}
}

void	update_memory(WINDOW *memory_display, t_vm *vm)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 1;
	while (y < 65)
	{
		x = 2;
		while (x < 194)
		{
			mvwprintw(memory_display, y, x, "%.2x ", vm->memory[i]);
			x += 3;
			i++;
		}
		y++;
	}
	wrefresh(memory_display);
}

void			visualizer(t_vm *vm)
{
	static WINDOW	*memory_display;
	static WINDOW	*game_variables;
	static WINDOW	*corewar_header;

	iwait();

	if (memory_display == NULL)
	{
		initscr();
		cbreak();
		noecho();
		curs_set(0);

		memory_display = newwin(66, 195, 0, 0);
		corewar_header = newwin(10, 50, 0, 196);
		game_variables = newwin(56, 50, 10, 196);

		fill_corewar_header(corewar_header);
		fill_game_variables(game_variables, vm);

		box(memory_display, 0, 0);
	
		box(corewar_header, 0, 0);
		wrefresh(corewar_header);
		box(game_variables, 0, 0);
		wrefresh(game_variables);
	}

	update_memory(memory_display, vm);
	update_game_variables(game_variables, vm);

	mvwprintw(game_variables, 2, 24, ft_itoa(vm->game.cycles));
	mvwprintw(game_variables, 4, 24, ft_itoa(vm->game.cycles_to_die));
	wrefresh(game_variables);
}
