/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 06:42:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/22 20:55:43 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_died(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->data->philo->num + 1));
	philo->data->muerte = 1;
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	check_death(t_data *data)
{
	int	i;
	long int	time;

	while (1)
	{
		i = 0;
		while (i < data->num_philos)
		{
			time = data->start_time - data->philo[i].last_eat;
			if (time >= data->time_to_die)
			{
				philo_died(data->philo);
				data->muerte = 1;
				break;
			}
			i++;
		}
		if (data->muerte == 1)
			break;
		ft_usleep(100, data);
	}
}