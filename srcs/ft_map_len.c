/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 16:39:07 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/24 16:39:52 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Calculate size of map passed in parameter
*/

int		ft_map_len(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	return (i);
}
