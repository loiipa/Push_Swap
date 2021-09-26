# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 15:26:15 by cjang             #+#    #+#              #
#    Updated: 2021/08/28 17:09:40 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = g++

SRCS = random.cpp

NAME = rand
NAME_PUSH_SWAP = ../push_swap
NAME_CHECKER = ../checker

all: $(NAME) $(NAME_PUSH_SWAP)

$(NAME): $(SRCS)
	$(CPP) $(SRCS) -o $(NAME)

$(NAME_PUSH_SWAP):
	make -C ../
	make clean -C ../

bonus: $(NAME) $(NAME_CHECKER)

$(NAME_CHECKER):
	make bonus -C ../
	make clean -C ../

clean:
	rm -f $(NAME)

re: clean all

.PHONY:
	all bonus clean fclean re
