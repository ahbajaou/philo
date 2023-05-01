/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:21:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/01 21:03:54 by ahbajaou         ###   ########.fr       */
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
// char *ft_itoa(int nb)
// {
// 	int nbr;
// 	int len;
// 	char *res;

// 	len = 0;
// 	nbr = nb;
// 	if (nb < 0)
// 		len++;
// 	while (nbr)
// 	{
// 		nbr /= 10;
// 		len++;
// 	}
// 	res = malloc(sizeof(char ) * len + 1);
// 	if (!res)
// 		return (NULL);
// 	res[len] = '\0';
// 	if (nb == 0)
// 		{
// 			res[0] = '0';
// 			return (res);
// 		}
// 	if (nb < 0)
// 	{
// 		res[0] = '-';
// 		nb = -nb;
// 	}
// 	while (nb)
// 	{
// 		res[--len] = nb % 10 + '0';
// 		nb /= 10;
// 	}
// 	return (res);
// }
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
					printf(">>>>>%d\n",arr[i]);
					// printf("here\n");
					i++;
				}
		
			}
	// }
	// return (0);
}