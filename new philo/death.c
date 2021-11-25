/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:42:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/25 04:41:55 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_died(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(RED"%ldms Philo%d died\n"WHITE, time, philo->data->philo->num);
	philo->data->muerte = 1;
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	check_death(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (data->philo[i].last_eat != data->start_time)
			{
				if (data->philo[i].last_eat >= data->time_to_die)
				{
					//printf("last_eat %ld\n", data->philo[i].last_eat);
					philo_died(data->philo);
					break;
				}
			}
			i++;
		}
		if (data->muerte == 1)
			break;
		ft_usleep(100, data);
	}
}

