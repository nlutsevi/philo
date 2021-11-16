/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:45:27 by nlutsevi          #+#    #+#             */
/*   Updated: 2021/08/21 22:32:46 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(int argc, char *argv[])
{
	if (argc < 5)
	{
		printf(RED"Too few argumens: \n1 - number of philosophers\n2 - time to die\n3 - time to sleep\n4 - time to eat\n5 - times that each philosopher needs to eat (optional)\n"WHITE);
		return (-1);
	}
	else
	{
		init_threads(argv);
	}
	return (0);
}