/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:21:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/04 21:45:17 by ahbajaou         ###   ########.fr       */
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

int	main(int ac,char **av)
{
	int i;
	int nb;
	int *arr;
	t_phil *ronowa;

	i = 1;
	ronowa = malloc(sizeof(t_phil));
	arr = malloc(sizeof(int) * ac);

		if (ac <= 6)
			{
					// printf("%d\n",nb);
				while (i < ac)
				{
					nb = ft_atoi(av[i]);
					arr[i] = nb;
					i++;
				}
				ronowa->philo = arr[1];
				ronowa->timedie = arr[2];
				ronowa->timeeat = arr[3];
				ronowa->timesleep = arr[4];
				printf(">>%d\n",ronowa->philo);
			}
	// }
	// return (0);
}