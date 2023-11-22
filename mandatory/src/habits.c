/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:39:26 by mac               #+#    #+#             */
/*   Updated: 2023/11/22 20:45:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->adlocks[philo->p_ind]);
	time = get_time() - philo->data->intime;
	pthread_mutex_unlock(&philo->data->adlocks[philo->p_ind]);
	pthread_mutex_lock(&philo->data->fork[philo->p_ind]);
	printf("%lldms %d has taken a fork\n", time, philo->p_ind + 1);
	pthread_mutex_lock(&philo->data->fork[(philo->p_ind + 1) % philo->p_am]);
	printf("%lldms %d has taken a fork\n", time, philo->p_ind + 1);
	printf("%lldms %d is eating\n", time, philo->p_ind + 1);
	usleep(philo->time_eat);
	pthread_mutex_lock(&philo->data->adlocks[philo->p_ind]);
		// printf("test philo number in eating == %d\n", philo->p_ind);
		// printf("test mutex adress in eating == %p\n", &philo->data->adlocks[philo->p_ind]);
	philo->time_when_ate = get_time();
	philo->ate++;
	// printf("time == %lld\n", get_time());
	pthread_mutex_unlock(&philo->data->adlocks[philo->p_ind]);
	pthread_mutex_unlock(&philo->data->fork[philo->p_ind]);
	pthread_mutex_unlock(&philo->data->fork[(philo->p_ind + 1) % philo->p_am]);
}

void	sleeping(t_philo *philo)
{
	long long	time;

	time = get_time();
	printf("%lldms %d is sleeping\n", time - philo->data->intime, philo->p_ind + 1);
	usleep(philo->time_sleep);
}
