# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachen <yachen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:01:12 by yachen            #+#    #+#              #
#    Updated: 2023/07/10 14:35:40 by yachen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

LIBFTDIR = ./new_libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

SRC =	push_swap.c push_swap_utils1.c push_swap_utils2.c parsing.c make_stack.c \
		instruction1.c instruction2.c instruction3.c search_outils.c \
		sort_to_a.c sort_to_b.c sort_to_a_case.c sort_to_b_case.c \

SRC_BONUS = checker.c make_stack.c push_swap_utils.c parsing.c \
			instruction.c sort_to_a.c sort_to_b.c search_outils.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS) 

$(NAME): $(OBJ)
	@make -C ./new_libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)/libft.a -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C ./new_libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFTDIR)/libft.a -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	cd $(LIBFTDIR) && make clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: clean fclean all re


