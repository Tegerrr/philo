/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:31:49 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/04 17:52:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(char **argv, t_philo *philo)
{
	int	p_num;
	int	n;
	t_philo *temp;

	n = 1;
	philo = NULL;
	p_num = ft_atoi(argv[1]);
	if (p_num > 200)
		return (error(2), NULL);
	while (p_num--)
	{
		temp = ft_calloc(1, sizeof(t_philo));
		if (!temp)
			return (error(3), NULL);
		temp->fork = 1;
		temp->philo_num = n++;
		temp->time_die = ft_atol(argv[2]) * 1000;
		temp->time_eat = ft_atol(argv[3]) * 1000;
		temp->time_sleep = ft_atol(argv[4]) * 1000;
		if (argv[5])
			temp->eat_time_num = ft_atol(argv[5]) * 1000;
		else
			temp->eat_time_num = -1;
		temp->next = NULL;
		ft_lstadd_back(&philo, temp);
	}
	if (temp->philo_num != 1)
		temp->next = philo;
	return (philo);
}

t_philo	*parsing(char **argv, t_philo *philo)
{
	int	i;
	int	j;

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
	philo = create_philos(argv, philo);
	return (philo);
}
