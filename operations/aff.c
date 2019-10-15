/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c        			             	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		aff(t_cursor *cursor)
{
	ft_printf("%c", (char)(cursor->reg[cursor->operation.arg[0]]));
}
