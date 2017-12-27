/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:16:18 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/30 15:14:01 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Append to ft_read_content's buffer, following of file descriptor, with a
** size of ($BUFF_SIZE * $bufsize_multiplier) bytes
*/

char	*ft_resize_buf(int fd, char *buf, int *bufsize_multiplier, int *wrote)
{
	char	*buf2;

	buf2 = (char *)malloc(sizeof(char) * BUFF_SIZE * *bufsize_multiplier + 1);
	*wrote = read(fd, buf2, (BUFF_SIZE * *bufsize_multiplier));
	buf2[*wrote] = '\0';
	*bufsize_multiplier += 1;
	return (ft_strjoin(buf, buf2));
}

/*
** Read the first $BUFF_SIZE bytes of file descriptor passed in parameter
** and store it in a malloc'ed char *
*/

char	*ft_read_content(int fd)
{
	char	*buf;
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
