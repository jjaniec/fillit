/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:14:22 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 23:06:25 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct	s_tetri
{
	int		x;
	int		y;
	char	*s;
}				t_tetri;
char			*ft_read_content(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_parse_tetri(char *s, int nb);
int				ft_errorhashtag(char *s);
int				ft_errordot(char *s);
int				ft_distribute_tetriminos(t_tetri **tab, char *s);
#endif
