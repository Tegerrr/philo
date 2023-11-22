/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:47:32 by timelkon          #+#    #+#             */
/*   Updated: 2023/11/22 20:22:10 by mac              ###   ########.fr       */
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
	int				p_ind;
	int				alive;
	long long		time_when_ate;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		eat_time_num;
	int				ate;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				dead;
	int				p_am;
	int				ind;
	long long		intime;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		eat_time_num;
	pthread_mutex_t	*fork;
	pthread_mutex_t	death_watch;
	pthread_mutex_t *adlocks;
	t_philo			*philo;
}	t_data;

int			error(int e);
int			philo(char	**argv, t_data *data);
t_philo		*create_philos(char **argv, t_philo *philo, t_data *data);
long long	ft_atol(const char *str);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_lstsize(t_philo *lst);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
t_philo		*parsing(char **argv, t_philo *to_parse, t_data *data);
long long	get_time(void);

#endif