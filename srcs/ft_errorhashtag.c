/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorhashtag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:43:37 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 19:53:45 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Verify validity of tetriminos by checking it's shape
*/

int	ft_errorhashtag(char *s)
{
	int	i;
	int	y;

	i = -1;
	y = 0;
	while (s[++i] != '\0')
		if (s[i] == '#')
			y++;
	if (y != 4)
		return (1);
	i = -1;
	y = 0;
	while (s[++i])
		if (s[i] == '#')
		{
			if (i > 0)
				y += (s[i - 1] == '#' ? 1 : 0);
			y += (s[i + 1] == '#' ? 1 : 0);
			if (i > 4)
				y += (s[i - 5] == '#' ? 1 : 0);
			if (i + 5 < ((int)ft_strlen(s)))
			y += (s[i + 5] == '#' ? 1 : 0);
		}
	if (y != 6 && y != 8)
		return (1);
	return (0);
}
