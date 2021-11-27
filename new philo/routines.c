/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:59:59 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/26 23:52:55 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;

	if (philo->num % 2 == 0)
		philo->data->pair = 1;

	while (philo->data->muerte == 0)
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
	}	
	return (0);
}

void		one_and_only(t_philo *philo)
{
	if (philo->data->num_philos == 1 || (philo->meals_num == philo->data->total_meals))
	{
		pthread_mutex_lock(&philo->mutex_fork);
		print_left_fork(philo);
		ft_usleep(philo->data->time_to_die, philo->data);
		philo_died(philo);
		philo->data->muerte = 1;
	}
}

void		routine_eat(t_philo *philo)
{
	int			right_hand;

	right_hand = philo->num;
	if (right_hand == philo->data->num_philos)
		right_hand = 0;
	one_and_only(philo);
	if (philo->data->pair)
	{
		pthread_mutex_lock(&philo->mutex_fork);
		pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
		print_left_fork(philo);
		print_right_fork(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
		pthread_mutex_lock(&philo->mutex_fork);
		print_right_fork(philo);
		print_left_fork(philo);
	}
	philo->last_eat = get_time() - philo->data->start_time;
	print_eating(philo);
	philo->meals_num++;
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(&philo->mutex_fork);
	pthread_mutex_unlock(&philo->data->philo[right_hand].mutex_fork);
}

void	routine_sleep(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(CYAN"%ldms Philo%d is sleeping\n"WHITE, time, philo->num);
	pthread_mutex_unlock(&philo->data->mutex_print);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	routine_think(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(GRAY"%ldms Philo%d is thinking\n"WHITE, time, philo->num);
	pthread_mutex_unlock(&philo->data->mutex_print);
}


