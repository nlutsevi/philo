/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:42:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/12/02 22:57:33 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *data)
{
	int			i;
	long int	time;

	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			time = get_time() - data->start_time - data->philo[i].last_eat;
			if (time > data->time_to_die && data->philo[i].meals_num != 0)
			{
				ft_print_mutex(&data->philo[i], "died");
				break ;
			}
			i++;
		}
		if (data->muerte == 1 || data->meals_over == 1)
			break ;
		usleep(100);
	}
}
