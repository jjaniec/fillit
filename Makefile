# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 17:05:25 by jjaniec           #+#    #+#              #
#    Updated: 2017/11/28 15:37:33 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Werror -Wextra
NOFLAGS=

all:
	make -C libft/ fclean && make -C libft/
	clang $(NOFLAGS) -I libft/ -o ft_read_content.o -c ft_read_content.c
#	clang $(NOFLAGS) -I libft/ -o main.o -c main.c
	clang -o fillit ft_read_content.o -I libft/ -L libft/ -lft

clean:
	rm ./*.o

fclean:
	rm fillit

re: fclean all clean
