/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 02:57:09 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/06 20:32:01 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->_print);
	if (str[0] == 'm')
		return (1);
	printf("%lld %d %s\n", get_time() - philo->time_start,
		philo->ident + 1, str);
	if (str[0] == 'd')
		return (1);
	pthread_mutex_unlock(philo->data->_print);
	return (0);
}
