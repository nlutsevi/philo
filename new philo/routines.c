#include "philo.h"

void	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(RED"%ldms Philo%d died\n"WHITE, time, (philo->num + 1));
	philo->data->muerte = 1;
	pthread_mutex_unlock(philo->data->mutex_print);
}

void	*philo_routine(void *arg)
{
	while (1)
	{
		if (routine_eat(arg))
			break;
	}
}

void	print_right_fork(t_philo *philo)
{
	long int	time;

	time = philo[philo->num]->taken_left_fork - philo->data->start_time;
	pthread_mutex_lock(philo->data->mutex_print);
	if (philo->data->muerte != 1)
		printf(YELLOW"%ldms Philo%d has taken a fork(left)\n"WHITE, time, (philo->num + 1));
	pthread_mutex_unlock(philo->data->mutex_print);
}

int		philo_takes_right_fork(t_philo *philo)
{
	long int	last_time;

	last_time = philo[philo->num]->taken_right_fork;
	//juntas las dos y seguir a partir de aqui
	if ((philo->num + 1) != data->num_philo)
	{
		if (pthread_mutex_lock(philo->data->mutex[philo->num + 1]) != 0)
			return (1);
		philo[philo->num]->taken_right_fork = get_time();
		philo->data->fork[philo->num + 1] = 1;
		if (last_time == 0 && ((philo[philo->num]->taken_right_fork - philo->data->start_time) > philo->data->time_to_die))) || \
			((philo[philo->num]->taken_right_fork - philo[philo->num]->start_eat) > philo->data->time_to_die)
		{
			philo_died(philo);
			return (1);
		}
	}
	else
	{
		if (pthread_mutex_lock(philo->data->mutex[0]) != 0)
			return (1);
		philo[philo->num]->taken_right_fork = get_time();
		philo->data->fork[0] = 1;
		if (last_time == 0 && ((philo[philo->num]->taken_right_fork - philo->data->start_time) > philo->data->time_to_die))) || \
			((philo[philo->num]->taken_right_fork - philo[philo->num]->start_eat) > philo->data->time_to_die)
		{
			philo_died(philo);
			return (1);
		}

	}
}

int		philo_takes_forks(t_philo *philo)
{
	long int	last_time;

	last_time = philo[philo->num]->taken_left_fork;
	if (pthread_mutex_lock(philo->data->mutex[philo->num]) != 0)
		return (1);
	philo[philo->num]->taken_left_fork = get_time();
	philo->data->fork[philo->num] = 1;
	if (last_time == 0 && ((philo[philo->num]->taken_left_fork - philo->data->start_time) > philo->data->time_to_die))) || \
		((philo[philo->num]->taken_left_fork - philo[philo->num]->start_eat) > philo->data->time_to_die)
	{
		philo_died(philo);
		return (1);
	}
	print_right_fork(philo);
	philo_takes_right_fork(philo);
}

int		routine_eat(t_philo *philo)
{
	long int	last_eat;

	last_eat = 0;
	philo_takes_forks(philo);
}