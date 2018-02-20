# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 20:31:14 by jjaniec           #+#    #+#              #
#    Updated: 2017/12/20 20:38:13 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_NAME = backtracking.c \
		   ft_count_tetris.c \
		   ft_distribute_tetriminos.c \
		   ft_errordot.c \
		   ft_errorhashtag.c \
		   ft_fillit_sqrt.c \
		   ft_generate_map.c \
		   ft_map_len.c \
		   ft_next_possibility.c \
		   ft_parse_tetri.c \
		   ft_pass_tests.c \
		   ft_print_usage.c \
		   ft_read_content.c \
		   ft_strjoin_free.c \
		   ft_upleft.c \
		   main.c

SRC_DIR = ./srcs/
INCLUDES_DIR = ./includes/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./libft -I./$(INCLUDES_DIR)
LFLAGS = -L./libft/ -lft
LIBFT = ./libft/libft.*

T_COUNT = 5

all : $(NAME)

.PHONY : all clean map

$(NAME) : $(OBJ)
	make -C ./libft/
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $(IFLAGS) $^ -o $@

map:
	./map_generator $(T_COUNT)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME) map.fillit

re: fclean all
