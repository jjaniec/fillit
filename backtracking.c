/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:58 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/22 22:51:43 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

#define SUCCESS 0
#define ERROR 1

void	remove_last_tetri(char *map, int *j)
{
	int	i;

	i = 0;
	(*j)--; // Pour acceder a l'element precedent
	while (map[i])
	{
		if (map[i] == *j + 65)
			map[i] = '.';
		i++;
	}
}

void	backtrack(char *map, t_tetri *tabtetri, int *j)
{
	remove_last_tetri(map, j);
//	(*j)++;
	(void)tabtetri;
}

int		nbligne(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	return (i);
}

int		skip_allready_taken(char *map, int *decaltetri, int *result, int *onemore)
{
	int	i;

	(void)decaltetri;
	i = 0;
	while (map[i] != '.' && map[i] != '\0')
	{
		(i)++;
		//(*decaltetri)++;
	}
	printf("Before onemore i: %d\n", i);
	if (*result == ERROR)
		i += *onemore;
	printf("After onemore i: %d\n\n", i);
	return (i);
}

int		put_tetri_on_map(t_tetri *tbt, int *j, char *map, int *i)
{
	static int	k = 0;
	int			marker;
	int			r;
	static int	star = 0;

	r = ((k -= k + 1) && (star -= star)) ? SUCCESS : SUCCESS;
	while (tbt[*j].s[k] != '#' || ((k--) ? 0 : 0))
		k++;
	while (tbt[*j].s[++k] != '\0' && r == SUCCESS && map[*i] != 0 && star < 4)
	{
		if (tbt[*j].s[k] == '#' && tbt[*j].s[k - 1] != '#')
			marker = (*i % nbligne(map)) - (k % 5);
		if (tbt[*j].s[k] == '#' && map[*i] == '.' && ++star)
			map[*i] = '*';
		else if (tbt[*j].s[k] == '#' && map[*i] != '.')
			r = ERROR;
		else if (tbt[*j].s[k] == '\n')
			while (map[*i] != '\n' || ((*i += marker) ? 0 : 0))
				(*i)++;
		else if (map[*i] == '\n' && ((*i += marker) ? 1 : 1))
			while (tbt[*j].s[k] != '\n')
				r = (tbt[*j].s[k++] == '#') ? ERROR : r;
		(*i)++;
	}
	return (r = (map[*i] == '\0' && r == SUCCESS && star != 4) ? ERROR : r);
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
	int		decaltetri;//
	//int		newchange;//

	j = 0;
	onemore = 0;
	decaltetri = 0;//
	result = SUCCESS;
	while (tabtetri[j].s != NULL)
	{
		i = skip_allready_taken(map, &decaltetri, &result, &onemore);
		result = put_tetri_on_map(tabtetri, &j, map, &i);
		change_stars(map, &result, &j, tabtetri);
		printf("%s\n", map);
		if (result == SUCCESS)
		{
			decaltetri = onemore;//
			onemore = 0;
			j++;
			//decaltetri = 0;//
		}
		else if (result == ERROR && map[i] == '\0')
		{
			printf("Before j: %d\n", j);
			backtrack(map, tabtetri, &j);//
			printf("After j: %d\n", j);
//			if (onemore != 0)//
			if (j == 0)//
				decaltetri = 0;//
			decaltetri++;//
			printf("decaltetri: %d\n", decaltetri);
			//onemore = 0;
			onemore = decaltetri;//
			//j++;
			if (j == -1)//
			{//
				printf("Agrandir map\n");//
				tabtetri[j].s = NULL;//
			}//
		}
		else
		{
			//decaltetri = 0;//
			onemore++;
		}
		printf("onemore: %d, j: %d\n", onemore, j);
		//printf("%s\n", map);
		sleep(1);

	}
}

//Quand j'ai un tetri qui rentre pas, je reviens sur le tetri precedent et je le replace en le decalant de un. Je fais ca jusqua ce que le tetri d'apres rentre ou que ce tetri arrive au '\0'. Si le tetri arrive au '\0' je passe au tetri encore d'avant. Si le premier tetri arrive au '\0' j'aggrandi la map.

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

	char map[300] = "....\n....\n....\n....\n";
	t_tetri t1;
	t_tetri t2;
	t_tetri t3;
	t_tetri t4;
	t_tetri	*tabtetri;

	t1.s = ".#..\n.#..\n##..\n....\n";
	t2.s = "#...\n#...\n##..\n....\n";
	t3.s = "##..\n##..\n....\n....\n";
	t4.s = "####\n....\n....\n....\n";
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

