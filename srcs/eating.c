/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:37:30 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/12/07 21:35:31 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_mutex(t_philo *philo, char *cmd)
{
	long int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
	{
		if (ft_strncmp(cmd, "died", 20) == 0)
		{
			printf(RED"%ldms Philo%d died\n"WHITE, time, philo->num);
			philo->data->muerte = 1;
		}
		else if (ft_strncmp(cmd, "left_fork", 20) == 0)
			printf(YELLOW"%ldms Philo%d has taken a fork(left)\n"WHITE, \
			time, philo->num);
		else if (ft_strncmp(cmd, "right_fork", 20) == 0)
			printf(YELLOW"%ldms Philo%d has taken a fork(right)\n"WHITE, \
			time, philo->num);
		else if (ft_strncmp(cmd, "eat", 20) == 0)
			printf(GREEN"%ldms Philo%d is eating\n"WHITE, time, philo->num);
		else if (ft_strncmp(cmd, "sleep", 20) == 0)
			printf(CYAN"%ldms Philo%d is sleeping\n"WHITE, time, philo->num);
		else if (ft_strncmp(cmd, "think", 20) == 0)
			printf(GRAY"%ldms Philo%d is thinking\n"WHITE, time, philo->num);
	}
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	eat_pair(t_philo *philo, int right_hand)
{
	pthread_mutex_lock(&philo->mutex_fork);
	ft_print_mutex(philo, "left_fork");
	pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
	ft_print_mutex(philo, "right_fork");
}

void	eat_odd(t_philo *philo, int right_hand)
{
	pthread_mutex_lock(&philo->data->philo[right_hand].mutex_fork);
	ft_print_mutex(philo, "right_fork");
	pthread_mutex_lock(&philo->mutex_fork);
	ft_print_mutex(philo, "left_fork");
}
