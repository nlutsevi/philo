/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:01 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/20 01:58:10 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_takes_forks(t_philo *philo)
{
	long int	last_time;

	last_time = philo[philo->num].taken_left_fork;
	if (pthread_mutex_lock(&philo->data->philo[philo->num].mutex_fork) != 0)
		return (1);
	philo[philo->num].taken_left_fork = get_time();
	philo[philo->num].fork = 1;
	if (((last_time == 0) && ((philo[philo->num].taken_left_fork - philo->data->start_time) > philo->data->time_to_die)) || \
		((last_time != 0) && (philo[philo->num].taken_left_fork - philo[philo->num].start_eat) > philo->data->time_to_die))
	{
		philo_died(philo);
		return (1);
	}
	print_left_fork(philo);
	if (philo_takes_right_fork(philo))
		return (1);
	return (0);
}

int		philo_takes_right_fork(t_philo *philo)
{
	long int	last_time;

	if (philo->data->num_philos == 1)
	{
		philo_died(philo);
		return (1);
	}
	last_time = philo[philo->num].taken_right_fork;
	if ((philo->num + 1) != philo->data->num_philos)
	{
		if (pthread_mutex_lock(&philo->data->philo[philo->num + 1].mutex_fork) != 0)
			return (1);
		philo[philo->num].taken_right_fork = get_time();
		philo[philo->num + 1].fork = 1;
	}
	else
	{
		if (pthread_mutex_lock(&philo->data->philo[0].mutex_fork) != 0)
			return (1);
		philo[philo->num].taken_right_fork = get_time();
		philo[0].fork = 1;
	}
	if (((last_time == 0) && ((philo[philo->num].taken_right_fork - philo->data->start_time) > philo->data->time_to_die)) || \
		((last_time != 0) && (philo[philo->num].taken_right_fork - philo[philo->num].start_eat) > philo->data->time_to_die))
	{
		philo_died(philo);
		return (1);
	}
	print_right_fork(philo);
	return (0);
}

void	print_right_fork(t_philo *philo)
{
	long int	time;

	time = philo[philo->num].taken_right_fork - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(right)\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	print_left_fork(t_philo *philo)
{
	long int	time;

	time = philo[philo->num].taken_left_fork - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(left)\n"WHITE, time, (philo->data->philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
}
