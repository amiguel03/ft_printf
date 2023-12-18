# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 15:11:25 by amiguel-          #+#    #+#              #
#    Updated: 2023/12/12 11:58:12 by amiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		ft_printf.c	\
		ft_printf_utils.c

OBJ=$(FT:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)