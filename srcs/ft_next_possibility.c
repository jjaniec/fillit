/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_possibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:19:05 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/24 17:13:20 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
**
*/

static void	enlargemap(int *j, char **map, int *result)
{
	int newnbl;
	int	i;
	int	i2;

	newnbl = ft_map_len(*map) + 1;
	*j = 0;
	*result = SUCCESS;
	free(*map);
	if (!(*map = malloc(sizeof(**map) * (newnbl * newnbl - newnbl + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	i2 = 0;
	while (i <= (newnbl - 1) * (newnbl - 1))
	{
		while (i2 < newnbl - 1)
		{
			(*map)[i] = '.';
			i++;
			i2++;
		}
		(*map)[i] = '\n';
		i2 = 0;
		i++;
	}
	(*map)[i] = '\0';
}

/*
**
*/

static int	firsthashtag(t_tetri *tabtetri, int j)
{
	int	k;
	int	jprevious;

	k = 0;
	jprevious = j - 1;
	while (tabtetri[jprevious].s[k] != '#')
		k++;
	return (k);
}

/*
**
*/

static int	endofmap(char *map, t_tetri *tabtetri, int j)
{
	int	i;
	int	k;
	int	firststar;
	int	positionletter;
	int	endoftetri;

	k = -1;
	firststar = SUCCESS;
	positionletter = 0;
	endoftetri = ERROR;
	while (tabtetri[j].s[++k])
	{
		if (firststar == SUCCESS)
		{
			firststar = ERROR;
			positionletter = k % 5;
		}
	}
	i = 0;
	while (map[i])
		i++;
	i -= 2;
	if (map[i - positionletter] == j - 1 + 65)
		endoftetri = SUCCESS;
	return (endoftetri);
}

/*
**
*/

static void	remove_last_tetri(char **map, int *j)
{
	int	i;

	i = 0;
	(*j)--;
	while ((*map)[i])
	{
		if ((*map)[i] == *j + 65)
			(*map)[i] = '.';
		i++;
	}
}

/*
**
*/

int		ft_next_possibility(char **map, t_tetri **tabtetri, int *j, int *onemore)
{
	int	result;

	result = ERROR;
	if (endofmap(*map, *tabtetri, *j) == SUCCESS)
	{
		(*tabtetri)[*j].decaltetri = 0;
		remove_last_tetri(map, j);
		if (*j != 0)
			(*tabtetri)[*j].decaltetri += firsthashtag(*tabtetri, *j);
	}
	remove_last_tetri(map, j);
	*j >= 0 ? (*tabtetri)[*j].decaltetri++ : 0;
	*onemore = (*tabtetri)[*j].decaltetri;
	if (*j == -1)
		enlargemap(j, map, &result);
	return (result);
}
