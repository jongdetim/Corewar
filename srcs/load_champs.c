/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_champs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 15:50:28 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/14 18:31:02 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	faulty_warrior(t_champion *champ)
{
	ft_printf("Error: warrior %s is faulty", champ->filename);
	exit(0);
}

static void	validate_champ(int fd, t_champion *champ)
{
	int	header;
	int	zero;

	read(fd, &header, 4);
	if (header != reverse32(COREWAR_EXEC_MAGIC))
		faulty_warrior(champ);
	champ->name = (char*)ft_memalloc(PROG_NAME_LENGTH);
	read(fd, champ->name, PROG_NAME_LENGTH);
	zero = INT_MAX;
	read(fd, &zero, 4);
	if (zero != 0)
		faulty_warrior(champ);
	read(fd, &(champ->size), 4);
	champ->size = reverse32(champ->size);
	if (champ->size >= CHAMP_MAX_SIZE)
		faulty_warrior(champ);
	champ->comment = (char*)ft_memalloc(COMMENT_LENGTH);
	read(fd, champ->comment, COMMENT_LENGTH);
	zero = INT_MAX;
	read(fd, &zero, 4);
	if (zero != 0)
		faulty_warrior(champ);
}

void		load_champs(t_vm *vm)
{
	int				i;
	int				pos;
	int				fd;
	unsigned char	*buff;
	int				j;

	i = 0;
	while (i < vm->champion_count)
	{
		fd = open(vm->champions[i].filename, O_RDONLY);
		validate_champ(fd, &(vm->champions[i]));
		pos = calc_starting_position(vm, vm->champions[i].id);
		buff = (unsigned char*)ft_memalloc(vm->champions[i].size);
		if (read(fd, buff, vm->champions[i].size) != vm->champions[i].size)
			faulty_warrior(&(vm->champions[i]));
		j = 0;
		while (j < vm->champions[i].size)
		{
			vm->memory[pos] = buff[j];
			pos = (pos + 1) % MEM_SIZE;
			j++;
		}
		free(buff);
		i++;
	}
}
