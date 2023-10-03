/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:31:49 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/04 00:47:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(char **argv, t_philo *philo)
{
	int	p_num;
	t_philo *temp;

	philo = NULL;
	p_num = ft_atoi(argv[1]);
	if (p_num > 200)
		return (error(2), NULL);
	while (p_num--)
	{
		temp = ft_calloc(1, sizeof(t_philo));
		temp->fork = 1;
		temp->time_die = ft_atoi(argv[2]);
		temp->time_eat = ft_atoi(argv[3]);
		temp->time_sleep = ft_atoi(argv[4]);
		if (argv[5])
			temp->eat_time_num = ft_atoi(argv[5]);
		else
			temp->eat_time_num = -1;
		temp->next = NULL;
		ft_lstadd_back(&philo, temp);
	}
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
				return (NULL);
			j++;
		}
		i++;
		j = 0;
	}
	philo = create_philos(argv, philo);
	return (philo);
}
