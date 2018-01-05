/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:14:22 by jjaniec           #+#    #+#             */
/*   Updated: 2018/01/05 20:54:56 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include "../libft/libft.h"

# define BUFF_SIZE 21
# define SUCCESS 0
# define ERROR 1

typedef struct	s_tetri
{
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

int				ft_count_tetris(char *file_content);

int				ft_next_possibility(char **map, t_tetri **tabtetri,
				int *j, int *onemore);

int				ft_map_len(char *map);

void			ft_fill_map(char **map, t_tetri *tabtetri);

int				ft_fillit_sqrt(int n);

int				ft_pass_tests(char *file_content);

int				ft_print_usage(char *pname);

char			*ft_strjoin_free(char *s1, char *s2);

#endif
