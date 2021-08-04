/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:13:07 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/08/04 21:51:28 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_takes_left_fork(t_philo *philo)
{
	long int	time;

	//coge el tenedor de la izquierda
	pthread_mutex_lock(&philo->data->mutex[philo->num]);
	gettimeofday(&philo->taken_left_fork, NULL);
	//restar start-program y taken left fork en miscrosegundos
	philo->l_taken_left_fork = (philo->taken_left_fork.tv_sec * 1000) + (philo->taken_left_fork.tv_usec / 1000);
	time = philo->l_taken_left_fork - philo->data->l_start_time;
	printf(YELLOW"%ldms Philo%d has taken a fork\n"WHITE, time, (philo->num + 1));
	//ponemos las variables tenedor y tenedor cogido en 1
	philo->data->fork[philo->num] = 1;
	philo->data->fork_taken[philo->num] = 1;
}

void	philo_takes_right_fork(t_philo *philo)
{
	long int	time;

	//coge el tenedor de la derecha
	pthread_mutex_lock(&philo->data->mutex[philo->num + 1]);
	gettimeofday(&philo->taken_right_fork, NULL);
	//restar start-program y taken right fork en miscrosegundos
	philo->l_taken_right_fork = (philo->taken_right_fork.tv_sec * 1000) + (philo->taken_right_fork.tv_usec / 1000);
	time = philo->l_taken_right_fork - philo->data->l_start_time;
	printf(YELLOW"%ldms Philo%d has taken a fork\n"WHITE, time, (philo->num + 1));
	//ponemos las variables tenedor y tenedor cogido en 1
	philo->data->fork[philo->num + 1] = 1;
	philo->data->fork_taken[philo->num + 1] = 1;
}

void	routine_eat(t_philo *philo)
{
	long int	time;

	// while ()
	//se cogen los cubiertos
	philo_takes_left_fork(philo);
	philo_takes_right_fork(philo);
	
	//empieza a comer
	gettimeofday(&philo->start_eat, NULL);
	//restar start-program y start eat en miscrosegundos
	philo->l_start_eat = (philo->start_eat.tv_sec * 1000) + (philo->start_eat.tv_usec / 1000);
	time = philo->l_start_eat - philo->data->l_start_time;
	printf(GREEN"%ldms Philo%d is eating\n"WHITE, time, (philo->num + 1));
	
	//tiempo comiendo
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->mutex[philo->num]);
	pthread_mutex_unlock(&philo->data->mutex[philo->num + 1]);
}

void	routine_sleep(t_philo *philo)
{
	long int	time;

	//empieza a dormir
	gettimeofday(&philo->start_sleep, NULL);
	//restar start-program y start sleep en miscrosegundos
	philo->l_start_sleep = (philo->start_sleep.tv_sec * 1000) + (philo->start_sleep.tv_usec / 1000);
	time = philo->l_start_sleep - philo->data->l_start_time;
	printf(WHITE"%ldms Philo%d is sleeping\n"WHITE, time, (philo->num + 1));
	//tiempo durmiendo
	usleep(philo->data->time_to_sleep);
}

void	routine_think(t_philo *philo)
{
	long int	time;

	//empieza a pensar
	gettimeofday(&philo->start_think, NULL);
	//restar start-program y start think en miscrosegundos
	philo->l_start_think = (philo->start_think.tv_sec * 1000) + (philo->start_think.tv_usec / 1000);
	time = philo->l_start_think - philo->data->l_start_time;
	printf(BLUE"%ldms Philo%d is thinking\n"WHITE, time, (philo->num + 1));
	//tiempo durmiendo
	//usleep(philo->data->time_to_sleep);
}