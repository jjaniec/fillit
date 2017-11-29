/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upleft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:00:08 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/29 13:14:43 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	left(char *s, int i, int first)
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

void	up(char *s, int i, int first)
{
	while (s[i] != '#')
		i++;
	first = 0;
	while (i - 5 > 0)
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

void	upleft(char *s)
{
	left(s, 0, 5);
	up(s, 0, 0);
}

int main()
{
	char	s[30] = "....\n....\n...#\n.###\n";
	printf("%s\n", s);
	upleft(s);
	printf("%s\n", s);
	return 0;
}

