/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:37:30 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/27 04:19:21 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eating(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(GREEN"%ldms Philo%d is eating\n"WHITE, time, philo->num);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	print_right_fork(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(right)\n"WHITE, \
			time, philo->num);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	print_left_fork(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(left)\n"WHITE, \
			time, philo->num);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	eat_pair(t_philo *philo, int right_hand)
{
	pthread_mutex_lock(&philo->mutex_fork);
	pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
	print_left_fork(philo);
	print_right_fork(philo);
}

void	eat_odd(t_philo *philo, int right_hand)
{
	pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
	pthread_mutex_lock(&philo->mutex_fork);
	print_right_fork(philo);
	print_left_fork(philo);
}
