/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:25:11 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/12/02 20:34:17 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int time, t_data *data)
{
	long int	start_time;

	(void)data;
	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(100);
}

long int	get_time(void)
{
	struct timeval	time;
	long int		long_time;

	gettimeofday(&time, NULL);
	long_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (long_time);
}
