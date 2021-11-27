/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:49:58 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/26 23:52:08 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		init_vars(char **argv, t_data *data)
{
	data->muerte = 0;
	data->pair = 0;
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->total_meals = ft_atoi(argv[5]);
}

void		init_vars_philos(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		printf(RED"Error \n print_mutex cannot be created\n"WHITE);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->philo[i].mutex_fork, NULL) != 0)
			printf(RED"Error \n Mutex%d cannot be created\n"WHITE, i);
		data->philo[i].last_eat = 0;
		data->philo[i].num = i + 1;
		data->philo[i].meals_num = 0;
		i++;
	}
}

void		pthread_creation(t_data *data)
{
	int	i;


	i = 0;
	while (i < data->num_philos)
	{
		data->philo[i].data = data;
		if (pthread_create(&data->philo[i].thread, NULL, philo_routine, &data->philo[i]) != 0)
			printf(RED"Error \n Thread%d cannot be created\n"WHITE, i);
		i++;
	}
	check_death(data);
	i = 0;
	while (i < data->num_philos && data->muerte == 0)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			printf(RED"Error \n Thread%d cannot be joined\n"WHITE, i);
		i++;
	}
}

void		init_threads(char **argv)
{
	t_data	data;

	init_vars(argv, &data);
	data.philo = malloc(sizeof(t_philo) * data.num_philos);
	init_vars_philos(&data);
	pthread_creation(&data);
	free(data.philo);
}