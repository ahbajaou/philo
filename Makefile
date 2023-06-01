# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 00:20:56 by ahbajaou          #+#    #+#              #
#    Updated: 2023/06/01 02:35:48 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
SRC = philo.c tools.c died.c stock.c
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g
cc = gcc

 all : $(NAME)

 philo : $(SRC)
	$(cc) $(CFLAGS) $(SRC) -o philo
clean : 
	rm -rf philo
fclean : clean
re : fclean all 