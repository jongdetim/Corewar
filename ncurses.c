#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void		fill_corewar_header(WINDOW *corewar_header)
{
	mvwprintw(corewar_header, 1, 2, "COREWAR ");
	mvwprintw(corewar_header, 2, 2, "By: Ayundina, Jheersm, Tide-jon and Tmeulenb");
	wrefresh(corewar_header);
	return ;
}

int			main()
{
	WINDOW *memory_display;
	WINDOW *game_variables;
	WINDOW *corewar_header;

	int ch;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	printw("Press F1 to exit");
	refresh();
	memory_display = create_newwin(66, 195, 0, 0);
	corewar_header = create_newwin(10, 50, 0, 196);
	game_variables = create_newwin(56 ,50 ,10 ,196);
	
	char		*memory;
	memory = malloc(sizeof(char) * 4096);
	int i = 0;
	while (i < 4096)
	{
		memory[i] = 0;
		i++;
	}
	int y = 1;
	
	while (y < 65)
	{
		int x = 2;
		//mvprintw(x, y, " ");
		//x += 1;
		while (x < 194)
		{
			mvprintw(y, x, "%.2x ", *memory);
			x += 3;
			memory++;
		}
		y++;
	}
	fill_corewar_header(corewar_header);
	box(memory_display, 0, 0);
	wrefresh(memory_display);
	getch();
	endwin();
	return (0);
}