/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:17:26 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/21 02:37:22 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	addback(t_phil **list, t_phil *new)
{
	t_phil	*tmp;
	tmp = (*list);
	if ((*list) == NULL)
	{
		printf("ARGSEGRESHRE\n");
		(*list) = new;
	}
	else
	{
		while ((*list)->next != NULL)
		{
			(*list) = (*list)->next;
		}
		(*list)->next = new;
		(*list) = tmp;
	}
}
t_phil	*add_to_list(t_phil *philowat)
{
	int	i;

	i = 1;
	t_phil *creat_new_link = NULL;
	while (i <= philowat->philo)
	{
		addback(&creat_new_link, create_list(i, philowat));
		i++;
	}
	return (creat_new_link);
}