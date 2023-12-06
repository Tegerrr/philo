/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:44:25 by timelkon          #+#    #+#             */
/*   Updated: 2023/12/06 15:35:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (error(0));
	if (*argv[1] && *argv[2] && *argv[3] && *argv[4])
		;
	else
		return (error(10));
	if (argv[5] && ft_atol(argv[5]) == 0)
		return (error(10));
	data.intime = get_time();
	data.dead = 0;
	data.ind = 0;
	philo(argv, &data);
	return (0);
}
