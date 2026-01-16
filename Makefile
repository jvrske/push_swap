# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 09:27:45 by csilva            #+#    #+#              #
#    Updated: 2026/01/15 14:52:45 by csilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

INCLUDE = -I/checker/include -I/get_next_line

CFLAGS = -Wall -Wextra -Werror -g

SRC =	push_swap_algorithm_utils.c \
		push_swap_algorithm.c \
		push_swap_chunk.c \
		push_swap_indexing.c \
		push_swap_initstack.c \
		push_swap_op_push.c \
		push_swap_op_rotate.c \
		push_swap_op_rrotate.c \
		push_swap_op_swap.c \
		push_swap_parser.c \
		push_swap_tiny_utils.c \
		push_swap_tinysort.c \
		push_swap_utils.c \
		push_swap.c

SRC_BONUS = push_swap_algorithm_utils.c \
		push_swap_algorithm.c \
		push_swap_chunk.c \
		push_swap_indexing.c \
		push_swap_initstack.c \
		push_swap_op_push.c \
		push_swap_op_rotate.c \
		push_swap_op_rrotate.c \
		push_swap_op_swap.c \
		push_swap_parser.c \
		push_swap_tiny_utils.c \
		push_swap_tinysort.c \
		push_swap_utils.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./bonus/src/push_swap_checker.c \
		./bonus/src/push_swap_checkerutils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re

BONUS = checker

bonus : all checker

checker : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^