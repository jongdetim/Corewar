/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 20:48:03 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/04 16:46:10 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcount(const char *s, char c)
{
	int	i;
	int strcount;

	strcount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c || s[i] == '\n')
			i++;
		while (s[i] != c && s[i] != '\n' && s[i] != '\0')
			i++;
		if (s[i] != '\0' || (s[i - 1] != c && s[i - 1] != '\n'))
			strcount++;
	}
	return (strcount);
}

int		ft_strcount_whitespace(const char *s)
{
	int	i;
	int strcount;

	strcount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (ft_iswhitespace(s[i]) == 1)
			i++;
		while (ft_iswhitespace(s[i]) == 0 && s[i] != '\0')
			i++;
		if (s[i] != '\0' || (ft_iswhitespace(s[i - 1]) == 0))
			strcount++;
	}
	return (strcount);
}
