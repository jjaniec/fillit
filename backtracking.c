/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:58 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/23 12:23:30 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

#define SUCCESS 0
#define ERROR 1

int		firsthashtag(t_tetri *tabtetri, int *j)
{
	int	k;
	int	jprevious;

	k = 0;
	jprevious = *j - 1;
	while (tabtetri[jprevious].s[k] != '#')
		k++;
	printf("K: %d, jprevious: %d\n", k, jprevious);
	return (k);
}

int		endofmap2(char *map, t_tetri *tabtetri, int *j, int i)
{
	int	k;
	int	hashtag_more_right;
	int	nbhashtag;
	int	lasthashtag;
	int	endoftetri;

	k = 0;
	nbhashtag = 0;
	hashtag_more_right = k % 5;
	endoftetri = ERROR;
	while (tabtetri[*j].s[k])
	{
		if (tabtetri[*j].s[k] == '#')
		{
			nbhashtag++;
			if (k % 5 > hashtag_more_right)
				hashtag_more_right = k % 5;
			if (nbhashtag == 4)
				lasthashtag = k;
		}
		k++;
	}
	printf("hmr: %d, lh modulo 5 : %d\n", hashtag_more_right, lasthashtag % 5);
	hashtag_more_right = hashtag_more_right - (lasthashtag % 5);
	if (map[i + lasthashtag + hashtag_more_right + 2] == '\0')
		endoftetri = SUCCESS;
	printf("result endoftetri: %d\nmap[%d] : %c, lasthashtag: %d, hmr: %d, map[lh+i+hmr:%d] |%c|\n", endoftetri, i, map[i], lasthashtag, hashtag_more_right, lasthashtag + i + hashtag_more_right, map[lasthashtag + i + hashtag_more_right]);
	return (endoftetri);
}

int		endofmap(char *map, t_tetri *tabtetri, int *j)
{
	int	i;
	int	k;
	int	firststar;
	int	positionletter;
	int	endoftetri;

	k = 0;
	firststar = SUCCESS;;
	positionletter = 0;
	endoftetri = ERROR;
	while (tabtetri[*j].s[k])
	{
		if (firststar == SUCCESS)
		{
			firststar = ERROR;
			positionletter = k % 5;
		}
		k++;
	}
	i = 0;
	while (map[i])
		i++;
	printf("%s\n", map);
	i -= 2;
	printf("dernier char de la map: %c, j+65: %c, map[i:%d - positionletter:%d = %d] : %c\n", map[i], *j+65, i, positionletter, i-positionletter, map[i-positionletter]);
	if (map[i - positionletter] == *j - 1 + 65) //////// CA BOUCLE ICI A VOIR POURQUOI A CAUSE DU -1
		endoftetri = SUCCESS;
	printf("result endoftetri : %d, map[i - positionletter] : %c, j+65 : %c\n", endoftetri, map[i - positionletter], *j + 65);
	return (endoftetri);
}

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
	printf("remove map: \n%s\n", map);
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

int		skip_allready_taken(char *map, int *result, int *onemore)
{
	int	i;

	i = 0;
	while (map[i] != '.' && map[i] != '\0')
	{
		i++;
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
	printf("k: %d, i: %d\n",k+1, *i);//
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
	//int		decaltetri;//
	//int		newchange;//

	j = 0;
	onemore = 0;
	//decaltetri = 0;//
	result = SUCCESS;
	while (tabtetri[j].s != NULL)
	{
		i = skip_allready_taken(map, &result, &onemore);
		result = put_tetri_on_map(tabtetri, &j, map, &i);
		change_stars(map, &result, &j, tabtetri);
		printf("%s\n", map);
		if (result == SUCCESS)
		{
			tabtetri[j].decaltetri = onemore;//
			onemore = 0;
			j++;
			//decaltetri = 0;//
		}
		else if (result == ERROR && map[i] == '\0')
		{
			printf("IIIIIIIIIIIIIIIIIIIIII: %d\n", i);
			//if(endofmap2(map, tabtetri, &j, i) == SUCCESS)//
			if (endofmap(map, tabtetri, &j) == SUCCESS)//
			{//
				tabtetri[j].decaltetri = 0;//
				backtrack(map, tabtetri, &j);//
				tabtetri[j].decaltetri += firsthashtag(tabtetri, &j);
				printf("yeah tbt[%d].decaltetri: %d\n", j, tabtetri[j].decaltetri);
				//j--;//
			}//
			printf("Before j: %d\n", j);
			backtrack(map, tabtetri, &j);//
			printf("After j: %d\n", j);
			tabtetri[j].decaltetri++;//
			printf("tbt[%d].decaltetri: %d\n", j,tabtetri[j].decaltetri);
			//onemore = 0;
			onemore = tabtetri[j].decaltetri;//
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
		printf("tbt[%d].decaltetri: %d, onemore: %d, j: %d\n", j, tabtetri[j].decaltetri, onemore, j);
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
	t1.x = -1;
	t1.y = -1;
	t2.x = -1;
	t2.y = -1;
	t3.x = -1;
	t3.y = -1;
	t4.x = -1;
	t4.y = -1;
	t1.decaltetri = 0;
	t2.decaltetri = 0;
	t3.decaltetri = 0;
	t4.decaltetri = 0;

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

