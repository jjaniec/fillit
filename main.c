/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:09:37 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/20 19:43:35 by jjaniec          ###   ########.fr       */
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
	if (ft_pass_tests(s))
		return (1);
	if (ft_distribute_tetriminos(&tab, s) == 1)
		return (1);
	return (0);
}

