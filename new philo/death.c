/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:42:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/12/01 03:51:14 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_died(t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(&philo->data->mutex_print);
	time = get_time() - philo->data->start_time;
	if (philo->data->muerte != 1)
		printf(RED"%ldms Philo%d died\n"WHITE, time, philo->num + 1);
	philo->data->muerte = 1;
	pthread_mutex_unlock(&philo->data->mutex_print);
}

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
				philo_died(data->philo);
				data->muerte = 1;
				break ;
			}
			i++;
		}
		if (data->muerte == 1 || data->meals_over == 1)
			break ;
		usleep(100);
	}
}
