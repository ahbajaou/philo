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
	 int left_fork = nami->index;
	 int right_fork = (nami->index + 1) % nami->philo;
	//  printf("left ==== %d right ===== %d\n",left_fork,right_fork);
	//  printf("index = %d\n",nami->index);
	 pthread_mutex_t *fracht;
	 fracht = malloc(sizeof(pthread_mutex_t));
	// printf(">>>>%d ---------%d\n",left_fork,right_fork);
	//  while (1)
	//  {
		pthread_mutex_lock(&fracht[left_fork]);
		printf("philo %d pick up fork %d\n",nami->index,left_fork);
		pthread_mutex_lock(&fracht[right_fork]);
		printf("philo %d pick up fork %d\n",nami->index,right_fork);

		printf("philo %d start eat\n",nami->index);
		pthread_mutex_unlock(&fracht[left_fork]);
		printf("philo %d pick down fork %d\n",nami->index,left_fork);
		pthread_mutex_unlock(&fracht[right_fork]);
		printf("philo %d pick down fork %d\n",nami->index,right_fork);

	//  }

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
                ronowa->index = 1;
				while (ronowa->index <= ft_atoi(av[1]))
				{
					pthread_mutex_init(&fracht[ronowa->index], NULL);
					ronowa->index++;
				}
				ronowa->index = 1;
                while (ronowa->index <= ft_atoi(av[1]))
                {
					ronowa[ronowa->index].philo = ft_atoi(av[1]);
					ronowa[ronowa->index].timedie = ft_atoi(av[2]);
					ronowa[ronowa->index].timeeat = ft_atoi(av[3]);
					ronowa[ronowa->index].timesleep = ft_atoi(av[4]);
					ronowa[ronowa->index].index = ronowa->index;
                    pthread_create(&ph[ronowa->index], NULL, &routine_life,&ronowa[ronowa->index]);
                    ronowa->index++;
                }
                ronowa->index = 1;
                while (ronowa->index <= ft_atoi(av[1]))
                {
                    pthread_join(ph[ronowa->index],NULL);
                    ronowa->index++;
                }
				ronowa->index = 1;
				while (ronowa->index <= ft_atoi(av[1]))
				{
					pthread_mutex_destroy(&fracht[ronowa->index]);
					ronowa->index++;
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