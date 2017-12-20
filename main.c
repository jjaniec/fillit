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

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*s;
	t_tetri		*tab;

	if (ac != 2)
		return (ft_print_usage());
	fd = open(av[1], O_RDONLY);
	s = ft_read_content(fd);
	if (ft_pass_tests(s))
		return (1);
	ft_distribute_tetriminos(&tab, s);
	return (0);
}

