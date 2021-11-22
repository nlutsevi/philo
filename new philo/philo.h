/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:03 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/11/22 06:55:32 by nlutsevi         ###   ########.fr       */
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
	int				fork;
	pthread_mutex_t	mutex_fork;
	pthread_t		thread;
	// long int		taken_right_fork;
	// long int		taken_left_fork;
	// long int		start_eat;
	// long int		start_sleep;
	// long int		start_think;
	long int		last_eat;
	int				num;
	t_data			*data;

}					t_philo;

typedef struct		s_data
{
	int				muerte;
	int				num_philos;
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
void				philo_died(t_philo *philo);
void				*philo_routine(void *arg);
int					routine_eat(t_philo *philo);
int					philo_takes_forks(t_philo *philo, int right_hand);
int					philo_takes_right_fork(t_philo *philo, int right_hand);
int					philo_starts_eat(t_philo *philo, int right_hand);
void				print_left_fork(t_philo *philo);
void				print_right_fork(t_philo *philo);
void				check_death(t_data *data);

#endif