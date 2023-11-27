/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:44:25 by timelkon          #+#    #+#             */
/*   Updated: 2023/11/27 19:48:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (error(0));
	data.intime = get_time();
	philo(argv, &data);
	return (0);
}
