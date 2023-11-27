/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:26:27 by timelkon          #+#    #+#             */
/*   Updated: 2023/11/27 19:28:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error(int e)
{
	if (e == 0)
		write (2, "wrong number of args\n", 22);
	if (e == 1)
		write (2, "args must only consist of numbers\n", 35);
	if (e == 2)
		write (2, "there are more than 200 philosophers\n", 38);
	if (e == 3)
		write (2, "malloc error\n", 14);
	if (e == 4)
		write (2, "gettimeofday didn't execute properly\n", 38);
	if (e == 5)
		write (2, "memory didn't allocate properly\n", 33);
	if (e == 6)
		write (2, "no philos for life ;(\n", 23);
	if (e == 7)
		write (2, "time args can't be lower than 60\n", 34);
	return (1);
}
