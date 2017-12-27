/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:09:37 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/20 20:02:37 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Main file of fillit project, try it with:
** make T_COUNT=x && ./fillit map.fillit
** with x the number of tetriminos you want to create
**
** thanks to user dnetto for his map_generator script
*/

int		main(int ac, char **av)
{
	int		fd;
	char	*s;
	t_tetri		*tab;
	char 	*map;

	if (ac != 2)
		return (ft_print_usage());
	fd = open(av[1], O_RDONLY);
	s = ft_read_content(fd);
	if (ft_pass_tests(s))
		return (1);
	ft_distribute_tetriminos(&tab, s);
	map = ft_generate_map(ft_fillit_sqrt(ft_count_tetris(s) * 4));
	ft_fill_map(&map, tab);
	ft_putstr(map);
	return (0);
}

