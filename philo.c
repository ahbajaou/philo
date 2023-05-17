/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:21:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/14 22:04:55 by ahbajaou         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

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
	while (str[i])
	{
		if ((str[i] >= 'a' &&  str[i] <= 'z') || (str[i] >= 'A' &&  str[i] <= 'Z'))
			ft_error();
		i++;
	}
	i = 0;
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
void    *routine_life(void *r)
{
	t_phil *nami;
	// nami = malloc(sizeof(t_phil));
	 nami = (t_phil *)r;
	 pthread_mutex_t *fracht;
	 fracht = malloc(sizeof(pthread_mutex_t));
	 while (1)
	 {
		pthread_mutex_lock(&fracht[1]);
		printf("philo 1 pick up fork\n");
		pthread_mutex_lock(&fracht[3]);
		printf("philo 3 pick up fork\n");

		printf("philo 1 start eat\n");
		printf("philo 3 start eat\n");
		sleep(1);
		pthread_mutex_unlock(&fracht[1]);
		printf("philo 1 pick down fork\n");
		pthread_mutex_unlock(&fracht[3]);
		printf("philo 3 pick down fork\n");

	 }

	// (void)r;
	return (0);
}
int	main(int ac,char **av)
{
	int i;
	// int nb;
	// int *arr;
	t_phil *ronowa;
    pthread_t *ph;
	pthread_mutex_t *fracht;

	i = 1;
	ronowa = malloc(sizeof(t_phil) * ft_atoi(av[1]));
	ph = malloc(sizeof(pthread_t));
	fracht = malloc(sizeof(pthread_mutex_t));
		if (ac > 2)
			{
				// int p = 0;
				// while (p < ft_atoi(av[1]))
				// {
				// 		printf("====%d\n",ronowa->philo);
				// 		p++;
				// }
                int c = 1;
				while (c <= ft_atoi(av[1]))
				{
					pthread_mutex_init(&fracht[c], NULL);
					c++;
				}
				c = 1;
                while (c <= ft_atoi(av[1]))
                {
					ronowa[c].philo = ft_atoi(av[1]);
					ronowa[c].timedie = ft_atoi(av[2]);
					ronowa[c].timeeat = ft_atoi(av[3]);
					ronowa[c].timesleep = ft_atoi(av[4]);
                    pthread_create(&ph[c], NULL, &routine_life,&ronowa[c]);
                    c++;
                }
                c = 1;
                while (c <= ft_atoi(av[1]))
                {
                    pthread_join(ph[c],NULL);
                    c++;
                }
				c = 1;
				while (c <= ft_atoi(av[1]))
				{
					pthread_mutex_destroy(&fracht[c]);
					c++;
				}
                // printf("here we go\n");
			}
			// free(ph);
			// free(arr);
			// free(ronowa);
    return 0;
	// }
	// return (0);
}
// int counter = 0;
// pthrea   
// void  *routine()
// {
//     int i = 0;
//     // int counter = 0;
//     // ronowa->counter = 0;
//     while (i < 10000)
//     {
//         // ronowa->counter++;
//         pthread_mutex_lock(&mutex);
//         counter++;
//         i++;
//         pthread_mutex_unlock(&mutex);
//     }
//     return (0);
// }

// int main() 
// {
//     pthread_t arr[2];
//     pthread_mutex_init(&mutex,NULL);
//     int i = 0;
//     while ( i <= 2)
//     {
//         pthread_create(&arr[i], NULL, &routine, NULL);
//         i++;
//     }
//     i = 0;
//     while (i <= 2)
//     {
//         pthread_join(arr[i], NULL);
//         i++;
//     }
//     printf("value of counter is = %d\n",counter);
//     pthread_mutex_destroy(&mutex);
//     // pthread_create(&t2, NULL, &routine, NULL);
//     // pthread_join(t2, NULL);
//     return 0;
// }