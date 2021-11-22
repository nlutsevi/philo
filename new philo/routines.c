/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:59:59 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/22 07:08:56 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while (philo->data->muerte == 0)
	{
		routine_eat(philo);
	}
	return (0);
}

int		routine_eat(t_philo *philo)
{
	long int	last_eat;
	int			right_hand;

	last_eat = 0;
	right_hand = philo->num + 1;
	if (right_hand == philo->data->num_philos)
		right_hand = 0;
	if (philo_takes_forks(philo, right_hand))
		return (1);
	if (philo_starts_eat(philo, right_hand))
		return (1);
	return (0);
}



