/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:24:17 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/20 19:52:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Makes all tests to verify validity of file content and all
** of it's tetriminos
*/

int		ft_pass_tests(char *file_content)
{
	int				i;
	int				j;
	unsigned short	r;
	char			*t_tmp;

	r = 0;
	j = 1;
	i = ft_count_tetris(file_content);
	if (i > 26 || ((int)ft_strlen(file_content) != (20 + (21 * (i - 1)))))
		r = 1;
	while (j <= i && r != 1)
	{
		t_tmp = ft_parse_tetri(file_content, j);
		if (
				ft_errordot(t_tmp) || \
				ft_errorhashtag(t_tmp) || \
				(int)ft_strlen(t_tmp) != 20
			)
			r = 1;
		j++;
	}
	if (r)
		write(1, "error\n", 6);
	return (r);
}
