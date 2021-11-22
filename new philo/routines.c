/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:59:59 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/22 20:37:55 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;

	if (philo->num % 2 == 0)
		philo->data->pair = 1;

	while (1)
	{
		routine_eat(philo);
	}
	return (0);
}

void		routine_eat(t_philo *philo)
{
	int			right_hand;

	right_hand = philo->num;
	if (right_hand == philo->data->num_philos)
		right_hand = 0;
	if (philo->data->pair)
	{
		pthread_mutex_lock(&philo->mutex_fork);
		print_left_fork(philo);
		pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
		print_right_fork(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
		print_right_fork(philo);
		pthread_mutex_lock(&philo->mutex_fork);
		print_left_fork(philo);
	}
	/*if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->time_to_die, philo->data);
		philo_died(philo);
	}*/
	philo->last_eat = get_time();
	print_eating(philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&philo->mutex_fork);
	pthread_mutex_unlock(&philo->data->philo[right_hand].mutex_fork);
}


