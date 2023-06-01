/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   philo->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:21:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/19 16:20:37 by ahbajaou         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 1;
	j = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' &&  str[i] <= 'z') || (str[i] >= 'A' &&  str[i] <= 'Z'))
			ft_error();
		i++;
	}
	i = 0;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			k *= -1;
			ft_error();
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j *= 10;
		j = j + str[i] - '0';
		i++;
	}
	return (j * k);
}

void *routine_life(void *arg)
{
	t_philo *ronowa;
	int left;
	int right;

	ronowa = (t_philo *)arg;
	left = ronowa->ident;
	right = (ronowa->ident + 1) % ronowa->data->philo;
	while (1)  
	{
		pthread_mutex_lock(&ronowa->data->fork[left]);
		pthread_mutex_lock(ronowa->data->_race);
		if (ronowa->nm_of_meal == ronowa->data->meal)
			break;
		pthread_mutex_unlock(ronowa->data->_race);
		ft_tbe3(ronowa,"took frok");
		pthread_mutex_lock(&ronowa->data->fork[right]);
		ft_tbe3(ronowa,"took frok");
		ft_tbe3(ronowa,"start eat");
		pthread_mutex_lock(ronowa->data->_died);
		ronowa->last_meal = get_time();
		pthread_mutex_unlock(ronowa->data->_died);
		sleepo((unsigned long)ronowa->data->timeeat);
		pthread_mutex_unlock(&ronowa->data->fork[left]);
		pthread_mutex_unlock(&ronowa->data->fork[right]);
		ft_tbe3(ronowa,"sleep");
		sleepo((unsigned long)ronowa->data->timesleep);
		pthread_mutex_lock(ronowa->data->_eat);
		ronowa->nm_of_meal++;
		pthread_mutex_unlock(ronowa->data->_eat);
		ft_tbe3(ronowa,"think");
	}
	return (0);
}
void	to_routine_two(t_philo *ronowa)
{
	int i;

	i = 0;
	while (i < ronowa->data->philo)
	{
		if (i % 2 == 0)
		{
			pthread_create(&ronowa[i].data->ph, NULL, &routine_life, &ronowa[i]);
			pthread_detach(ronowa[i].data->ph);
		}
		i++;
	}
	usleep(500);
	i = 0;
	while (i < ronowa->data->philo)
	{
		if (i % 2 == 1)
		{
			pthread_create(&ronowa[i].data->ph, NULL, &routine_life, &ronowa[i]);
			pthread_detach(ronowa[i].data->ph);
		}
		i++;
	}
}


void	check_pars(char **str)
{

	if (ft_atoi(str[2]) <= 60)
		exit(0);	
	if (ft_atoi(str[3]) <= 60)
		exit(0);
	if (ft_atoi(str[1]) <= 0)
		exit(0);
}
	
int	main(int ac,char **av)
{
	t_philo *ronowa;
	t_data *zoro;

	ronowa = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	zoro = malloc(sizeof(t_data) * ft_atoi(av[1]));
	check_pars(av);
	stock_3(zoro,ft_atoi(av[1]));
	if (ac == 5 || ac == 6)
	{
		stock(zoro,av,ac);
		stock_2(ronowa, zoro,ft_atoi(av[1]));
		to_routine_two(ronowa);
		while (1)
		{
			died_2(ronowa);
			died_1(ronowa);
		}
	}
	return 0;
}
