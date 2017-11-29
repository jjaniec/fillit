/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:09:37 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/29 23:10:08 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main()
{
	int		fd;
	char	*s;
	t_tetri		*tab;

	fd = open("map.fillit", O_RDONLY);
	s = ft_read_content(fd);
	if (ft_distribute_tetriminos(&tab, s) == 1)
		return (1);
	return (0);
}

