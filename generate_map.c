/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:41:30 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/18 16:31:50 by jjaniec          ###   ########.fr       */
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
	int		y;

	i = 0;
	s = (char *)malloc(sizeof(char) * ((width + 1) * (width + 1) + 1));
	s[((width + 1) * (width + 1))] = '\0';
	while (i < ((width + 1) * (width + 1)))
		if (((i + 1) % (width + 1) != 0))
			s[i++] = '.';
		else
			s[i++] = '\n';
	printf("%s", s);
	return (s);
}

int		main()
{
	ft_generate_map(6);
	return (0);
}
