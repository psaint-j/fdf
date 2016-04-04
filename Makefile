# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 17:43:28 by psaint-j          #+#    #+#              #
#    Updated: 2016/04/04 17:49:47 by psaint-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =	./src/fdf.c\
		./src/ft_cordo.c\
		./src/ft_draw.c\
		./src/ft_free.c\
		./src/ft_init.c\
		./src/ft_key_hook.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK_FLAG = -L./mlx -lft -L./libft -lft \
			-lmlx -framework OpenGL -framework AppKit

.PHONY: $(NAME) all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir obj
	@make -sC libft/
	@make -sC mlx/
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LINK_FLAG) -g3
	@mv $(OBJ) obj
	@echo "FDF COMPILATION DONE"

clean:
	@rm -rf obj
	@make clean -sC libft/
	@make clean -sC mlx/
	@rm -rf $(NAME)
	@rm -rf *.o
	@echo "FDF CLEAN DONE"

fclean: clean
	@make fclean -sC libft/
	@rm -rf $(NAME)
	@echo "FDF FCLEAN DONE"

re: fclean $(NAME)
