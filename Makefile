# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 00:20:56 by ahbajaou          #+#    #+#              #
#    Updated: 2023/05/21 02:27:55 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = philo.c linklist/*.c
# CFLAGS = -Wall -Wextra -Werror -lpthread #-fsanitize=address -g3
cc = gcc

 all : philo

 philo : $(SRC)
	$(cc) $(CFLAGS) -pthread $(SRC) -o philo
clean : 
	rm -rf philo
fclean : clean
re : fclean all