/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:26:27 by timelkon          #+#    #+#             */
/*   Updated: 2023/10/03 23:05:36 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error(int e)
{
	if (e == 0)
		printf("wrong number of args\n");
	if (e == 1)
		printf("args must only consist of numbers\n");
	if (e == 2)
		printf("there are more than 200 philosophers\n");
	return (1);
}
