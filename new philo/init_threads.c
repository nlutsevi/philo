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

void		init_vars(char **argv)
{
	t_data	*data;

	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	data->time_to_eat = ft_atoi(argv[4]);
}

long int	get_l_time()
{
	
}


void		init_threads(char **argv)
{
	init_vars(argv);
	prog_start = get_l_time()
}