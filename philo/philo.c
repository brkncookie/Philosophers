/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:31:07 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/23 15:39:48 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int	argc, char	**argv)
{
	t_philo	*philo;
	pthread_t	thread;

	philo = parassign(argc, argv);
	if(!philo)
		return (0);
	pthread_create(&thread, NULL, watcher, philo);
	pthread_join(thread, NULL);
	return(0);
}
