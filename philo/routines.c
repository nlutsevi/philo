/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:13:07 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/17 21:57:27 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_takes_right_fork(t_philo *philo)
{
	long int	time;

	//coge el tenedor de la derecha
	if (pthread_mutex_lock(&philo->data->mutex[philo->num + 1]) != 0)
		return (1);
	gettimeofday(&philo->taken_right_fork, NULL);


	//caso excepcional 1 tenedor / 1 philo
	if (philo->data->num_philos == 1)
	{
		philo->l_taken_right_fork = (philo->taken_right_fork.tv_sec * 1000) + (philo->taken_right_fork.tv_usec / 1000);
		time = philo->l_taken_right_fork - philo->data->l_start_time;
		pthread_mutex_lock(&philo->data->mutex_print);
		if (philo->data->muerte != 1)
			printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
		philo->data->muerte = 1;
		pthread_mutex_unlock(&philo->data->mutex_print);
		return (1);
	}
	if (philo->l_taken_right_fork != 0)
	{
		philo->l_taken_right_fork = (philo->taken_right_fork.tv_sec * 1000) + (philo->taken_right_fork.tv_usec / 1000);
		
		if ((philo->l_taken_right_fork - philo->l_start_eat) > philo->data->time_to_die)
		{
			time = philo->l_taken_right_fork - philo->data->l_start_time;
			pthread_mutex_lock(&philo->data->mutex_print);
			if (philo->data->muerte != 1)
				printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
			philo->data->muerte = 1;
			pthread_mutex_unlock(&philo->data->mutex_print);
			return (1);
		}
	}
	else
		philo->l_taken_right_fork = (philo->taken_right_fork.tv_sec * 1000) + (philo->taken_right_fork.tv_usec / 1000);
	//restar start-program y taken right fork en miscrosegundos
	time = philo->l_taken_right_fork - philo->data->l_start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(right)\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
	//ponemos las variables tenedor y tenedor cogido en 1
	philo->data->fork[philo->num + 1] = 1;
	philo->data->fork_taken[philo->num + 1] = 1;
	return (0);
}

int	philo_takes_left_fork(t_philo *philo)
{
	long int	time;

	//coge el tenedor de la izquierda
	if (pthread_mutex_lock(&philo->data->mutex[philo->num]) != 0)
		return (1);
	gettimeofday(&philo->taken_left_fork, NULL);
	if (philo->l_taken_left_fork != 0)
	{
		philo->l_taken_left_fork = (philo->taken_left_fork.tv_sec * 1000) + (philo->taken_left_fork.tv_usec / 1000);
		if ((philo->l_taken_left_fork - philo->l_start_eat) > philo->data->time_to_die)
		{
			time = philo->l_taken_left_fork - philo->data->l_start_time;
			pthread_mutex_lock(&philo->data->mutex_print);
			if (philo->data->muerte != 1)
				printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
			philo->data->muerte = 1;
			pthread_mutex_unlock(&philo->data->mutex_print);
			return (1);
		}
	}
	else
		philo->l_taken_left_fork = (philo->taken_left_fork.tv_sec * 1000) + (philo->taken_left_fork.tv_usec / 1000);
	time = philo->l_taken_left_fork - philo->data->l_start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(left)\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
	if (philo_takes_right_fork(philo))
		return (1);
	//ponemos las variables tenedor y tenedor cogido en 1
	philo->data->fork[philo->num] = 1;
	philo->data->fork_taken[philo->num] = 1;
	return (0);
}


int	routine_eat(t_philo *philo)
{
	long int	time;
	long int	last_eat;

	last_eat = 0;
	//se cogen los cubiertos
	if (philo_takes_left_fork(philo))
		return (1);
	// if (philo_takes_right_fork(philo))
	// 	return (1);
	
	//empieza a comer
	gettimeofday(&philo->start_eat, NULL);
	if (philo->l_start_eat != 0)
	{
		last_eat = philo->l_start_eat;
		philo->l_start_eat = (philo->start_eat.tv_sec * 1000) + (philo->start_eat.tv_usec / 1000);
		if ((philo->l_start_eat - last_eat) > philo->data->time_to_die)
		{
			time = philo->l_start_eat - philo->data->l_start_time;
			pthread_mutex_lock(&philo->data->mutex_print);
			if (philo->data->muerte != 1)
				printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
			philo->data->muerte = 1;
			pthread_mutex_unlock(&philo->data->mutex_print);
			return (1);
		}
	}
	else
		philo->l_start_eat = (philo->start_eat.tv_sec * 1000) + (philo->start_eat.tv_usec / 1000);
	//restar start-program y start eat en miscrosegundos

	time = philo->l_start_eat - philo->data->l_start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(GREEN"%ldms Philo%d is eating\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
	//printf("eat time: %ld\n", (time * 100));
	
	//tiempo comiendo
	usleep(philo->data->time_to_eat * 1000);


	pthread_mutex_unlock(&philo->data->mutex[philo->num]);
	pthread_mutex_unlock(&philo->data->mutex[philo->num + 1]);
	return (0);
}

int	routine_sleep(t_philo *philo)
{
	long int	time;

	//empieza a dormir
	gettimeofday(&philo->start_sleep, NULL);
	//restar start-program y start sleep en miscrosegundos
	philo->l_start_sleep = (philo->start_sleep.tv_sec * 1000) + (philo->start_sleep.tv_usec / 1000);
	if ((philo->l_start_sleep - philo->l_start_eat) > philo->data->time_to_die)
	{
		time = philo->l_start_sleep - philo->data->l_start_time;
		pthread_mutex_lock(&philo->data->mutex_print);
		if (philo->data->muerte != 1)
			printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
		philo->data->muerte = 1;
		pthread_mutex_unlock(&philo->data->mutex_print);
		return (1);
	}
	time = philo->l_start_sleep - philo->data->l_start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(WHITE"%ldms Philo%d is sleeping\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
	//tiempo durmiendo
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	routine_think(t_philo *philo)
{
	long int	time;

	//empieza a pensar
	gettimeofday(&philo->start_think, NULL);
	//restar start-program y start think en miscrosegundos
	philo->l_start_think = (philo->start_think.tv_sec * 1000) + (philo->start_think.tv_usec / 1000);
	time = philo->l_start_think - philo->data->l_start_time;
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(BLUE"%ldms Philo%d is thinking\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(&philo->data->mutex_print);
	return (0);
	//tiempo durmiendo
	//usleep(philo->data->time_to_sleep);
}