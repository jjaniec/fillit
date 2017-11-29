# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 17:05:25 by jjaniec           #+#    #+#              #
#    Updated: 2017/11/29 21:08:25 by unicolai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

HEAD = fillit.h

SRCS = ft_read_content.c\
	   ft_parse_tetri.c\
	   ft_distribute_terminos.c\
	   ft_errordot.c\
	   ft_errorhashtag.c\
	   main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I $(HEAD) -c $(SRCS)
	$(MAKE) -C ./libft
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -I $(HEAD)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
