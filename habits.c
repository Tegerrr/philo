/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:39:26 by mac               #+#    #+#             */
/*   Updated: 2023/12/06 15:57:26 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->p_ind]);
	pthread_mutex_lock(&philo->data->write);
	safeprint(philo->data, get_time() - philo->data->intime,
		philo->p_ind + 1, "has taken a fork\n");
	pthread_mutex_unlock(&philo->data->write);
	pthread_mutex_lock(&philo->data->fork[(philo->p_ind + 1) % philo->p_am]);
	pthread_mutex_lock(&philo->data->write);
	safeprint(philo->data, get_time() - philo->data->intime,
		philo->p_ind + 1, "has taken a fork\n");
	safeprint(philo->data, get_time() - philo->data->intime,
		philo->p_ind + 1, "is eating\n");
	pthread_mutex_unlock(&philo->data->write);
	ft_usleep(philo->time_eat * 1000, philo);
	pthread_mutex_lock(&philo->data->adlocks[philo->p_ind]);
	pthread_mutex_lock(&philo->data->write);
	philo->time_when_ate = get_time();
	pthread_mutex_unlock(&philo->data->write);
	philo->ate++;
	pthread_mutex_unlock(&philo->data->adlocks[philo->p_ind]);
	pthread_mutex_unlock(&philo->data->fork[philo->p_ind]);
	pthread_mutex_unlock(&philo->data->fork[(philo->p_ind + 1) % philo->p_am]);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write);
	safeprint(philo->data, get_time() - philo->data->intime,
		philo->p_ind + 1, "is sleeping\n");
	pthread_mutex_unlock(&philo->data->write);
	ft_usleep(philo->time_sleep * 1000, philo);
}

void	ft_usleep(useconds_t time, t_philo *philo)
{
	long long	stime;

	if (philo)
		time /= 1000;
	stime = get_time();
	while (get_time() - stime < time)
		usleep(50);
}
