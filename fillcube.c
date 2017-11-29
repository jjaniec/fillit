/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillcube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:19:23 by unicolai          #+#    #+#             */
/*   Updated: 2017/11/29 14:35:27 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	tetri();

int		ft_strlen(char *s);

int		ft_sqrt(int n);

char	*newmap(char *map)
{
	int	i;

	i = ft_strlen(map);
	i = ft_sqrt(i);
	i++;
	i *= i;
	map = malloc(sizeof(map) * (i + 1));
	return (map);
}

void	fillcube(char *map, t_list tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetri->s[i] != '\0')
	{
		if (map[j] != '\0')
			map[j] = tetri->s[i];
		else
		{
			map = newmap(s);
			while (tetri->s[i])
				i++;
			i--;
		}
		i++;
		j++;
	}
	i = 0;
	j = 0;
}


