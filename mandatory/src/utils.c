/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:46:37 by mac               #+#    #+#             */
/*   Updated: 2023/10/04 00:15:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		znak;
	size_t	res;

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

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*a;

	a = (*lst);
	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			(*lst)->next = NULL;
			return ;
		}
		while (a -> next != NULL)
			a = a -> next;
		a -> next = new;
	}
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
