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
	// int i = 1;
    int philo = *(int *)r;
	// pthread_mutex_t *fracht;
	// fracht = malloc(sizeof(pthread_mutex_t) * 5);
	(void)philo;
	t_phil *ronowa;
	ronowa = malloc(sizeof(t_phil));
		// pthread_mutex_lock(&fracht[5]);
			printf(">>%d\n",ronowa->philo);
		// pthread_mutex_unlock(&fracht[5]);
	
	// while (1)
	// {
		// printf("think\n");
		// // sleep(1);
		// // printf("here we go\n");
    	// printf("pick up fork\n");
		// printf("eating\n");
		// // sleep(1);
		// printf("pick down fork\n");
		// printf("end eat\n");
		// // sleep(1);
	// }
	return 0;
	// int right = philo;
	
    // philo++;
    // printf("philo number %d",philo);
	return (0);
}
int	main(int ac,char **av)
{
	int i;
	int nb;
	// int *arr;
	t_phil *ronowa;
    pthread_t *ph;
	pthread_mutex_t *fracht;

	i = 1;
	ronowa = malloc(sizeof(t_phil));
	ronowa->arr = malloc(sizeof(int) * ac);
	ph = malloc(sizeof(pthread_t));
	fracht = malloc(sizeof(pthread_mutex_t));

		if (ac > 2)
			{
					// printf("%d\n",nb);
                // printf("here\n");
				while (i < ac)
				{
					nb = ft_atoi(av[i]);
					ronowa->arr[i] = nb;
					i++;
				}
				ronowa->philo = ronowa->arr[1];
				ronowa->timedie = ronowa->arr[2];
				ronowa->timeeat = ronowa->arr[3];
				ronowa->timesleep = ronowa->arr[4];
				// exit(0);
					// printf("-----%d\n",ronowa->philo);
				// int  *nami = malloc(sizeof(int ) * arr[1]);
				int *ad = malloc(sizeof(int ) * ronowa->philo);
                int c = 1;
				while (c <= ronowa->philo)
				{
					pthread_mutex_init(&fracht[c], NULL);
					c++;
				}
				c = 1;
                while (c <= ronowa->philo)
                {
					ad[c] = c;
					// int x = c;
					// printf("-----%d\n",ad[c]);
                    pthread_create(&ph[c], NULL, &routine_life, &ad[c]);
                    c++;
                }
                c = 1;
                while (c <= ronowa->philo)
                {
                    pthread_join(ph[c],NULL);
                    c++;
                }
				c = 1;
				while (c <= ronowa->philo)
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