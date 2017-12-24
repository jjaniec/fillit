/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:14:22 by jjaniec           #+#    #+#             */
/*   Updated: 2017/12/24 16:34:51 by unicolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
//# include "libft/libft.h"

# define BUFF_SIZE 21
# define SUCCESS 0
# define ERROR 1

typedef struct	s_tetri
{
	int		x;
	int		y;
	char	*s;
	int		decaltetri;
}				t_tetri;

char			*ft_read_content(int fd);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_parse_tetri(char *s, int nb);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

int				ft_errorhashtag(char *s);

int				ft_errordot(char *s);

int				ft_distribute_tetriminos(t_tetri **tab, char *s);

void			ft_putstr_fd(char const *s, int fd);

void			ft_upleft(char *s);

char			*ft_generate_map(unsigned int width);

int				ft_can_copy(char **map, t_tetri *t);

int				ft_map_copy(char **map, t_tetri *t);

char			*ft_resize_tetri(t_tetri *t, size_t size);

unsigned int	ft_get_map_size(char *m);

int				ft_count_tetris(char *file_content);

int				ft_next_possibility(char **map, t_tetri **tabtetri,
				int *j, int *onemore);

int				ft_map_len(char *map);
#endif
