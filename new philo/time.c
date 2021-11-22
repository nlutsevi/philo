/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:25:11 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/22 19:54:22 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_usleep(long int time, t_data *data)
{
	long int	start_time;

	start_time = data->start_time;
	while ((data->start_time - start_time) < time)
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