/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:57:09 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/28 05:36:01 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
} 

long long	get_time()
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
	while (((get_time() - start_time)) < t_sleep);
}

void	ft_tbe3(t_philo *philo,char *str)
{
	pthread_mutex_lock(philo->data->_print);
	if (str[0] == 'm')
		exit(0);
	printf("%lld %d %s\n",get_time() - philo->time_start, philo->ident + 1, str);
	if (str[3] == 'd')
		exit(0);
	pthread_mutex_unlock(philo->data->_print);
}