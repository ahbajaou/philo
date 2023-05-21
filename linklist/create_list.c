/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:05:42 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/21 02:39:14 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_phil	*create_list(int nb, t_phil *philowat)
{
	t_phil	*new;
	new = malloc(sizeof(t_phil));
	new->data = nb;
	new->philo = philowat->philo;
	new->next = NULL;
	return (new);
}