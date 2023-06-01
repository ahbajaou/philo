/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:55:55 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/01 10:10:11 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + str[i] - '0';
		i++;
	}
	return (j * k);
}

int	check_pars_2(char **str)
{
	if (ft_atoi(str[2]) < 60)
		return (1);
	if (ft_atoi(str[3]) < 60)
		return (1);
	if (ft_atoi(str[4]) < 60)
		return (1);
	if (ft_atoi(str[1]) <= 0 || ft_atoi(str[1]) >= 201)
		return (1);
	return (0);
}

int	check_pars(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= 'a' && str[i][j] <= 'z')
				|| (str[i][j] >= 'A' && str[i][j] <= 'Z'))
				return (ft_error());
			if (str[i][j] == ' ' || str[i][j] == '\t')
				return (ft_error());
			if (str[i][j] == '-')
				return (ft_error());
			if (str[i][j] != ' ' && str[i][j + 1] == '+')
				return (ft_error());
			j++;
		}
		i++;
	}
	if (check_pars_2(str) == 1)
		return (ft_error());
	return (0);
}
