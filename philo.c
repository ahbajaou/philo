/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:08:51 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/11 04:23:37 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_2(t_philo *ronowa, int left, int right)
{
	sleepo(ronowa->data->timeeat);
	pthread_mutex_unlock(&ronowa->data->fork[left]);
	pthread_mutex_unlock(&ronowa->data->fork[right]);
	ft_print(ronowa, "is sleeping");
	sleepo(ronowa->data->timesleep);
	pthread_mutex_lock(ronowa->data->_eat);
	ronowa->nm_of_meal++;
	pthread_mutex_unlock(ronowa->data->_eat);
	ft_print(ronowa, "is thinking");
}

void	*routine_life(void *arg)
{
	t_philo	*ronowa;
	int		left;
	int		right;

	ronowa = (t_philo *)arg;
	left = ronowa->ident;
	right = (ronowa->ident + 1) % ronowa->data->philo;
	while (1)
	{
		pthread_mutex_lock(&ronowa->data->fork[left]);
		pthread_mutex_lock(ronowa->data->_race);
		if (ronowa->nm_of_meal == ronowa->data->meal)
			break ;
		pthread_mutex_unlock(ronowa->data->_race);
		ft_print(ronowa, "has taken a fork");
		pthread_mutex_lock(&ronowa->data->fork[right]);
		ft_print(ronowa, "has taken a fork");
		ft_print(ronowa, "is eating");
		pthread_mutex_lock(ronowa->data->_died);
		ronowa->last_meal = get_time();
		pthread_mutex_unlock(ronowa->data->_died);
		routine_2(ronowa, left, right);
	}
	return (0);
}

void	to_routine_two(t_philo *ronowa)
{
	int	i;

	i = 0;
	while (i < ronowa->data->philo)
	{
		if (i % 2 == 0)
		{
			pthread_create(&ronowa[i].data->ph,
				NULL, &routine_life, &ronowa[i]);
			pthread_detach(ronowa[i].data->ph);
		}
		i++;
	}
	// sleepo(100);
	usleep(500);
	i = 0;
	while (i < ronowa->data->philo)
	{
		if (i % 2 == 1)
		{
			pthread_create(&ronowa[i].data->ph,
				NULL, &routine_life, &ronowa[i]);
			pthread_detach(ronowa[i].data->ph);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*ronowa;
	t_data	*zoro;

	if (ac >= 0 && ac <= 4)
		return (ft_error());
	if (check_pars(av, ac) == 1)
		return (0);
	ronowa = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	zoro = malloc(sizeof(t_data) * ft_atoi(av[1]));
	stock_3(zoro, ft_atoi(av[1]));
	if (ac == 5 || ac == 6)
	{
		stock(zoro, av, ac);
		stock_2(ronowa, zoro, ft_atoi(av[1]));
		to_routine_two(ronowa);
		while (1)
		{
			if (died_2(ronowa) == 1)
				break ;
			if (died_1(ronowa) == 1)
				break ;
		}
	}
	return (0);
}
