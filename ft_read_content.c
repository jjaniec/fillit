/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:16:18 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 16:20:16 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_resize_buf(int fd, char *buf, int *bufsize_multiplier, int *wrote)
{
	char	*buf2;
	char	*retbuf;
	int		x;

	buf2 = (char *)malloc(sizeof(char) * BUFF_SIZE * *bufsize_multiplier + 1);
	x = read(fd, buf2, (BUFF_SIZE * *bufsize_multiplier));
	buf2[x] = '\0';
	*wrote = x;
	*bufsize_multiplier += 1;
	return (ft_strjoin(buf, buf2));
}


char	*ft_read_content(int fd)
{
	char	*buf;
	char	*buf2;
	int		x;
	int		multiplier;

	multiplier = 1;
	buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	x = read(fd, buf, BUFF_SIZE);
	buf[x] ='\0';
	if (x < BUFF_SIZE)
		return (buf);
	while (x > 0)
		buf = ft_resize_buf(fd, buf, &multiplier, &x);
	return (buf);
}
