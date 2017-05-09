# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <apineda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 14:15:48 by apineda           #+#    #+#              #
#    Updated: 2017/05/08 19:17:49 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILENAMES = main
INCLUDE_DIR = ./inc

CC = gcc
AR = AR

CCFLAGS = -Wall -Wextra -Werror
INC = $(INCLUDE_DIR)
LIBFT = ./libft
LIBFT_A = libft.a
LIBFT_ALL = $(LIBFT)/$(LIBFT_A) 

MLX = ./mlx_macros
MLX_A = ./libmlx.a
MLX_ALL = $(MLX)/$(MLX_A) -framework OpenGL -framework Appkit

FT_PRINTF = ./ft_printf
FT_PRINTF_A = libftprintf.a
FT_PRINTF_ALL = $(FT_PRINTF)/$(FT_PRINTF_A)

LIB_ALL = $(LIBFT_ALL) $(MLX_ALL) $(FT_PRINTF_ALL)

SRC_1 = $(addprefix src/, $(addsuffix .c, $(FILENAMES)))
OBJ_1 =	$(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(SRC_1)
	@make -C libft
	@echo "\033[32mCompiled libft\033[0m"
	@make -C ft_printf
	@echo "\033[32mCompiled ft_printf\033[0m"
	@make -C mlx_macros
	@echo "\033[32mCompiled mlx_macros\033[0m"
	@$(CC) -g -I$(INC) $(LIB_ALL) $(SRC_1) -o $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"

clean:
	@make -C libft clean
	@make -C ft_printf clean
	@make -C mlx_macros clean
	@echo "\033[31;1m libs cleaned\033[0m"

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@rm -f $(NAME)
	@echo "\033[31;1m$(NAME) and libs fcleaned\033[0m"

re: fclean all

.PHONY: clean
