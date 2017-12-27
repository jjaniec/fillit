/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:47:50 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/20 18:31:53 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Return tetri number $nb contained in $s, only works if length of
** tetriminos is valid
*/

char	*ft_parse_tetri(char *s, int nb)
{
	char	*t;

	t = ft_strsub(s, ((nb - 1) * 21), 20);
	return ((ft_strlen(t) == 20) ? (t) : (NULL));
}
