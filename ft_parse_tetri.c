/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:47:50 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 17:02:51 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char *s, int a, int b);

char	*ft_parse_tetri(char *s, int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '#' && s[i] != '.')
		i++;
	while (s[i++])
	{
		if ((s[i] == '#' || s[i] == '.') && nb != 1)
		{
			while (s[i] == '#' || s[i] == '.' || s[i] == '\n' && \
					s[i - 1] != '\n')
				i++;
			nb--;
			if (s[i] == '\n' && s[i - 1] == '\n')
				i++;
		}
		if (nb == 1)
			return (ft_strsub(s, i, 20));
	}
	return (NULL);
}

int		main()
{
	char	*buf;
	int		fd;

	fd = open("map.fillit", O_RDONLY);
	buf = ft_read_content(fd);
	buf = ft_parse_tetri(buf, 4);
	printf("\nreturned buf\n//////////\n|%s|", buf);
}
