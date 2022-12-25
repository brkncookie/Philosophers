/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:14:55 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/25 11:19:33 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	currenttime(void)
{	
	struct timeval	time;		

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	locknprint(t_philo *philo, char *str, int dead)
{
	pthread_mutex_lock(philo->print);
	printf("%ld %d %s\n", currenttime() - philo->data->ss, philo->inx, str);
	if (dead)
		return ;
	pthread_mutex_unlock(philo->print);
}

void	mssleep(long time_ms)
{
	long	time;

	time = currenttime();
	while (currenttime() - time < time_ms)
		usleep(time_ms / 10);
}

void	*philostat(void *parm)
{
	t_philo		*philo;

	philo = (t_philo *)parm;
	while (1)
	{
		pthread_mutex_lock(&(philo->fork[philo->inx]));
		locknprint(philo, "has taken a fork", 0);
		pthread_mutex_lock(&(philo->fork[(philo->inx + 1) % \
					philo->data->phn]));
		locknprint(philo, "has taken a fork", 0);
		locknprint(philo, "is eating", 0);
		philo->tlm = currenttime();
		mssleep(philo->data->t2e);
		philo->data->ate++;
		pthread_mutex_unlock(&(philo->fork[(philo->inx + 1) % \
					philo->data->phn]));
		pthread_mutex_unlock(&(philo->fork[philo->inx]));
		locknprint(philo, "is sleeping", 0);
		mssleep(philo->data->t2s);
		locknprint(philo, "is thinking", 0);
	}
	return (NULL);
}

void	*watcher(void	*parm)
{
	t_philo	*philo;
	int		inx;

	philo = (t_philo *)parm;
	while (1)
	{
		if (philo->data->m2e != -1 && (philo->data->m2e == philo->data->ate))
			return (pthread_mutex_lock(philo->print), NULL);
		inx = 0;
		while (inx < philo->data->phn)
		{
			if (currenttime() - philo[inx].tlm > philo->data->t2d)
				return (locknprint(philo, "is dead", 1), NULL);
			inx++;
		}
	}
	return (NULL);
}
