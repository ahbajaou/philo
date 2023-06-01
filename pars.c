/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:55:55 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/01 08:02:33 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_atoi_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			ft_error();
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	j;

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
		j = (j * 10) + str[i] - '0';
		i++;
	}
	return (j * k);
}

int	check_pars(char **str)
{
	if (ft_atoi(str[2]) <= 60)
		return (1);
	if (ft_atoi(str[3]) <= 60)
		return (1);
	if (ft_atoi(str[1]) <= 0)
		return (1);
	return (0);
}
