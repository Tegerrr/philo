/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:11:56 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/04 18:18:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life_cicle(void)
{
	while ()
}

int	life_prep(t_philo *philo, pthread_mutex_t mutex)
{
	int				i;
	long			intime;
	long			since_ate;
	struct timeval	curtime;
	pthread_t		th[ft_lstsize(philo)];

	i = 0;
	if (gettimeofday(&curtime, NULL) == -1)
		return (0);
	intime = curtime.tv_sec * 1000;
	while (th[i++])
		pthread_create(th + 1, NULL, &life_cicle, NULL);
	i = 0;
	while (th[i++])
		pthread_join(th[i], NULL);
	return (1);
}

int	philo(char	**argv)
{
	t_philo	philo;
	t_philo	*true_philo;
	pthread_mutex_t mutex;
	

	pthread_mutex_init(&mutex, NULL);
	true_philo = parsing(argv, &philo);
	if (!true_philo)
		return (0);
	life_prep(true_philo, mutex);
	// int i = 0;
	// t_philo *temp = true_philo;
	// while (temp)
	// {
	// 	printf("---------------\nphilosopher #%d\n", i++);
	// 	printf("fork == %d\n", temp->fork);
	// 	printf("time to die == %d\n", temp->time_die);
	// 	printf("time to eat == %d\n", temp->time_eat);
	// 	printf("time to sleep == %d\n", temp->time_die);
	// 	printf("number of times to eat == %d\n", temp->eat_time_num);
	// 	printf("------------------\n");
	// 	temp = temp->next;
	// }
	pthread_mutex_destroy(&mutex);
}
