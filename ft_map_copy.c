/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_copy_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:07:13 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/19 18:56:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char	*ft_generate_map(int x);

void	ft_map_copy(char **map, t_tetri *t)
{
	int		i;

	i = 0;
	while ((*map)[i] && t->s[i])
	{
		(*map)[i] = t->s[i];
		i++;
	}
}

char	*ft_resize_tetri(t_tetri *t, size_t size)
{
	char	*new_t;
	int		i;
	int		j;

	new_t = ft_generate_map(size);
	i = 0;
	j = 0;
	while (t->s[i] && new_t[j])
	{
		while (t->s[i] != '\n')
		{
			if (new_t[j] == '.')
				new_t[j] = t->s[i];
			i++;
			j++;
		}
		while (new_t[j] != '\n')
			j++;
		i++;
		j++;
	}
	return (new_t);
}

int		main()
{
	char *m;
	t_tetri t;

	t.s = "AE..\n..TT\nR...\n....\n";
	t.x = 1;
	t.y = 1;
	m = ft_generate_map(8);
	t.s = ft_resize_tetri(&t, 8);
	ft_map_copy(&m, &t);
	printf("new_t\n%s", t.s);
	printf("aaaaa\n%s", m);
	return (0);
}
