/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:37:30 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/18 20:53:59 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eating(t_philo *philo)
{
	long int	time;

	time = philo[philo->num].start_eat - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(GREEN"%ldms Philo%d is eating\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
}

int		philo_starts_eat(t_philo *philo)
{
	long int	last_time;

	last_time = philo[philo->num].start_eat;
	philo[philo->num].start_eat = get_time();
	if (((last_time == 0) && ((philo[philo->num].start_eat - philo->data->start_time) > philo->data->time_to_die)) \
		|| ((philo[philo->num].start_eat - last_time) > philo->data->time_to_die))
	{
		philo_died(philo);
		return (1);
	}
	else
	{
		print_eating(philo);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->data->mutex[philo->num]);
		pthread_mutex_unlock(&philo->data->mutex[philo->num + 1]);
	}
	return (0);
}
