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
		pthread_mutex_lock(ronowa->data->_eat);
		ronowa->nm_of_meal++;
		pthread_mutex_unlock(ronowa->data->_eat);
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
		// if (ronowa->data->meal == 0)
		// 	exit(1);
		if (ronowa->data->meal != -1)
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
			// pthread_mutex_lock(ronowa->data->_died); 
			if ( get_time() - ronowa[i].last_meal >= ronowa->data->timedie)
			{
				ft_tbe3(ronowa, "is dead");
				pthread_mutex_unlock(ronowa->data->_died);
				pthread_mutex_destroy(ronowa->data->_died);
				exit(1);
			}
			pthread_mutex_unlock(ronowa->data->_died);
			pthread_mutex_destroy(ronowa->data->_died);
			i++;
		}
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
	int i;
	t_philo *ronowa;
	t_data *zoro;

	check_pars(av);
	int nbr = ft_atoi(av[1]);
	ronowa = malloc(sizeof(t_philo) * nbr);
	zoro = malloc(sizeof(t_data) * nbr);
	zoro->fork = malloc(sizeof(pthread_mutex_t ) * nbr);
	zoro->_print = malloc(sizeof(pthread_mutex_t));
	zoro->_eat = malloc(sizeof(pthread_mutex_t));
	zoro->_died = malloc(sizeof(pthread_mutex_t));

	i = -1;
		if (ac == 5 || ac == 6)
		{
			while (++i < nbr)
				pthread_mutex_init(&zoro->fork[i], NULL);
			pthread_mutex_init(zoro->_print,NULL);
			pthread_mutex_init(zoro->_eat,NULL);
			pthread_mutex_init(zoro->_died,NULL);

			zoro->philo = ft_atoi(av[1]);
			zoro->timedie = ft_atoi(av[2]);
			zoro->timeeat = ft_atoi(av[3]);
			zoro->timesleep = ft_atoi(av[4]);
			zoro->meal = -1;
			if (ac == 6)
			{
					zoro->meal = ft_atoi(av[5]);
					if (zoro->meal == 0)
						exit(0);
			}
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
			to_routine_two(ronowa);
			// pthread_mutex_lock(ronowa->data->_eat);
			check_dead_phil(ronowa);
			// pthread_mutex_destroy(ronowa->data->_died);
			// pthread_mutex_unlock(ronowa->data->_eat);
		

		
		}
    return 0;
}
