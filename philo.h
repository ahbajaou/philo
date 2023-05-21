/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:15:40 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/21 02:38:10 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct brok_t{
   
    // pthread_t *phil;
    // pthread_mutex_t *chops;

}brok_t;

typedef struct t_phil{

    struct brok_t *soul;
    pthread_mutex_t fork;
    pthread_t   ph;
    int id;
    int philo;
    int index;
    int timeeat;
    int timedie;
    int timesleep;
    int timet;
    int data;
    struct t_phil *next;
}t_phil;




t_phil *create_list(int nb, t_phil *philowat);
// t_phil *addback(t_phil *list, t_phil *new);
void	addback(t_phil **list, t_phil *new);
t_phil	*add_to_list(t_phil *philowat);

#endif