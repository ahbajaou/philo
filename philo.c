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
t_phil stock_param(t_phil ronowa,char **av,int ac)
{
		ronowa.philo = ft_atoi(av[1]);
		ronowa.timedie = ft_atoi(av[2]);
		ronowa.timeeat = ft_atoi(av[3]);
		ronowa.timesleep = ft_atoi(av[4]);
	if (ac == 6)
		ronowa.timet = ft_atoi(av[5]);
	return (ronowa);
}
void	*routine(void *arg)
{
	
	t_phil *ronowa;
	ronowa = (t_phil *)arg;
	printf(">>>>>%d\n", ronowa->data);

	return (0);
}
int main(int ac,char **av)
{
	t_phil *tmp;
	t_phil *philo;
	t_phil ronowa;

	tmp = NULL;
	philo = NULL;
	int i = 1;
	if (ac == 5 || ac == 6)
	{
	
		ronowa = stock_param(ronowa,av,ac);
		// t_phil *creat_new_link = NULL;
		philo =  add_to_list(&ronowa);
		tmp = philo;
		while (tmp != NULL)
		{
			printf("data >>>>>>>>>> %d\n", tmp->data);
			tmp = tmp->next;
		}
		
		// printf("here\n");
		// printf("philo_num >>>>>%d\n", philowat->philo);
		tmp = philo;
		while (i <= ronowa.philo)
		{
			pthread_mutex_init(&tmp->fork,NULL);
			tmp = tmp->next;
			i++;
		}
		i = 1;
		tmp = philo;
		printf("philo >>>>>>>>>>>>>>>> %d\n", tmp->philo);
		while (i <= ronowa.philo)
		{
			pthread_create(&tmp->ph, NULL, &routine, tmp);
			tmp = tmp->next;
			i++;
		}
		i = 1;
		tmp = philo;
		while (i <= ronowa.philo)
		{
			pthread_join(tmp->ph,NULL);
			tmp = tmp->next;
			i++;
		}
		tmp = philo;
		i = 1;
		while (i <= ronowa.philo)
		{
			pthread_mutex_destroy(&tmp->fork);
			tmp = tmp->next;
			i++;
		}
		tmp = philo;
		// while (tmp)
		// {
		// 		printf("philo = %d\n",tmp->data);
		// 		tmp = tmp->next;
		// }
		while(1);
	}
	return (0);
}