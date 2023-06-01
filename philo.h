/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:15:40 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/06/01 03:27:06 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <stdlib.h> 
# include <unistd.h>

typedef struct t_data{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*_print;
	pthread_mutex_t	*_eat;
	pthread_mutex_t	*_died;
	pthread_mutex_t	*_race;
	pthread_t		ph;
	int				philo;
	int				timeeat;
	int				timedie;
	int				timesleep;
	int				meal;
}t_data;

typedef struct t_philo{
	long long		time_start;
	long long		last_meal;
	int				nm_of_meal;
	int				ident;
	struct t_data	*data;
}t_philo;

long long	get_time(void);
void		sleepo(unsigned long t_sleep);
void		ft_tbe3(t_philo *philo, char *str);
void		ft_error(void);
int			ft_atoi(char *str);
void		ft_error(void);
void		died_1(t_philo *ronowa);
void		died_2(t_philo *ronowa);
void		stock(t_data *zoro, char **av, int ac);
void		stock_2(t_philo *ronowa, t_data *zoro, int nbr);
void		stock_3(t_data *zoro, int nbr);
void		check_pars(char **str);

#endif