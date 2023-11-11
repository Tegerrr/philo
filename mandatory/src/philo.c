/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:11:56 by timelkon          #+#    #+#             */
/*   Updated: 2023/11/10 18:12:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long		get_time(void)
{
	int	time;
	struct timeval get;

	gettimeofday(&get, NULL);
	time = get.tv_sec * 1000;
	return (time);
}

void	life_cicle(t_philo *philo)
{
	long long	time;
	while (1)
	{
		if (!philo->data->alive)
			return ;
		time = get_time();
		printf("%lln %d\n", time, philo->p_num);
	}
}

int	life_prep(t_data *data)
{
	int				i;
	long			intime;
	long			since_ate;
	pthread_t		th[data->p_num];

	i = 0;
	while (th[i++])
		pthread_create(th[i], NULL, &life_cicle, &data->philo[i]);
	i = 0;
	while (&data->philo[i])
	{
		if (!data->philo->alive)
	}
	i = 0;
	while (th[i++])
		pthread_join(th[i], NULL);
	return (1);
}

int	philo(char	**argv)
{
	t_data			data;
	t_philo			to_parse;
	int		i;

	i = 0;
	data.philo = parsing(argv, &to_parse, &data);
	if (!data.philo)
		return (0);
	data.intime = 0;
	data.alive = 1;
	data.ind = 0;
	data.flag = data.philo->flag;
	data.p_num = ft_atol(argv[1]);
	life_prep(&data);
	while (i++ != data.p_num)
		pthread_mutex_destroy(&data.philo[i].flag);
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
