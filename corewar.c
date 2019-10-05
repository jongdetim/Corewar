#include "corewar.h"

void		display_help(void)
{
	ft_printf("Usage: 	./corewar champion1.cor champion2.cor champion3.cor \n");
	ft_printf("	--help for flags.\n");
	return ;
}

int			main(int argc, char **argv)
{
	check_arguments(argc, argv);

	return (1);
}