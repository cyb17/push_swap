# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bing <bing@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:01:12 by yachen            #+#    #+#              #
#    Updated: 2023/07/03 15:14:09 by bing             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFTDIR = ./new_libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRC =	push_swap.c push_swap_utils.c parsing.c instruction.c sort_to_b.c \
		sort_to_a.c search_outils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./new_libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	cd $(LIBFTDIR) && make clean

fclean:	clean
	$(RM) $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: clean fclean all re


