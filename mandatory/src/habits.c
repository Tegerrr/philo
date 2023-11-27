/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:39:26 by mac               #+#    #+#             */
/*   Updated: 2023/11/27 19:08:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	// long long	time;

	// pthread_mutex_lock(&philo->data->adlocks[philo->p_ind]);
	// time = get_time() - philo->data->intime;
	// pthread_mutex_unlock(&philo->data->adlocks[philo->p_ind]);
	pthread_mutex_lock(&philo->data->fork[philo->p_ind]);
	printf("%lldms %d has taken a fork\n", get_time() - philo->data->intime, philo->p_ind + 1);
	pthread_mutex_lock(&philo->data->fork[(philo->p_ind + 1) % philo->p_am]);
	printf("%lldms %d has taken a fork\n", get_time() - philo->data->intime, philo->p_ind + 1);
	printf("%lldms %d is eating\n", get_time() - philo->data->intime, philo->p_ind + 1);
	ft_usleep(philo->time_eat * 1000);
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
	// long long	time;

	// time = get_time();
	printf("%lldms %d is sleeping\n", get_time() - philo->data->intime, philo->p_ind + 1);
	ft_usleep(philo->time_sleep * 1000);
}

void	ft_usleep(useconds_t time)
{
	long long	stime;

	time /= 1000;
	stime = get_time();
	while (get_time() - stime < time)
		usleep(time / 10);
}
