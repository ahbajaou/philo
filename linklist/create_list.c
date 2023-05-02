/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:05:42 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/02 23:13:50 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_phil *create_list(int nb)
{
    t_phil *tmp;
    tmp = malloc(sizeof(t_phil));
    tmp->data = nb;
    tmp->next = NULL;
    return (tmp);
}
