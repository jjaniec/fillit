/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:58:44 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 20:55:55 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Prints usage of fillit
*/

int		ft_print_usage(char *pname)
{
	ft_putstr("usage: ");
	ft_putstr(pname);
	ft_putstr(" [file]\n");
	return (1);
}
