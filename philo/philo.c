/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:31:07 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/24 15:05:37 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_philo		*philo;
	pthread_t	thread;

	if (argc != 5 && argc != 6)
		return (printf("the number of arguments given weren't enough.\n"), -1);
	philo = parassign(argc, argv);
	if (!philo)
		return (-1);
	pthread_create(&thread, NULL, watcher, philo);
	pthread_join(thread, NULL);
	return (0);
}
