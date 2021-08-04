/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 01:30:33 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/08/04 21:47:12 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	// while (1)
	// {
		//crear rutina comer
		routine_eat(arg);
		//crear rutina dormir
		routine_sleep(arg);
		//crear rutina pensar
		routine_think(arg);
	// }
	return (0);
}

void	memalloc_threads(t_philo *philo, t_data *data)
{
	int		i;
	
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->thread = malloc(sizeof(pthread_t) * data->num_philos);
	data->fork = malloc(sizeof(int) * data->num_philos);
	data->fork_taken = malloc(sizeof(int) * data->num_philos);
	i = 0;
	while (i < data->num_philos)
	{
		data->fork[i] = 0;
		data->fork_taken[i] = 0;
		philo[i].l_taken_left_fork = 0;
		philo[i].l_taken_right_fork = 0;
		philo[i].l_start_eat = 0;
		philo[i].l_start_sleep = 0;
		philo[i].l_start_think = 0;
		i++;
	}
}

void	init_threads(char *argv[])
{
	int			i;
	t_philo		*philo;
	t_data		data;
	
	data.num_philos = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_sleep = ft_atoi(argv[3]);
	data.time_to_eat = ft_atoi(argv[4]);
	//tiempo inicio del programa
	gettimeofday(&data.start_time, NULL);
	data.l_start_time = (data.start_time.tv_sec * 1000) + (data.start_time.tv_usec / 1000);
	philo = malloc(sizeof(t_philo) * data.num_philos);
	memalloc_threads(philo, &data);
	i = 0;
	while (i < data.num_philos)
	{
		philo[i].data = &data;
		philo[i].num = i;
		if (pthread_create(&data.thread[i], NULL, philo_routine, &philo[i]) != 0)
			printf(RED"Error \n Thread%d cannot be created\n"WHITE, i);
		if (pthread_mutex_init(&data.mutex[i], NULL) != 0)
			printf(RED"Error \n Mutex%d cannot be created\n"WHITE, i);
		i++;
	}
	i = 0;
	while (i < data.num_philos)
	{
		pthread_join(data.thread[i], NULL);
		i++;
	}
}