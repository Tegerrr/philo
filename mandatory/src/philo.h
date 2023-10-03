/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:47:32 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/04 00:36:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	fork;
	int	time_die;
	int time_eat;
	int	time_sleep;
	int	eat_time_num;
	struct s_philo	*next;
}	t_philo;

int		error(int e);
void	philo(char	**argv);
t_philo	*parsing(char **argv, t_philo *philo);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
#endif