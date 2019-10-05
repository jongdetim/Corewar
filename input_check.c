/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		input_error(char *arg, int choice)
{
	if (arg)
		ft_printf("Error at argument: \"%s\"\n", arg);
	if (choice == 0)
		ft_printf("Champion can only be .cor file.\n");
	if (choice == 1)
		ft_printf("Incorrect flag. Need help? ./corewar -help.\n");
	if (choice == 2)
		ft_printf("Too many champions (max. 4).\n");
	if (choice == 3)
		ft_printf("Invalid argument. Need help? ./corewar -help\n");
	if (choice == 4)
		ft_printf("No valid number for the flag\n");
	exit(1);
}

int			check_for_champion(char *arg)
{
	char 		*temp;

	temp = arg;
	while (*arg && *arg != '.')
		arg++;
	if (*arg != '.')
		return (0);
	if (*arg == '.' && ft_strncmp(arg, ".cor", 4))
		input_error(temp, 0);
	return (1);
}

void		check_number_for_flag(char **argv, int argc, int i)
{
	int			j;

	j = 0;
	if (i + 1 == argc)
		input_error(argv[i], 4);
	while (argv[i + 1][j])
	{
		if (!ft_isdigit(argv[i + 1][j]))
			input_error(argv[i], 4);
		j++;
	}
	return ;
}

int			check_for_flag(char **argv, int argc, int i)
{
	int			j;

	j = 0;
	if (argv[i][0] != '-')
		input_error(argv[i], 3);
	if (!ft_strcmp("-n", argv[i]))
		check_number_for_flag(argv, argc, i);
	else if (!ft_strcmp("-dump", argv[i]))
		check_number_for_flag(argv, argc, i);
	else
		input_error(argv[i], 1);
	return (1);
}

void		check_arguments(int argc, char **argv)
{
	int				i;
	int				champion_count;

	i = 1;
	champion_count = 0;
	if (argc == 1)
		display_help();
	while (i < argc)
	{
		if (!ft_strcmp("-help", argv[i]))
			display_help();
		else if (check_for_champion(argv[i]))
			champion_count++;
		else if (check_for_flag(argv, argc, i))
			i++;
		i++;
	}
	if (champion_count > 4)
		input_error(NULL, 2);
	return ;
}
