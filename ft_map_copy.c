/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:13:33 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/12 16:14:16 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Tries to copy tetri in a copy of map to know if it is possible
*/

int		ft_can_copy(char **map, int offset_x, int offset_y, char *tetri)
{
	char	*tmp;

	tmp = ft_strdup(*map);
	if (ft_map_copy(&tmp, offset_x, offset_y, tetri) != 1)
		return (ft_map_copy(&tmp, offset_x, offset_y, tetri));
	return (0);
}

/*
** Copies in $map, $tetri, starting at $map[$offset_y][$offset_x]
** The function returns 0 if copy was successful or 1 if tetriminos is 
** incomplete in $map
*/

int		ft_map_copy(char **map, int offset_x, int offset_y, char *tetri)
{
	int		width;
	int		i;
	int		j;

	i = 0;
	j = 0;
	width = 0;
	while ((*map)[width] && (*map)[width] != '\n')
		width += 1;
	width += 1;
	while (tetri[i] && (*map)[(width * offset_y) + offset_x + j])
	{
		if (tetri[i] != '\n' && tetri[i] && tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			if ((*map)[(offset_y * width) + offset_x + j] != '.')
				return (((*map)[(width * offset_y) + offset_x + j] == '\n') \
						? (2) : (1));
			(*map)[(offset_y * width) + offset_x + j] = tetri[i];
			j += 1;
		}
		if (tetri[i] == '\n')
		{
			j = 0;
			offset_y += 1;
		}
		i++;
	}
	return (0);
}


int		main()
{
	char	*m;
	char	*t;

	m = ft_create_map(5);
	t = "AA..\nA...\nA...\n....\n";
	printf("%d - ", ft_map_copy(&m, 0, 0, t));
	printf("\n%s|\n", m);
	printf("%d - ", ft_can_copy(&m, 0, 0, t));
	printf("\n%s|\n", m);
}
