/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visualizer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:11:11 by tide-jon       #+#    #+#                */
/*   Updated: 2019/11/07 22:47:02 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		fill_corewar_header(WINDOW *corewar_header)
{
	mvwprintw(corewar_header, 1, 5,
	"   ___                                  ");
	mvwprintw(corewar_header, 2, 5,
	"  / __\\___  _ __ _____      ____ _ _ __ ");
	mvwprintw(corewar_header, 3, 5,
	" / /  / _ \\| '__/ _ \\ \\ /\\ / / _` | '__|");
	mvwprintw(corewar_header, 4, 5,
	"/ /__| (_) | | |  __/\\ V  V / (_| | |   ");
	mvwprintw(corewar_header, 5, 5,
	"\\____/\\___/|_|  \\___| \\_/\\_/ \\__,_|_|   ");
	mvwprintw(corewar_header, 7, 0,
	"\tAna Yundina\tJim heeresma\n\tTim de Jong\tThijs Meulenbelt");
	wrefresh(corewar_header);
	return ;
}

static void		fill_game_variables(WINDOW *game_variables, t_vm *vm)
{
	int	i;

	i = 0;

	mvwprintw(game_variables, 2, 17, "*** PLAYING ***");
	mvwchgat(game_variables, 3, 12, 25, A_UNDERLINE, 0, NULL);

	mvwprintw(game_variables, 5, 10, "total cycles:");
	mvwprintw(game_variables, 7, 10, "cycles to die:");
	mvwprintw(game_variables, 9, 10, "number of cursors:");
	mvwchgat(game_variables, 10, 12, 25, A_UNDERLINE, 0, NULL);
	start_color();
	while (i < vm->champion_count)
	{
		init_pair(i + 1, i + 1, -1);
		wattron(game_variables, COLOR_PAIR(i + 1));
		mvwprintw(game_variables, 12 + i * 11, 4, "player");
		mvwprintw(game_variables, 12 + i * 11, 11, ft_itoa(vm->champions[i].id));
		wattroff(game_variables, COLOR_PAIR(i + 1));
		mvwprintw(game_variables, 12 + i * 11, 17, "%.75s", vm->champions[i].name);
		wattron(game_variables, A_DIM);
		mvwprintw(game_variables, 14 + i * 11, 4, "\"");
		wprintw(game_variables, "%.268s", vm->champions[i].comment);
		wprintw(game_variables, "\"");
		wattroff(game_variables, A_DIM);
		mvwprintw(game_variables, 20 + i * 11, 4, "last live:");
		mvwprintw(game_variables, 21 + i * 11, 4, "lives in current period:");
		
		i++;
	}
	
}

void	update_game_variables(WINDOW *game_variables, t_vm *vm)
{
	int	i;

	mvwprintw(game_variables, 5, 33, "%6s", ft_itoa(vm->game.cycles));
	mvwprintw(game_variables, 7, 33, "%6s", ft_itoa(vm->game.cycles_to_die));
	wprintw(game_variables, "    ");
	mvwprintw(game_variables, 9, 33, "%6s", ft_itoa(vm->game.total_cursors));
	wprintw(game_variables, "    ");
	i = 0;
	while (i < vm->champion_count)
	{
		mvwprintw(game_variables, 20 + i * 11, 30, "%6s",
					ft_itoa(vm->champions[i].last_live));
		wprintw(game_variables, "    ");
		i++;
	}
	wrefresh(game_variables);
}

void	update_cursors(WINDOW *memory_display, t_vm *vm)
{
	t_cursor	*current;
	int			x;
	int			y;

	current = vm->cursors;
	while (current != NULL)
	{
		if (current->last_live != -1)
		{
			y = (current->position / 64) + 1;
			x = ((current->position * 3) % 192) + 2;
			mvwchgat(memory_display, y, x, 2, A_STANDOUT, 0, NULL);
		}
		current = current->next;
	}
}

void	update_memory(WINDOW *memory_display, t_vm *vm)
{
	int			i;
	int			y;
	int			x;

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
	update_cursors(memory_display, vm);
	wrefresh(memory_display);
}

void			visualizer(t_vm *vm)
{
	static WINDOW	*memory_display;
	static WINDOW	*game_variables;
	static WINDOW	*corewar_header;
	int key;

	// iwait();
	nodelay(memory_display, 1);
	if (wgetch(memory_display) == 32)
	{
		mvwprintw(game_variables, 2, 17, "*** PAUSED *** ");
		wrefresh(game_variables);
		while (wgetch(memory_display) != 32)
			;
		mvwprintw(game_variables, 2, 17, "*** RUNNING ***");
	}
	while (vm == NULL)
	{
		nodelay(memory_display, 0);
		key = wgetch(memory_display);
		if (key == 113)
		{
			endwin();
			return ;
		}
	}
	if (memory_display == NULL)
	{
		play_audio();
		initscr();
		cbreak();
		noecho();
		curs_set(0);
		use_default_colors();
		memory_display = newwin(66, 195, 0, 0);
		corewar_header = newwin(10, 50, 0, 196);
		game_variables = newwin(56, 50, 10, 196);
		fill_corewar_header(corewar_header);
		fill_game_variables(game_variables, vm);
		box(memory_display, 0, 0);
		wrefresh(corewar_header);
		box(game_variables, 0, 0);
		wrefresh(game_variables);
	}

	update_memory(memory_display, vm);
	update_game_variables(game_variables, vm);
}
