/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhashtag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:21:57 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/28 18:54:24 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	errorhashtag(char *s)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			y++;
		i++;
	}
	if (y != 4)
		return (0);
	printf("y = %d\n", y);
	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (s[i - 1] == '#')
				y++;
			if (s[i + 1] == '#')
				y++;
			if (s[i - 5] == '#')
				y++;
			if (s[i + 5] == '#')
				y++;
			printf("s[%d] y : %d\n", i, y);
		}
				i++;
	}
	if (y != 6 && y != 8)
		return (0);
	return (1);
}


int main()
{
	char *s = "..##\n...#\n...#\n....\n";

	printf("%s\n%d\n", s, errorhashtag(s));
	return 0;
}
