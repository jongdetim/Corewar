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

#include "../includes/corewar.h"

// Display help should be rewritten when we are done with the project.
// We need the flags
// We need the usage more explicitly.

void		display_help(void)
{
	ft_printf("Usage: 	./corewar champion1.cor ");
	ft_printf("champion2.cor champion3.cor \n");
	ft_printf("	--help for flags.\n");
	return ;
}

void		input_error(char *arg, t_input_error choice)
{
	if (arg)
		ft_printf("Error at argument: \"%s\"\n", arg);
	if (choice == no_dot_cor)
		ft_printf("Champion can only be .cor file.\n");
	else if (choice == bad_flag)
		ft_printf("Incorrect flag. Need help? ./corewar -help.\n");
	else if (choice == champ_nmbr)
		ft_printf("Wrong amount of champions (min. 1 | max. 4).\n");
	else if (choice == bad_arg)
		ft_printf("Invalid argument. Need help? ./corewar -help\n");
	else if (choice == flag_nmbr)
		ft_printf("No valid number for the flag.\n");
	else if (choice == id_no_champ)
		ft_printf("No champion argument to give id to.\n");
	else if (choice == n_too_big)
		ft_printf("N is higher than the amount of champions.\n");
	else if (choice == same_id)
		ft_printf("Same id used twice.\n");
	else if (choice == double_dump)
		ft_printf("Dump flag used twice\n");
	exit(1);
}
