# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <apineda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 14:15:48 by apineda           #+#    #+#              #
#    Updated: 2017/05/19 14:05:23 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILENAMES = fdf ft_put_map ft_put_line ft_draw_line
INCLUDE_DIR = ./inc

CC = gcc
AR = AR

CCFLAGS = -Wall -Wextra -Werror #-g #-fsanitize=address
INC = $(INCLUDE_DIR)
LIBFT = ./libft
LIBFT_A = libft.a
LIBFT_ALL = $(LIBFT)/$(LIBFT_A) 

MLX_CAP = ./mlx_capitan/minilibx_macos
MLX_A = libmlx.a
MLX_MAC = $(MLX_CAP)/$(MLX_A)
MLX_C_ALL = $(MLX_MAC) -framework OpenGL -framework Appkit


LIB_M_ALL = $(LIBFT_ALL) $(MLX_C_ALL)

SRC_1 = $(addprefix src/, $(addsuffix .c, $(FILENAMES)))

all: $(NAME)

$(NAME): $(SRC_1)
	@make -C libft
	@echo "\033[32mCompiled libft\033[0m"
	@make -C $(MLX_CAP)
	@echo "\033[32mCompiled mlx_macros\033[0m"
	@$(CC) -g -I $(INC) -I $(MLX_CAP) -I $(LIBFT)/includes $(LIB_M_ALL) $(SRC_1) -o $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"

clean:
	@make -C libft clean
	@make -C $(MLX_CAP) clean
	@echo "\033[31;1m libs cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@make -C $(MLX_CAP) clean
	@rm -f $(NAME)
	@echo "\033[31;1m$(NAME) and libs fcleaned\033[0m"

re: fclean all

.PHONY: clean
