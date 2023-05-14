/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:15:40 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/13 02:51:50 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct t_phil{

    int *arr;
    int philo;
    int timeeat;
    int timedie;
    int timesleep;
    int counter;
    int data;
    struct t_phil *next;
}t_phil;

#include <stdio.h>
#include <stdlib.h>


t_phil *create_list(int nb);


#endif