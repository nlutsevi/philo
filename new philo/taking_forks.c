/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taking_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:21:01 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/22 07:11:52 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_takes_forks(t_philo *philo, int right_hand)
{
	// long int	last_time;

	// last_time = philo[philo->num].taken_left_fork;
	if (pthread_mutex_lock(&philo->mutex_fork) != 0)
		return (1);
	// philo[philo->num].taken_left_fork = get_time();
	philo[philo->num].fork = 1;
	if (philo->data->num_philos == 1)
	{
		usleep(philo->data->time_to_die * 1000);
		philo_died(philo);
		return (1);
	}
	print_left_fork(philo);
	printf("hola\n");
	if (philo_takes_right_fork(philo, right_hand))
		return (1);
	return (0);
}

int		philo_takes_right_fork(t_philo *philo, int right_hand)
{
	// long int	last_time;

	// last_time = philo[philo->num].taken_right_fork;
	if (pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork) != 0)
		return (1);
	// philo[philo->num].taken_right_fork = get_time();
	philo[right_hand].fork = 1;
	print_right_fork(philo);
	return (0);
}

void	print_right_fork(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(right)\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	print_left_fork(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(left)\n"WHITE, time, (philo->data->philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
}
