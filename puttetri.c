/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:41:55 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/20 18:37:26 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

#define	SUCCESS 0
#define ERROR 1

int		ft_strlen(char *s)
{
	int		i;
	int		result;

	result = 0;
	i = -1;
	while (s[++i] != 0)
		result++;
	return (result);
}

int		fillit_sqrt(int n)
{
	int		res;

	res = 1;
	while (res * res < n)
		++res;
	return (res);
}

int		nbligne(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

void	ft_backtrack(char *map, t_tetri *tabtetri)
{
	int		i;
	int		j;
	int		k;
	int		nbl;
	int		result;
	int		firststar;
	int		onemore;
	int		marquer;

	j = 0;
	onemore = 0;
	while (tabtetri[j].s != NULL) // Pour chaque tetri
	{
		k = 0; // charactere d'un tetri
		i = 0; // charactere de la map
		while (map[i] != '.' && map[i] != '\0') // Pour avancer si la place dans la map est deja occupee
			i++;
		if (result == ERROR)
			i += onemore;
		result = SUCCESS;
		//printf("map[%d] = %c\n", i, map[i]);
		while (tabtetri[j].s[k] != '\0' && result == SUCCESS && map[i] != '\0') // Analyse chaque char du tetri
		{
			nbl = nbligne(map);
			if (tabtetri[j].s[k] == '#' && tabtetri[j].s[k - 1] != '#')
				marquer = i % nbl;
			printf("i: %d, i modulo nbl: %d\n", i, i % nbl);
			printf("marquer: %d de j, k %d, %d\n", marquer, j, k);
			if (tabtetri[j].s[k] == '#' && map[i] == '.') // Si la place est disponible pour placer un bout de la piece du tetri
				map[i] = '*';
			else if (tabtetri[j].s[k] == '#' && map[i] != '.') // Si la place n'est pas disponible
				result = ERROR;
			else if (tabtetri[j].s[k] == '\n') // Si on veut passer a la ligne suivante de la map car on est en bout de ligne du tetri
			{
				while (map[i] != '\n')
					i++;
				i += marquer;
			}
			else if (map[i] == '\n') // Si je suis en fin de map
			{
				i += marquer;
				while (tabtetri[j].s[k] != '\n')
				{
					if (tabtetri[j].s[k] == '#')
						result = ERROR;
					k++;
				}
			}
			//printf("equanime\nresult = %d, tabtetri[%d].s[%d] = %c\n", result, j, k, tabtetri[j].s[k]);
			i++; // On passe au char suivant sur la map
			k++; // On passe au char suivant du tetri
		}
		printf("map :\n%s\n", map);
		i = 0;
		firststar = 1;
		while (map[i] != '\0')
		{
			if (map[i] == '*' && result == SUCCESS)
			{
				map[i] = j + 65;
				onemore = 0;
				if (firststar == 1)
				{
					tabtetri[j].x = i % nbl;
					tabtetri[j].y = i / nbl;
					firststar = 0;
				}
			}
			else if (map[i] == '*' && result == ERROR)
				map[i] = '.';
			i++;
		}
		if (result == SUCCESS)
			j++;
		else
			onemore++;
		//printf("2. tabtetri[%d].x = %d, tabtetri[%d].y = %d, tabtetri[%d].s = %s\n", j, tabtetri[j].x, j, tabtetri[j].y, j, tabtetri[j].s);
		//printf("1. tabtetri[%d].s[%d] = %c, result = %d, map[%d] = %c\n", j, k, tabtetri[j].s[k], result, i, map[i]);
	}
}

//<d0>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int				main(int ac, char **av)
{
	int			i;

	(void)ac;
	(void)av;

	char map[300] = "......\n......\n......\n......\n......\n";
	t_tetri t1;
	t_tetri t2;
	t_tetri t3;
	t_tetri t4;
	t_tetri	*tabtetri;

	t1.s = "##..\n.##.\n....\n....\n....\n";
	t2.s = "##...\n.##.\n....\n....\n....\n";
	t3.s = "#...\n#...\n#...\n#...\n....\n";
	t4.s = ".#..\n###.\n....\n....\n....\n";
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
	ft_backtrack(map, tabtetri);
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
