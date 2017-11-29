# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 17:05:25 by jjaniec           #+#    #+#              #
#    Updated: 2017/11/29 18:50:28 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Werror -Wextra
NOFLAGS=

all:
	make -C libft/ fclean && make -C libft/
	clang $(NOFLAGS) -I libft/ -o ft_read_content.o -c ft_read_content.c
	clang $(NOFLAGS) -I libft/ -o ft_parse_tetri.o -c ft_parse_tetri.c
	clang $(NOFLAGS) -I libft/ -o ft_distribute_tetriminos.o -c ft_distribute_tetriminos.c
	clang $(NOFLAGS) -I libft/ -o ft_errordot.o -c ft_errordot.c
	clang $(NOFLAGS) -I libft/ -o ft_errorhashtag.o -c ft_errorhashtag.c
#	clang $(NOFLAGS) -I libft/ -o main.o -c main.c
	clang -o fillit ft_read_content.o ft_parse_tetri.o ft_distribute_tetriminos.o ft_errordot.o ft_errorhashtag.o -I libft/ -L libft/ -lft

clean:
	rm ./*.o

fclean:
	rm fillit

re: fclean all clean
