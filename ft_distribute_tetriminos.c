/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distribute_tetriminos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:24:56 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 23:11:45 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_distribute_tetriminos(t_tetri **tab, char *s)
{
	int		i;
	int		j;

	i = 1;
	while (ft_parse_tetri(s, i) != NULL)
		i++;
	j = i;
	(*tab) = (t_tetri *)malloc(sizeof(t_tetri) * i);
	i = 1;
	while (i != j - 1)
	{
		if (ft_errordot(ft_parse_tetri(s, i)) == 0 && ft_errorhashtag(ft_parse_tetri(s, i)) == 0)
			(*tab)[i - 1].s = ft_parse_tetri(s, i);
		else if (!(ft_errordot(ft_parse_tetri(s, i)) == 0 && ft_errorhashtag(ft_parse_tetri(s, i)) == 0))
		{
			ft_putstr_fd("Error: Invalid Tetriminos !", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
