/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:47:32 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/30 20:47:39 by mac              ###   ########.fr       */
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
	int				p_am;
	int				p_num;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		eat_time_num;
	pthread_mutex_t mutex;
}	t_philo;

typedef struct s_data
{
	int			alive;
	int			p_num;
	long long	intime;
	t_philo		*philo;
}	t_data;

int			error(int e);
int			philo(char	**argv);
t_philo		*parsing(char **argv, t_philo *philo);
long long	ft_atol(const char *str);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_lstsize(t_philo *lst);
#endif