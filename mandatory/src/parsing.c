/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:31:49 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/30 20:48:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(char **argv, t_philo *philo)
{
	int				i;
	long long		p_num;

	i = -1;
	p_num = ft_atol(argv[1]);
	philo = malloc(p_num * sizeof(t_philo));
	while (++i != p_num)
	{
		philo[i].p_am = ft_atol(argv[1]);
		philo[i].p_num = i;
		philo[i].time_die = ft_atol(argv[2]) * 1000;
		philo[i].time_eat = ft_atol(argv[3]) * 1000;
		philo[i].time_sleep = ft_atol(argv[4]) * 1000;
		pthread_mutex_init(&philo[i].mutex, NULL);
		if (argv[5])
			philo[i].eat_time_num = ft_atol(argv[5]);
		else
			philo[i].eat_time_num = -1;
	}
	return (philo);
}

t_philo	*parsing(char **argv, t_philo *to_parse)
{
	int		i;
	int		j;
	t_philo	*philo;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (error(1), NULL);
			j++;
		}
		i++;
		j = 0;
	}
	philo = create_philos(argv, to_parse);
	i = 0;
	return (philo);
}
