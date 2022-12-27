/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:14:55 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/27 15:50:00 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

void	*child_watcher(void	*parm)
{
	t_philo	*philo;
	int		inx;

	philo = (t_philo *)parm;
	while (1)
	{
		if (currenttime() - philo->tlm > philo->data->t2d)
			return (locknprint(philo, "died", 1), exit(0), NULL);
		inx++;
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
	while (1)
	{
		sem_wait(philo->ate);
		count++;
		if (count == philo->data->m2e)
			exit(0);
	}
	return (philo);
}
