/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:32:44 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/07 01:13:35 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stock(t_data *zoro, char **av, int ac)
{
	int	i;
	int	nbr;

	nbr = ft_atoi(av[1]);
	i = -1;
	while (++i < nbr)
		pthread_mutex_init(&zoro->fork[i], NULL);
	pthread_mutex_init(zoro->_print, NULL);
	pthread_mutex_init(zoro->_eat, NULL);
	pthread_mutex_init(zoro->_died, NULL);
	pthread_mutex_init(zoro->_race, NULL);
	zoro->philo = ft_atoi(av[1]);
	zoro->timedie = ft_atoi(av[2]);
	zoro->timeeat = ft_atoi(av[3]);
	zoro->timesleep = ft_atoi(av[4]);
	zoro->meal = -1;
	if (ac == 6)
	{
		zoro->meal = ft_atoi(av[5]);
		if (zoro->meal == 0)
			return ;
	}
}

void	stock_2(t_philo *ronowa, t_data *zoro, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		ronowa[i].time_start = get_time();
		ronowa[i].ident = i;
		ronowa[i].nm_of_meal = 0;
		ronowa[i].data = zoro;
		ronowa[i].last_meal = get_time();
		i++;
	}
}

void	stock_3(t_data *zoro, int nbr)
{
	zoro->fork = malloc(sizeof(pthread_mutex_t) * nbr);
	zoro->_eat = malloc(sizeof(pthread_mutex_t));
	zoro->_died = malloc(sizeof(pthread_mutex_t));
	zoro->_print = malloc(sizeof(pthread_mutex_t));
	zoro->_race = malloc(sizeof(pthread_mutex_t));
}
