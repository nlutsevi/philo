/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:03 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/23 03:41:52 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define YELLOW "\033[1;33m"
# define GREEN  "\033[1;32m"
# define BLUE   "\033[1;34m"
# define PINK   "\033[1;35m"
# define GRAY   "\033[1;30m"
# define CYAN   "\033[1;36m"
# define RED    "\033[1;31m"
# define WHITE  "\033[0;37m"

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct		s_philo
{
	pthread_mutex_t	mutex_fork;
	pthread_t		thread;
	long int		last_eat;
	int				num;
	t_data			*data;

}					t_philo;

typedef struct		s_data
{
	int				muerte;
	int				num_philos;
	int				pair;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		time_to_eat;
	long int		start_time;
	pthread_mutex_t	mutex_print;
	t_philo			*philo;
}					t_data;

int					ft_atoi(const char *str);
void				init_threads(char **argv);
long int			get_time(void);
void				ft_usleep(long int time, t_data *data);
void				philo_died(t_philo *philo);
void				*philo_routine(void *arg);
void				routine_eat(t_philo *philo);
void				print_left_fork(t_philo *philo);
void				print_right_fork(t_philo *philo);
void				check_death(t_data *data);
void				print_eating(t_philo *philo);
void				routine_sleep(t_philo *philo);
void				routine_think(t_philo *philo);

#endif