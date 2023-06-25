# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:01:12 by yachen            #+#    #+#              #
#    Updated: 2023/06/21 14:34:13 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

LIBFTNAME = libft.a

LIBFTDIR = ./new_libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = push_swap.c push_swap_utils.c parsing.c instruction.c sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

makelibft: 
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJ)
	ar rcs $(NAME) $(OBJ)

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


