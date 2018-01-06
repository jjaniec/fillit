/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:18:31 by unicolai          #+#    #+#             */
/*   Updated: 2018/01/04 15:48:22 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Put the counter on the first dot of the map
*/

static int	ft_skip_dot_allready_taken(char *map, int *result, int *onemore)
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

/*
** If can put 4 stars on the map, return SUCCESS, otherwise return ERROR
*/

static int	ft_put_tetri_on_map(t_tetri *tbt, int *j, char **map, int *i)
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
	}
	return (r = ((*map)[*i] == '\0' && r == SUCCESS && star != 4) ? ERROR : r);
}

/*
** Replace stars by letter if result equal SUCCESS or
** replace stars by dot if result equal ERROR
*/

static int	ft_change_stars(char **map, int *result, int *j)
{
	int	i;
	int	firststar;

	i = 0;
	firststar = SUCCESS;
	while ((*map)[i] != '\0')
	{
		if ((*map)[i] == '*' && *result == SUCCESS)
		{
			(*map)[i] = *j + 65;
			if (firststar == SUCCESS)
				firststar = ERROR;
		}
		else if ((*map)[i] == '*' && *result == ERROR)
			(*map)[i] = '.';
		i++;
	}
	return (i);
}

/*
** Fill the map
*/

void		ft_fill_map(char **map, t_tetri *tabtetri)
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
		i = ft_skip_dot_allready_taken(*map, &result, &onemore);
		result = ft_put_tetri_on_map(tabtetri, &j, map, &i);
		ft_change_stars(map, &result, &j);
		if (result == SUCCESS)
		{
			tabtetri[j].decaltetri = onemore;
			onemore = 0;
			j++;
		}
		else if (result == ERROR && (*map)[i] == '\0')
			result = ft_next_possibility(map, &tabtetri, &j, &onemore);
		else
			onemore++;
	}
}
