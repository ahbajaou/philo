# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 00:20:56 by ahbajaou          #+#    #+#              #
#    Updated: 2023/05/26 21:31:19 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c 
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g
cc = gcc

 all : philo

 philo : $(SRC)
	$(cc) $(CFLAGS) $(SRC) -o philo
clean : 
	rm -rf philo
fclean : clean
re : fclean all 