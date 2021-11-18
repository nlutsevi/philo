/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:49:58 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/16 18:02:36 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		init_vars(char **argv, t_data *data)
{
	data->muerte = 0;
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	data->time_to_eat = ft_atoi(argv[4]);
	data->start_time = 0;
}

long int	get_time(void)
{
	struct timeval	time;
	long int		long_time;

	gettimeofday(&time, NULL);
	long_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);

	return (long_time);
}

void		memalloc(t_philo *philo, t_data *data)
{
	philo = malloc(sizeof(t_philo) * data->num_philos);
	data->mutex = malloc(sizeof(pthread_mutex_t) * (data->num_philos));
	data->thread = malloc(sizeof(pthread_t) * data->num_philos);
	data->fork = malloc(sizeof(int) * data->num_philos);
}

void		init_vars_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->fork[i] = 0;
		philo[i].taken_left_fork = 0;
		philo[i].take_right_fork = 0;
		philo[i].start_eat = 0;
		philo[i].start_sleep = 0;
		philo[i].start_think = 0;
		philo[i].data = data;
		philo[i].num = i + 1;
		i++;
	}
}

void		pthread_creation(t_data *data, t_philo *philo)
{
	int	i;

	if (pthread_mutex_init(data->mutex_print, NULL) != 0)
		printf(RED"Error \n Mutex%d cannot be created\n"WHITE, i);
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(data->thread[i], NULL, philo_routine, philo[i]) != 0)
			printf(RED"Error \n Thread%d cannot be created\n"WHITE, i);
		if (pthread_mutex_init(data->mutex[i], NULL) != 0)
			printf(RED"Error \n Mutex%d cannot be created\n"WHITE, i);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->pthread[i], NULL);
		i++
	}
}

void		init_threads(char **argv)
{
	t_data	data;
	t_philo	philo;

	init_vars(argv, &data);
	start_time = get_time();
	memalloc(&philo, &data);
	init_vars_philos(&data, &philo);
	pthread_creation(&data, &philo);
}