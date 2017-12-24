/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:18:31 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/24 16:47:27 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		skip_dot_allready_taken(char *map, int *result, int *onemore)
{
	int	i;

	i = 0;
	while (map[i] != '.' && map[i] != '\0')
	{
		i++;
	}
	if (*result == ERROR)
		i += *onemore;
	return (i);
}

int		put_tetri_on_map(t_tetri *tbt, int *j, char **map, int *i)
{
	static int	k = 0;
	int			marker;
	int			r;
	static int	star = 0;

	r = ((k -= k + 1) && (star -= star)) ? SUCCESS : SUCCESS;
	while (tbt[*j].s[k] != '#' || ((k--) ? 0 : 0))
		k++;
	while (tbt[*j].s[++k] != 0 && r == SUCCESS && (*map)[*i] != 0 && star < 4)
	{
		if (tbt[*j].s[k] == '#' && tbt[*j].s[k - 1] != '#')
			marker = (*i % ft_map_len(*map)) - (k % 5);
		if (tbt[*j].s[k] == '#' && (*map)[*i] == '.' && ++star)
			(*map)[*i] = '*';
		else if (tbt[*j].s[k] == '#' && (*map)[*i] != '.')
			r = ERROR;
		else if (tbt[*j].s[k] == '\n')
			while ((*map)[*i] != '\n' || ((*i += marker) ? 0 : 0))
				(*i)++;
		else if ((*map)[*i] == '\n' && ((*i += marker) ? 1 : 1))
			while (tbt[*j].s[k] != '\n')
				r = (tbt[*j].s[k++] == '#') ? ERROR : r;
		(*i)++;
		printf("%s\n", *map);
		//sleep(1);
	}
	return (r = ((*map)[*i] == '\0' && r == SUCCESS && star != 4) ? ERROR : r);
}

int		change_stars(char **map, int *result, int *j, t_tetri *tabtetri)
{
	int	i;
	int	nbl;

	i = 0;
	nbl = ft_map_len(*map);
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] == '*' && *result == SUCCESS)
			(*map)[i] = *j + 65;
		else if ((*map)[i] == '*' && *result == ERROR)
			(*map)[i] = '.';
		i++;
	}
	return (i);
}

void	fillmap(char **map, t_tetri *tabtetri)
{
	int		i;
	int		j;
	int		result;
	int		onemore;

	j = 0;
	onemore = 0;
	result = SUCCESS;
	while (tabtetri[j].s != NULL)
	{
		i = skip_dot_allready_taken(*map, &result, &onemore);
		result = put_tetri_on_map(tabtetri, &j, map, &i);
		change_stars(map, &result, &j, tabtetri);
		if (result == SUCCESS)
		{
			tabtetri[j].decaltetri = onemore;//
			onemore = 0;
			j++;
		}
		else if (result == ERROR && (*map)[i] == '\0')
			result = ft_next_possibility(map, &tabtetri, &j, &onemore);
		else
			onemore++;
		printf("%s\n", *map);
		//sleep(1);
	}
}
//Quand j'ai un tetri qui rentre pas, je reviens sur le tetri precedent et je le replace en le decalant de un. Je fais ca jusqua ce que le tetri d'apres rentre ou que ce tetri arrive au '\0'. Si le tetri arrive au '\0' je passe au tetri encore d'avant. Si le premier tetri arrive au '\0' j'aggrandi la map.

int		fillit_sqrt(int n)
{
	int		res;

	res = 1;
	while (res * res < n)
		++res;
	return (res);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int		main()
{
	int		i;
	int		i2;
	int		i3;
	char	*map;
	t_tetri t1;
	t_tetri t2;
	t_tetri t3;
	t_tetri t4;
	t_tetri	*tabtetri;
	int		nbtetri;
	int		taillemap;

	t1.s = ".#..\n.#..\n##..\n....\n";
	t2.s = "#...\n#...\n##..\n....\n";
	t3.s = "##..\n##..\n....\n....\n";
	t4.s = "####\n....\n....\n....\n";
	t1.decaltetri = 0;
	t2.decaltetri = 0;
	t3.decaltetri = 0;
	t4.decaltetri = 0;
	i = -1;
	i2 = 0;
	i3 = 0;
	if (!(tabtetri = (t_tetri *)malloc(sizeof(t_tetri) * 5)))
		return (0);
	tabtetri[0] = t1;
	tabtetri[1] = t2;
	tabtetri[2] = t3;
	tabtetri[3] = t4;
	tabtetri[4].s = NULL;
	nbtetri = 0;
	while (tabtetri[++i].s != NULL)
		nbtetri++;
	taillemap = fillit_sqrt(nbtetri * 4) * fillit_sqrt(nbtetri * 4) + nbtetri;
	if (!(map = malloc(sizeof(*map) * (taillemap + 1))))
		return (0);
	printf("taillemap: %d\n", taillemap);
	while (i2 < taillemap)
	{
		while (i3 < nbtetri)
		{
			map[i2] = '.';
			i2++;
			i3++;
		}
		map[i2] = '\n';
		i3 = 0;
		i2++;
	}
	map[i2] = '\0';
	printf("%s\n", map);
	fillmap(&map, tabtetri);
	i = 0;
	while (tabtetri[i].s != NULL)
	{
		printf("tabtetri[%d].x = %d, tabtetri[%d].y = %d\n", i, tabtetri[i].x, i, tabtetri[i].y);
		i++;
	}
	printf("%s\n", map);
	return (0);
}
