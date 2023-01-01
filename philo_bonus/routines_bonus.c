/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:11:16 by mnadir            #+#    #+#             */
/*   Updated: 2023/01/01 12:11:17 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

void	*child_watcher(void	*parm)
{
	t_philo	*philo;

	philo = (t_philo *)parm;
	while (1)
	{
		if (currenttime() - philo->tlm > philo->data->t2d)
			return (locknprint(philo, "died", 1), NULL);
	}
	return (NULL);
}

void	child_routine(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, child_watcher, philo);
	pthread_detach(thread);
	while (1)
	{
		sem_wait(philo->fork);
		locknprint(philo, "has taken a fork", 0);
		sem_wait(philo->fork);
		locknprint(philo, "has taken a fork", 0);
		locknprint(philo, "is eating", 0);
		philo->tlm = currenttime();
		mssleep(philo->data->t2e);
		sem_post(philo->ate);
		sem_post(philo->fork);
		sem_post(philo->fork);
		locknprint(philo, "is sleeping", 0);
		mssleep(philo->data->t2s);
		locknprint(philo, "is thinking", 0);
	}
}

void	*enough_eating(void *parm)
{
	t_philo	*philo;
	int		count;

	philo = (t_philo *)parm;
	count = 0;
	if (philo->data->m2e != -1)
	{
		while (1)
		{
			sem_wait(philo->ate);
			count++;
			if (count == philo->data->m2e)
			{
				sem_wait(philo->print);
				killmychilds(philo->pid, philo);
				exit(0);
			}
		}
	}
	return (philo);
}
