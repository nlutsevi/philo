/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:47:51 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/12/02 22:51:51 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf(RED"Too few argumens: \n1 - number of philosophers\n\
2 - time to die\n3 - time to sleep\n4 - time to eat\n\
5 - times that each philosopher needs to eat (optional)\n"WHITE);
		return (-1);
	}
	else
		init_threads(argc, argv);
	return (0);
}
