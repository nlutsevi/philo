/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:59:59 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/18 21:02:06 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_died(t_philo *philo)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
	philo->data->muerte = 1;
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	*philo_routine(void *arg)
{
	while (1)
	{
		if (routine_eat(arg))
			break;
	}
	return (0);
}

int		routine_eat(t_philo *philo)
{
	long int	last_eat;

	last_eat = 0;
	if (philo_takes_forks(philo))
		return (1);
	if (philo_starts_eat(philo))
		return (1);
	return (0);
}



