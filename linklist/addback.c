/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:17:26 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/02 23:19:31 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    addback(t_phil *ronowa)
{
    t_phil *tmp;
    tmp = ronowa;
    while (tmp->next)
        tmp = tmp->next;
    
}