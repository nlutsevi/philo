/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:46:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/08/04 21:46:57 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILO_H
# define FILO_H
# define YELLOW "\033[1;33m"
# define GREEN  "\033[1;32m"
# define BLUE   "\033[1;34m"
# define PINK   "\033[1;35m"
# define GRAY   "\033[1;30m"
# define CYAN   "\033[1;36m"
# define RED    "\033[1;31m"
# define WHITE  "\033[0;37m"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>


typedef struct	s_data
{
	int				num_philos;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_to_die;
	struct timeval	start_time;
	long int		l_start_time;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	int				*fork;
	int				*fork_taken;
	int				dead_philo;
}				t_data;

typedef struct	s_philo
{
	int				num;
	struct timeval	taken_left_fork;
	long int		l_taken_left_fork;
	struct timeval	taken_right_fork;
	long int		l_taken_right_fork;
	struct timeval	start_eat;
	long int		l_start_eat;
	struct timeval	start_sleep;
	long int		l_start_sleep;
	struct timeval	start_think;
	long int		l_start_think;
	t_data			*data;
}				t_philo;

void				init_threads(char *argv[]);
void				routine_eat(t_philo *philo);
void				routine_sleep(t_philo *philo);
void				routine_think(t_philo *philo);
int					ft_atoi(const char *str);

#endif