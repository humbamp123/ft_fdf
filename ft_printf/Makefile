# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 14:15:48 by apineda           #+#    #+#              #
#    Updated: 2017/03/12 19:37:28 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILENAMES = ft_printf.c printf_std.c ft_libfunct_1.c ft_libfunct_2.c \
			ft_libfunct_3.c ft_libfunct_4.c ft_libfunct_5.c vasprintf.c \
			ft_printf_s.c ft_printf_d.c ft_printf_p.c ft_printf_u.c \
			ft_printf_c.c ft_printf_o.c ft_printf_x.c ft_printf_flags.c \
			ft_width.c ft_printf_per.c ft_printf_cap_s.c

INCLUDE_DIR = ./includes

CC = gcc
AR = ar

CCFLAGS = -Wall -Wextra -Werror
INC = -I $(INCLUDE_DIR)

SOURCES_1 = $(addprefix srcs/, $(FILENAMES))
OBJECTS_1 = $(addprefix objs/, $(FILENAMES:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS_1)
	@$(AR) rc $@ $^
	@ranlib $@
	@echo "libftprintf compiled!"

objs:
	@mkdir $@

objs/%.o: srcs/%.c | objs
	@$(CC) $(CCFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf objs

fclean: clean
	@rm -f test_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
