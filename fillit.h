/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:14:22 by jjaniec           #+#    #+#             */
/*   Updated: 2017/11/29 21:24:47 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>

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

void			ft_putstr_fd(char *s, int fd);

void			ft_upleft(char *s);
#endif
