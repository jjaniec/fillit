/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:36:04 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/20 17:49:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Generate a map in a char * to place tetriminos
*/

char	*ft_generate_map(unsigned int width)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ((width + 1) * (width) + 1));
	s[(((int)width + 1) * ((int)width))] = '\0';
	while (i < (((int)width + 1) * ((int)width)))
		if (((i + 1) % (width + 1) != 0))
			s[i++] = '.';
		else
			s[i++] = '\n';
	return (s);
}
