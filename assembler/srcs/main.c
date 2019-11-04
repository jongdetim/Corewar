/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 19:06:00 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/30 21:43:46 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
**	TEST-FUNCTION to print the tokens
*/

static void	test_tokenlist(t_corewar *data)
{
	t_tokens	*current;

	current = data->tokens;
	while (current != NULL)
	{
		ft_printf("line: %4i token: %10s  value: %10d position: %4d\n",
		current->linenum, current->content, current->value,
		current->position);
		current = current->next;
	}
	ft_printf("total bytes: %d\n", data->total_bytes);
}

static void	check_descriptives(t_corewar *data)
{
	if (data->got_name == 0)
		ft_error("error: no name found");
	if (data->got_comment == 0)
		ft_error("error: no comment found");
}

int			main(int argc, char **argv)
{
	int			fd;
	t_corewar	data;
	int			len;

	if (argc != 2)
		ft_error("usage: ./asm filename.s");
	len = ft_strlen(argv[1]);
	if (len < 2 || argv[1][len - 1] != 's' || argv[1][len - 2] != '.')
		ft_error("usage: ./asm filename.s");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("error: can't open file");
	data.name = (char*)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH);
	data.comment = (char*)ft_memalloc(sizeof(char) * COMMENT_LENGTH);
	data.got_name = 0;
	data.got_comment = 0;
	data.found_first_op = 0;
	parser(&data, fd);
	check_descriptives(&data);
	analyze_tokens(&data);
	check_arguments(data.tokens);
	replace_labels(&data);
	write_output(data, argv[1]);
	test_tokenlist(&data);
	return (0);
}
