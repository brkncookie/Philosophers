/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:10:52 by mnadir            #+#    #+#             */
/*   Updated: 2023/01/01 12:15:27 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char	**argv)
{
	t_philo		*philo;
	pthread_t	thread;

	if (argc != 5 && argc != 6)
		return (printf("the number of arguments given weren't enough.\n"), -1);
	philo = parassign(argc, argv);
	if (!philo)
		return (-1);
	pthread_create(&thread, NULL, enough_eating, philo);
	pthread_detach(thread);
	waitpid(-1, NULL, 0);
	killmychilds(philo->pid, philo);
	return (0);
}
