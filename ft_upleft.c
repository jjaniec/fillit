/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upleft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:00:08 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/29 21:58:06 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_left(char *s, int i, int first)
{
	while (s[i])
	{
		if (s[i] == '#' && i % 5 < first)
			first = i % 5;
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			s[i] = '.';
			s[i - first] = '#';
		}
		i++;
	}
}

void	ft_up(char *s, int i, int first)
{
	while (s[i] != '#')
		i++;
	first = 0;
	while (i - 5 >= 0)
	{
		first++;
		i -= 5;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '#' && first > 0)
		{
			s[i] = '.';
			s[i - 5 * first] = '#';
		}
		i++;
	}
}

void	ft_upleft(char *s)
{
	ft_left(s, 0, 5);
	ft_up(s, 0, 0);
}
