/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:47:32 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/04 17:50:58 by mac              ###   ########.fr       */
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
	int		philo_num;
	int		fork;
	long	time_die;
	long 	time_eat;
	long	time_sleep;
	long	eat_time_num;
	struct s_philo	*next;
}	t_philo;

int		error(int e);
int		philo(char	**argv);
t_philo	*parsing(char **argv, t_philo *philo);
long	ft_atol(const char *str);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_lstsize(t_philo *lst);
#endif