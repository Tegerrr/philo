/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:11:56 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/30 20:44:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life_cicle(t_philo *philo)
{
	while (1)
	{
		if (!data->alive)
			
		if (data->philo->)
		{
			
		}
	}
}

int	life_prep(t_data *data)
{
	int				i;
	long			intime;
	long			since_ate;
	pthread_t		th[data->p_num];

	i = -1;
	while (1)
	{
		if (!data->alive)
			break ;
		while (th[i++])
			pthread_create(th[i], NULL, &life_cicle, &data->philo[i]);
	}
		i = -1;
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
	data.philo = parsing(argv, &to_parse);
	if (!data.philo)
		return (0);
	data.intime = 0;
	data.alive = 1;
	data.p_num = ft_atol(argv[1]);
	life_prep(&data);
	while (i++ != data.p_num)
		pthread_mutex_destroy(&data.philo[i].mutex);
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
