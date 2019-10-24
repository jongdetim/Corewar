/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:57:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/17 16:20:42 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// display_help should be changed into the actual help.

void		display_help(void)
{
	ft_printf("Usage: 	./corewar champion1.cor ");
	ft_printf("champion2.cor champion3.cor \n");
	ft_printf("	--help for flags.\n");
	return ;
}

void		input_error(char *arg, int choice)
{
	if (arg)
		ft_printf("Error at argument: \"%s\"\n", arg);
	if (choice == 0)
		ft_printf("Champion can only be .cor file.\n");
	if (choice == 1)
		ft_printf("Incorrect flag. Need help? ./corewar -help.\n");
	if (choice == 2)
		ft_printf("Wrong amount of champions (min. 1 | max. 4).\n");
	if (choice == 3)
		ft_printf("Invalid argument. Need help? ./corewar -help\n");
	if (choice == 4)
		ft_printf("No valid number for the flag.\n");
	if (choice == 5)
		ft_printf("No champion argument to give id to.\n");
	if (choice == 6)
		ft_printf("N is higher than the amount of champions.\n");
	if (choice == 7)
		ft_printf("Same id used twice.\n");
	exit(1);
}
