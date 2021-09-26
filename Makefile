# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 15:21:51 by cjang             #+#    #+#              #
#    Updated: 2021/08/25 14:16:01 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_A = libft/libft.a

SRCS =			push_swap.c				main_common_function.c	push_swap_check_function.c	push_swap_simple_function.c	\
				quick_sort_main_tree.c	quick_sort_move_half.c	quick_sort_move_onethird.c	quick_sort_three.c \
				find_num_1.c				find_num_2.c		\
				game_rule.c				game_rule_command.c		\
				about_linked_list.c

SRCS_BONUS =	checker.c				main_common_function.c	push_swap_check_function.c	push_swap_simple_function.c	\
				checker_function.c	\
				game_rule.c				game_rule_command.c		\
				about_linked_list.c
				
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

all: $(NAME_PUSH_SWAP)
	
$(NAME_PUSH_SWAP): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJS) -o $(NAME_PUSH_SWAP)

$(LIBFT_A):
	make -C $(LIBFT)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_CHECKER): $(LIBFT_A) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJS_BONUS) -o $(NAME_CHECKER)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME_PUSH_SWAP) $(NAME_CHECKER)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY:
	all bonus clean fclean re
