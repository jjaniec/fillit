/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distribute_tetriminos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:24:56 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/20 19:55:28 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Create a sturct * containing each tetrimminos in t_tetri.s
** t_tetri.decaltetri is initialized to 0 and will contain the offset of
** the tetriminos in our map, used for backtracking
*/

int		ft_distribute_tetriminos(t_tetri **tab, char *s)
{
	int		i;
	int		j;

	j = ft_count_tetris(s);
	(*tab) = (t_tetri *)malloc(sizeof(t_tetri) * (j + 1));
	i = -1;
	while (++i != j)
	{
		(*tab)[i].s = ft_parse_tetri(s, i + 1);
		ft_upleft((*tab)[i].s);
		(*tab)[i].decaltetri = 0;
	}
	(*tab)[j].s = NULL;
	return (0);
}
