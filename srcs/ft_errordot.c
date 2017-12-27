/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errordot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:10:04 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/29 18:35:15 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Check validity of tetriminos by verifying it's content
*/

int	ft_errordot(char *s)
{
	int	i;
	int 	dot_count;

	dot_count = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		dot_count += ((s[i] == '.') ? (1) : (0));
		if ((i + 1) % 5 == 0 && s[i] != '\n')
			return (1);
	}
	return ((dot_count == 12) ? (0) : (1));
}
