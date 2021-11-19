/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:49:58 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/19 06:05:23 by nlutsevi         ###   ########.fr       */
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

void		memalloc(t_data *data)
{
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
		philo[i].taken_right_fork = 0;
		philo[i].taken_left_fork = 0;
		philo[i].start_eat = 0;
		philo[i].start_sleep = 0;
		philo[i].start_think = 0;
		philo[i].data = data;
		philo[i].num = i;
		i++;
	}
}

void		pthread_creation(t_data *data, t_philo *philo)
{
	int	i;

	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		printf(RED"Error \n print_mutex cannot be created\n"WHITE);
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->thread[i], NULL, philo_routine, &philo[i]) != 0)
			printf(RED"Error \n Thread%d cannot be created\n"WHITE, i);
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			printf(RED"Error \n Mutex%d cannot be created\n"WHITE, i);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
			printf(RED"Error \n Thread%d cannot be joined\n"WHITE, i);
		i++;
	}
}

// void		pthreads_join(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_philos)
// 	{
// 		pthread_join(data->thread[i], NULL);
// 		i++;
// 	}
// }

void		init_threads(char **argv)
{
	t_data	data;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data.num_philos);
	memalloc(&data);
	init_vars(argv, &data);
	data.start_time = get_time();
	init_vars_philos(&data, philo);
	pthread_creation(&data, philo);
	//pthreads_join(&data);
}