# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 14:18:26 by marvin            #+#    #+#              #
#    Updated: 2023/10/13 14:18:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_printf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_num_nosign.c \
		ft_punt_hexa.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_hexa_min.c \
		ft_hexa_mayus.c
OBJ=$(FT:%.c=%.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
%.o: %.c
	CC $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
	$(NAME)
.PHONY: clean bonus fclean re all
