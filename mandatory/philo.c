/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:11:56 by timelkon          #+#    #+#             */
/*   Updated: 2023/12/05 20:57:20 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cicle(void *info)
{
	t_philo		*philo;

	philo = info;
	if ((philo->p_ind + 1) % 2 == 0)
		ft_usleep(15000, philo);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		safeprint(philo->data, get_time() - philo->data->intime,
			philo->p_ind + 1, "is thinking\n");
	}
	return (0);
}

int	death_watch_1(t_data *data, int i)
{
	pthread_mutex_lock(&data->adlocks[i]);
	if (data->time_die <= get_time() - data->philo[i].time_when_ate)
	{
		pthread_mutex_lock(&data->write);
		printf("%lldms %d died \n", get_time() - data->intime, i + 1);
		pthread_mutex_unlock(&data->write);
		data->dead = 1;
		return (1);
	}
	pthread_mutex_unlock(&data->adlocks[i]);
	return (0);
}

void	*death_watch(void *info)
{
	int			i;
	int			eat_count;
	t_data		*data;

	eat_count = 0;
	data = ((t_data *)info);
	while (1)
	{
		i = -1;
		while (++i != data->p_am)
		{
			if (death_watch_1(data, i) == 1)
				return ((void *)(1));
			if (data->eat_time_num >= 0
				&& data->philo[i].ate >= data->eat_time_num)
				eat_count++;
			else
				eat_count = 0;
			if (eat_count == data->p_am)
				return ((void *)(2));
		}
	}
	printf("exit 0\n");
	return ((void *)(0));
}

int	life_prep(t_data *data)
{
	int				i;
	pthread_t		*th;
	pthread_t		th_death;

	i = -1;
	th = malloc(data->p_am * sizeof(pthread_t));
	pthread_create(&th_death, NULL, death_watch, (void *)data);
	while (++i < data->p_am)
		pthread_create(&th[i], NULL, life_cicle, &(data->philo[i]));
	i = -1;
	pthread_join(th_death, NULL);
	return (1);
}

int	philo(char	**argv, t_data *data)
{
	t_philo			to_parse;
	int				i;

	i = -1;
	data->philo = parsing(argv, &to_parse, data);
	if (!data->philo || data->philo == NULL)
		return (0);
	data->p_am = ft_atol(argv[1]);
	data->fork = malloc(data->p_am * sizeof(pthread_mutex_t));
	data->adlocks = malloc(data->p_am * sizeof(pthread_mutex_t));
	while (i++ != data->p_am)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->adlocks[i], NULL);
	}
	pthread_mutex_init(&data->write, NULL);
	life_prep(data);
	i = -1;
	while (++i != data->p_am)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->adlocks[i]);
	}
	pthread_mutex_destroy(&data->write);
	return (0);
}
