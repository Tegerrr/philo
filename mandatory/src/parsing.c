/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:31:49 by timelkon          #+#    #+#             */
/*   Updated: 2023/11/22 19:23:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(char **argv, t_philo *philo, t_data *data)
{
	int				i;
	long long		p_am;

	i = -1;
	p_am = ft_atol(argv[1]);
	philo = malloc(p_am * sizeof(t_philo));
	// printf("ind == %x\n", philo->p_ind);
	// printf("*data adress == %p\n", philo->data);
	// printf("*philo adress == %p\n", philo);
	if (!philo)
		return (error(5), NULL);
	while (++i != p_am)
	{
		philo[i].p_am = ft_atol(argv[1]);
		philo[i].p_ind = i;
		philo[i].alive = 1;
		philo[i].time_die = ft_atol(argv[2]) * 1000;
		philo[i].time_eat = ft_atol(argv[3]) * 1000;
		philo[i].time_sleep = ft_atol(argv[4]) * 1000;
		philo[i].data = data;
		philo[i].ate = 0;
		philo[i].time_when_ate = data->intime;
		// printf("*data adress == %p\n", philo->data);
		if (argv[5])
			philo[i].eat_time_num = ft_atol(argv[5]);
		else
			philo[i].eat_time_num = -1;
	}
	data->time_die = philo[0].time_die;
	data->time_eat = philo[0].time_eat;
	data->time_sleep = philo[0].time_sleep;
	data->eat_time_num = philo[0].eat_time_num;
	return (philo);
}

t_philo	*parsing(char **argv, t_philo *to_parse, t_data *data)
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
	philo = create_philos(argv, to_parse, data);
	i = 0;
	return (philo);
}
