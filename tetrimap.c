/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:58 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/21 19:47:02 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

#define SUCCESS 0
#define ERROR 1

int		nbligne(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	return (i);
}

void	skip_allready_taken(char *map, int *i, int *result, int *onemore)
{
	while (map[*i] != '.' && map[*i] != '\0')
		(*i)++;
	if (*result == ERROR)
		*i += *onemore;
}

int		put_tetri_on_map(t_tetri *tabtetri, int *j, char *map, int *i)
{
	static int	k = 0;
	int			marquer;
	int			nbl;
	int			result;

	result = (k -= k + 1) ? SUCCESS : SUCCESS;
	while (tabtetri[*j].s[++k] != '\0' && result == SUCCESS && map[*i] != '\0')
	{
		nbl = nbligne(map);
		if (tabtetri[*j].s[k] == '#' && tabtetri[*j].s[k - 1] != '#')
			marquer = (*i % nbl) - (k % 5);
		if (tabtetri[*j].s[k] == '#' && map[*i] == '.')
			map[*i] = '*';
		else if (tabtetri[*j].s[k] == '#' && map[*i] != '.')
			result = ERROR;
		else if (tabtetri[*j].s[k] == '\n')
			while (map[*i] != '\n' || ((*i += marquer) ? 0 : 0))
				(*i)++;
		else if (map[*i] == '\n' && ((*i += marquer) ? 1 : 1))
			while (tabtetri[*j].s[k] != '\n')
				if (tabtetri[*j].s[k++] == '#')
					result = ERROR;
		(*i)++;
	}
	return (result);
}

int		change_stars(char *map, int *result, int *j, t_tetri *tabtetri)
{
	int	i;
	int	firststar;
	int	nbl;

	i = 0;
	firststar = SUCCESS;
	nbl = nbligne(map);
	while (map[i] != '\0')
	{
		if (map[i] == '*' && *result == SUCCESS)
		{
			map[i] = *j + 65;
			if (firststar == SUCCESS)
			{
				tabtetri[*j].x = i % nbl;
				tabtetri[*j].y = i / nbl;
				firststar = ERROR;
			}
		}
		else if (map[i] == '*' && *result == ERROR)
			map[i] = '.';
		i++;
	}
	return (i);
}

void	tetrimap(char *map, t_tetri *tabtetri)
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
		i = 0;
		skip_allready_taken(map, &i, &result, &onemore);
		result = put_tetri_on_map(tabtetri, &j, map, &i);
		i = 0;
		i = change_stars(map, &result, &j, tabtetri);
		if (result == SUCCESS)
		{
			onemore = 0;
			j++;
		}
		else
			onemore++;
		onemore += onemore % nbligne(map);
	}
}

//<d0>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int		main(int ac, char **av)
{
	int			i;

	(void)ac;
	(void)av;

	char map[300] = "...\n...\n...\n";
	t_tetri t1;
	t_tetri t2;
	t_tetri t3;
	t_tetri t4;
	t_tetri	*tabtetri;

	t1.s = "#...\n#...\n##..\n....\n....\n";
	t2.s = "##..\n##..\n....\n....\n....\n";
	t3.s = ".#..\n.#..\n##..\n....\n....\n";
	t4.s = "####\n....\n....\n....\n....\n";
	t1.x = 0;
	t1.y = 0;
	t2.x = 0;
	t2.y = 0;
	t3.x = 0;
	t3.y = 0;
	t4.x = 0;
	t4.y = 0;
	tabtetri = (t_tetri *)malloc(sizeof(t_tetri) * 5);
	tabtetri[0] = t1;
	tabtetri[1] = t2;
	tabtetri[2] = t3;
	tabtetri[3] = t4;
	tabtetri[4].s = NULL;
	tetrimap(map, tabtetri);
	i = 0;
	while (tabtetri[i].s != NULL)
	{
		printf("tabtetri[%d].x = %d, tabtetri[%d].y = %d\n", i, tabtetri[i].x, i, tabtetri[i].y);
		i++;
	}
	printf("%s\n", map);
	return (0);
}
//</d0>

