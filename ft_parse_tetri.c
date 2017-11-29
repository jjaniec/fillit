/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:47:50 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 19:35:33 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char *s, int a, int b);

char	*ft_parse_tetri(char *s, int nb)
{
	int		i;

	i = 0;
	while (s[i] != '#' && s[i] != '.')
		i++;
	while (s[i])
	{
		if ((s[i] == '#' || s[i] == '.') && nb != 1)
		{
			while (!(s[i] == '\n' && s[i + 1] == '\n') && s[i + 1])
				i++;
			while (s[i] == '\n')
				i++;
			nb--;
		}
		if (nb == 1)
			return (ft_strsub(s, i, 20));
		i++;
	}
	return (NULL);
}
