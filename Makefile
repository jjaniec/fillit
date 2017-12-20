# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 17:05:25 by jjaniec           #+#    #+#              #
#    Updated: 2017/12/20 19:44:28 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

HEAD = fillit.h

SRCS = ft_read_content.c \
	   ft_count_tetris.c \
	   ft_parse_tetri.c \
	   ft_distribute_tetriminos.c \
	   ft_pass_tests.c \
	   ft_errordot.c \
	   ft_errorhashtag.c \
	   ft_upleft.c \
	   main.c

OBJ = $(SRCS:.c=.o)
T_COUNT = 5

all: $(NAME)

$(NAME): map
	gcc $(CFLAGS) -I $(HEAD) -c $(SRCS)
	gcc $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

map:
	./map_generator $(T_COUNT)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
