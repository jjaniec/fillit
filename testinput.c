/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testinpute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:08:35 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/24 22:28:13 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <stdlib.h>
#include <fcntl.h>

int 	ft_a(char *buf, int len)
{
	int 	i;
	int 	j;

	j = 0;
	i = -1;
	while (++i < len)
	{
		while (buf[i] == '.' || buf[i] == '#')
			j++;
		if (!(j == 16))
			write(1, "error", 6);
	}
	return (len);
}

int 	main()
{
	char 	*filename = "lol.lol";
	char 	buf[545];
	int 	fd;
	int 	len;

	fd = open(filename, O_RDONLY);
	len = read(fd, buf, 545);
	ft_a(buf, len);

	close(fd);
}
