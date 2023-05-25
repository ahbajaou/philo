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
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>



void	ft_error(void)
{
	write(1,"Error\n",6);
	exit(0);
}
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
long long get_time()
{
	struct timeval weqt;
	gettimeofday(&weqt,NULL);
	return (weqt.tv_sec * 1000 + weqt.tv_usec / 1000);
}

void	sleepo(unsigned long t_sleep)
{
	unsigned long	start_time;

	start_time = get_time();
	usleep(t_sleep);
	while (((get_time() - start_time)) < t_sleep)
		;
}
void	ft_tbe3(t_philo *philo,char *str)
{
	pthread_mutex_lock(philo->data->_print);
	printf("%lld %d %s\n",get_time() - philo->time_start, philo->ident + 1, str);
	pthread_mutex_unlock(philo->data->_print);
}
void *routine_life(void *arg)
{
	t_philo *ronowa;

	ronowa = (t_philo *)arg;
	int left = ronowa->ident;
	int right = (ronowa->ident + 1) % ronowa->data->philo;
	while (1)
	{
		pthread_mutex_lock(&ronowa->data->fork[left]);
		ft_tbe3(ronowa,"took frok");
		pthread_mutex_lock(&ronowa->data->fork[right]);
		ft_tbe3(ronowa,"took frok");
		ft_tbe3(ronowa,"start eat");
		ronowa->last_meal = get_time();
		sleepo((unsigned long)ronowa->data->timeeat);
		pthread_mutex_unlock(&ronowa->data->fork[left]);
		pthread_mutex_unlock(&ronowa->data->fork[right]);
		ronowa->nm_of_meal++;
		ft_tbe3(ronowa,"sleep");
		sleepo((unsigned long)ronowa->data->timesleep);
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
			pthread_create(&ronowa[i].data->ph, NULL, &routine_life, &ronowa[i]);
		i++;
	}
	usleep(500);
	i = 0;
	while (i < ronowa->data->philo)
	{
		if (i % 2 == 1)
			pthread_create(&ronowa[i].data->ph, NULL, &routine_life, &ronowa[i]);
		i++;
	}
}

void	check_dead_phil(t_philo *ronowa)
{
	int j = 0;
	int i;
	while (1)
	{
		i = 0;
		if (ronowa->data->meal == 0)
			exit(1);
		else if (ronowa->data->meal != -1)
		{
			while (i < ronowa->data->philo)
			{
				if (ronowa[i].nm_of_meal >= ronowa->data->meal)
					j++;
				if (j == ronowa->data->philo)
					exit (1);
				i++;
			}
		}
		i = 0;
		while (i < ronowa->data->philo)
		{
			if (get_time() - ronowa[i].last_meal >= ronowa->data->timedie)
			{
				ft_tbe3(ronowa, "is dead");
				exit(1);
			}
			i++;
		}
	}
}

int	main(int ac,char **av)
{
	int i;
	t_philo *ronowa;
	t_data *zoro;

	int nbr = ft_atoi(av[1]);
	ronowa = malloc(sizeof(t_philo) * nbr);
	zoro = malloc(sizeof(t_data) * nbr);
	zoro->fork = malloc(sizeof(pthread_mutex_t ) * nbr);
	zoro->_print = malloc(sizeof(pthread_mutex_t));
	zoro->_eat = malloc(sizeof(pthread_mutex_t));

	i = -1;
		if (ac == 5 || ac == 6)
		{
			while (++i < nbr)
				pthread_mutex_init(&zoro->fork[i], NULL);
			pthread_mutex_init(zoro->_print,NULL);
			pthread_mutex_init(zoro->_eat,NULL);
			if (ft_atoi(av[1]) == 0)
				return (0);
			zoro->philo = ft_atoi(av[1]);
			zoro->timedie = ft_atoi(av[2]);
			zoro->timeeat = ft_atoi(av[3]);
			zoro->timesleep = ft_atoi(av[4]);
			zoro->meal = -1;
			if (ac == 6)
					zoro->meal = ft_atoi(av[5]);
			i = 0;
			while (i < nbr)
			{
				ronowa[i].last_meal = get_time();
				ronowa[i].time_start = get_time();
				ronowa[i].ident = i;
				ronowa[i].nm_of_meal = 0;
				ronowa[i].data = zoro;
				i++; 
			}
			to_routine_two(ronowa);
			check_dead_phil(ronowa);
		}
    return 0;
}
