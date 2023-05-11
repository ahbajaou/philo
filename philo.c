/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:21:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/05/11 12:09:54 by ahbajaou         ###   ########.fr       */
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
void    *routine_life()
{
    int philo = 0;
    philo++;
    printf("philo number %d",philo);
    return (0);
}
int	main(int ac,char **av)
{
	int i;
	int nb;
	int *arr;
	t_phil *ronowa;

	i = 1;
	ronowa = malloc(sizeof(t_phil));
	arr = malloc(sizeof(int) * ac);

		if (ac > 2)
			{
					// printf("%d\n",nb);
                printf("here\n");
				while (i < ac)
				{
					nb = ft_atoi(av[i]);
					arr[i] = nb;
					i++;
				}
				ronowa->philo = arr[1];
				ronowa->timedie = arr[2];
				ronowa->timeeat = arr[3];
				ronowa->timesleep = arr[4];
				// printf(">>%d\n",ronowa->philo);
                pthread_t ph[ronowa->philo];
                int c = 0;
                while (i < ronowa->philo)
                {
                    pthread_create(&ph[c],NULL,&routine_life,NULL);
                    c++;
                }
                c = 0;
                while (i < ronowa->philo)
                {
                    pthread_join(ph[c],NULL);
                    i++;
                }
                printf("here we go\n");
			}
    return 0;
	// }
	// return (0);
}
// int counter = 0;
// pthread_mutex_t mutex
// void  *routine()
// {
//     int i = 0;
//     // int counter = 0;
//     // ronowa.counter = 0;
//     while (i < 10000)
//     {
//         // ronowa.counter++;
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