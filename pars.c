/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:55:55 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/03 15:32:27 by ahbajaou         ###   ########.fr       */
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
	if (ft_atoi(str[0]) <= 0 || ft_atoi(str[0]) >= 201)
		return (1);
	if (ft_atoi(str[1]) < 60)
		return (1);
	if (ft_atoi(str[2]) < 60)
		return (1);
	if (ft_atoi(str[3]) < 60)
		return (1);
	return (0);
}

int	check_pars_3(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				return (1);
			if ((str[i][j] >= 'a' && str[i][j] <= 'z')
				|| (str[i][j] >= 'A' && str[i][j] <= 'Z'))
				return (1);
			if (str[i][j] != ' ' && str[i][j + 1] == '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free2d(char **d)
{
	int	i;

	i = 0;
	while (d[i] != NULL)
	{
		free(d[i]);
		i++;
	}
	free(d);
}

int	check_pars(char **data, int ac)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = NULL;
	while (i < ac)
	{
		tmp = ft_strjoin(tmp, data[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	data = ft_split(tmp, ' ');
	free(tmp);
	if (check_pars_3(data) == 1)
	{
		free2d(data);
		return (ft_error());
	}
	if (check_pars_2(data) == 1)
	{
		free2d(data);
		return (ft_error());
	}
	free2d(data);
	return (0);
}
