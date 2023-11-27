/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:11:56 by timelkon          #+#    #+#             */
/*   Updated: 2023/11/27 19:44:19 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long		get_time(void)
{
	struct timeval get;

	gettimeofday(&get, NULL);
	return (get.tv_sec * 1000 + get.tv_usec / 1000);
}

void	*life_cicle(void *info)
{
	int			flag1;
	t_philo		*philo;
	// long long	time;

	philo = info;
	flag1 = 1;
	while (1)
	{
		// if (philo->data->dead)
		// 	return (0);
		// time = get_time();
		if (flag1)
		{
			if ((philo->p_ind + 1) % 2 == 0)
				ft_usleep(2000);
			flag1 = 0;
		}
		eating(philo);
		sleeping(philo);
		printf("%lldms %d is thinking\n", get_time() - philo->data->intime, philo->p_ind + 1);
	}
	return (0);
}

void	*death_watch(void *info)
{
	int			i;
	int			eat_count;
	t_data		*data;
	long long	curtime;

	eat_count = 0;
	data = ((t_data *)info);
	while (1)
	{
		i = -1;
		while (++i != data->p_am)
		{
			curtime = get_time();
			// printf("%lld\n", get_time() - data->philo[i].time_when_ate);
			// printf("test time to die == %lld\n", data->time_die);
			pthread_mutex_lock(&data->adlocks[i]);
			// printf("curtime - time when ate = %lld\n", curtime - data->philo[i].time_when_ate);
			// printf("time_die == %lld\n", data->time_die);
			if (data->time_die <= curtime - data->philo[i].time_when_ate)
			{
				// printf("curtime - time when ate = %lld\n", curtime - data->philo[i].time_when_ate);
				// printf("test time when ate == %lld\n", data->philo[i].time_when_ate);
				// printf("test mutex adress in death == %p\n", &data->adlocks[i]);
				// printf("test philo number in death == %d\n", i);
				printf("%lldms %d died \n", get_time() - data->intime, i + 1);
				// printf("hi 1\n");
				return ((void *)(1));
			}
			pthread_mutex_unlock(&data->adlocks[i]);
			if (data->eat_time_num >= 0 &&
				data->philo[i].ate >= data->eat_time_num)
				eat_count++;
			else
				eat_count = 0;
			if (eat_count == data->p_am)
			{
				// printf("---philos have eaten %d times---\n", data->philo[i].ate);
				return ((void *)(2));
			}
		}
	}
	printf("hi 0\n");
	return ((void *)(0));
}

int	life_prep(t_data *data)
{
	int				i;
	pthread_t		th[data->p_am];
	pthread_t		th_death;
	

	i = -1;
	pthread_create(&th_death, NULL, death_watch, (void *)data);
	while (++i < data->p_am)
		pthread_create(&th[i], NULL, life_cicle, &(data->philo[i]));
	i = -1;
	pthread_join(th_death, NULL);
	while (++i < data->p_am)
		pthread_detach(th[i]);
	return (1);
}

int	philo(char	**argv, t_data *data)
{
	t_philo			to_parse;
	int				i;

	i = -1;
	data->philo = parsing(argv, &to_parse, data);
	// pthread_mutex_init(&data->death_watch, NULL);
	if (!data->philo || data->philo == NULL)
		return (0);
	data->dead = 0;
	data->ind = 0;
	data->p_am = ft_atol(argv[1]);
	data->fork = malloc(data->p_am * sizeof(pthread_mutex_t));
	data->adlocks = malloc(data->p_am * sizeof(pthread_mutex_t));
	while (i++ != data->p_am)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_mutex_init(&data->adlocks[i], NULL);
	}
	life_prep(data);
	i = -1;
	while (++i != data->p_am)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->adlocks[i]);
	}
	// i = 0;
	// while (i++ != data.p_num)
	// {
	// 	printf("philo number %d\n", i);
	// 	printf("amount of philos: %d\n", data.p_num);
	// 	printf("time to die: %lld\n", data.philo->time_die);
	// 	printf("time to eat: %lld\n", data.philo->time_eat);
	// 	printf("time to sleep: %lld\n", data.philo->time_sleep);
	// 	printf("number of times philo must eat: %lld\n\n", data.philo->eat_time_num);
	// }
	// 	printf("intime is %lld\n", data.intime);
	return (0);
}
