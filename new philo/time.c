/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:25:11 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/19 04:32:55 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;
	long int		long_time;

	gettimeofday(&time, NULL);
	long_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);

	return (long_time);
}