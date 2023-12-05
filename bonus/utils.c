/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:46:37 by mac               #+#    #+#             */
/*   Updated: 2023/12/05 20:47:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atol(const char *str)
{
	int			i;
	int			znak;
	long long	res;

	i = 0;
	znak = 1;
	res = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		znak *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
		{
			res = (res * 10) + (str[i] - 48);
			i++;
		}
	}
	return (znak * res);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	prd;
	void	*spc;

	prd = count * size;
	if (count && size)
	{
		if (prd < size || prd < count)
			return (NULL);
	}
	spc = malloc(prd);
	if (!spc)
		return (NULL);
	ft_bzero(spc, prd);
	return (spc);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	a;
	char	*str;

	str = (char *) s;
	a = 0;
	if (n > 0)
	{
		while (a != n)
		{
			str[a] = '\0';
			a++;
		}
		a = 0;
	}
	return ;
}

long long	get_time(void)
{
	struct timeval	get;

	gettimeofday(&get, NULL);
	return (get.tv_sec * 1000 + get.tv_usec / 1000);
}

void	safeprint(t_data *data, long long time, int p_ind, char *str)
{
	pthread_mutex_lock(&data->write);
	if (!data->dead)
		printf("%lldms %d %s", time, p_ind, str);
	pthread_mutex_unlock(&data->write);
}
