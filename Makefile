# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/05 16:18:14 by aaudiber          #+#    #+#              #
#    Updated: 2016/02/02 14:26:51 by psaint-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./src/*.c\

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra
MLX = -I./mlx/ -lmlx -framework openGL -framework appKit
all : $(NAME)

$(NAME):
	@echo "\033[42;1m" Compilating Sources "\033[0m"
	@make -C ./libft
	@make -C ./mlx
	@echo "\033[42;1m" Done "\033[0m"
	@echo "\033[42;1m" Creating Executable "\033[0m"
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(MLX) -I./libft/includes/ ./libft/libft.a
	@echo "\033[42;1m" Done "\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
