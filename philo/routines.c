/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:14:55 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/23 15:40:13 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	locknprint(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print);
	printf("%d %s\n", philo->inx, str);
	pthread_mutex_unlock(philo->print);
}

int	currenttime(void)
{	
	struct timeval	time;		

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

void	*philostat(void *parm)
{
	t_philo	*philo;
	int		first;

	philo = (t_philo *)parm;
	first = 0;
	while (1)
	{
		if (philo->inx % 2)
			first = 1;
		if (first)
		{
			pthread_mutex_lock(&(philo->fork[philo->inx]));
			pthread_mutex_lock(&(philo->fork[philo->inx + 1 % \
						philo->data->phn]));
			locknprint(philo, "has taken a fork");
			locknprint(philo, "is eating");
			usleep(philo->data->t2e * 1000);
			philo->tlm = currenttime();
			philo->data->ate++;
			pthread_mutex_unlock(&(philo->fork[philo->inx]));
			pthread_mutex_unlock(&(philo->fork[philo->inx + 1 % \
						philo->data->phn]));
			locknprint(philo, "is sleeping");
			usleep(philo->data->t2s * 1000);
		}
		locknprint(philo, "is thinking");
		first = 1;
	}
	return (NULL);
}

void	*watcher(void	*parm)
{
	t_philo	*philo;
	int		inx;

	philo = (t_philo *)parm;
	while(1)
	{
		if(philo->data->m2e != -1 && (philo->data->m2e == philo->data->ate))
			return (NULL);
		inx = 0;
		while (inx < philo->data->phn)
		{
			if(currenttime() - philo[inx].tlm > (philo->data->t2d * 1000))
				return (locknprint(philo, "is dead"), NULL);
			inx++;
		}
	}
	return (NULL);
}
