/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 05:05:10 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/01 03:22:40 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died_1(t_philo *ronowa)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pthread_mutex_lock(ronowa->data->_eat);
	if (ronowa->data->meal != -1)
	{
		while (i < ronowa->data->philo)
		{
			if (ronowa[i].nm_of_meal >= ronowa->data->meal)
				j++;
			if (j == ronowa->data->philo)
			{
				pthread_mutex_unlock(ronowa->data->_eat);
				ft_tbe3(ronowa, "meal");
			}
			i++;
		}
	}
	pthread_mutex_unlock(ronowa->data->_eat);
}

void	died_2(t_philo *ronowa)
{
	int	i;

	i = 0;
	while (i < ronowa->data->philo)
	{
		pthread_mutex_lock(ronowa->data->_died);
		if (get_time() - ronowa[i].last_meal >= ronowa->data->timedie)
		{
			if (ronowa[i].nm_of_meal == ronowa->data->meal)
			{
				pthread_mutex_unlock(ronowa->data->_race);
				break ;
			}
			ft_tbe3(ronowa, "is dead");
			pthread_mutex_unlock(ronowa->data->_died);
		}
		pthread_mutex_unlock(ronowa->data->_died);
		i++;
	}
}
