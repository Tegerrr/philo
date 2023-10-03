/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:11:56 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/04 00:43:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char	**argv)
{
	t_philo	philo;
	t_philo	*true_philo;

	true_philo = parsing(argv, &philo);
	int i = 0;
	t_philo *temp = true_philo;
	while (temp)
	{
		printf("---------------\nphilosopher #%d\n", i++);
		printf("fork == %d\n", temp->fork);
		printf("time to die == %d\n", temp->time_die);
		printf("time to eat == %d\n", temp->time_eat);
		printf("time to sleep == %d\n", temp->time_die);
		printf("number of times to eat == %d\n", temp->eat_time_num);
		printf("------------------\n");
		temp = temp->next;
	}
}
