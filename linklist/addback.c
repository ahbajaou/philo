/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:17:26 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/21 15:45:49 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	addback(t_phil **list, t_phil *new)
{
	t_phil	*tmp;

	if ((*list) == NULL)
	{
		(*list) = new;
		new->next = (*list);
	}
	else
	{
		tmp = (*list);
		while (tmp->next != (*list))
			tmp = tmp->next;
		tmp->next = new;
		new->next = (*list);
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