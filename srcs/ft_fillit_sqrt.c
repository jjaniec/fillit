/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_sqrt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:08:20 by unicolai          #+#    #+#             */
/*   Updated: 2017/12/24 17:08:39 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Calculate square root for $n
*/

int		ft_fillit_sqrt(int n)
{
	int		res;

	res = 1;
	while (res * res < n)
		++res;
	return (res);
}

