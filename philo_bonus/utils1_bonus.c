/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:57:01 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/28 12:21:44 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

long	currenttime(void)
{	
	struct timeval	time;		

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	locknprint(t_philo *philo, char *str, int dead)
{
	sem_wait(philo->print);
	printf("%ld %d %s\n", currenttime() - philo->data->ss, philo->inx + 1, str);
	if (dead)
		exit (0);
	sem_post(philo->print);
}

void	mssleep(long time_ms)
{
	long	time;

	time = currenttime();
	while (currenttime() - time < time_ms)
		usleep(time_ms / 10);
}

void	killmychilds(pid_t *pid, t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < philo->data->phn)
		kill(pid[idx++], SIGTERM);
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->ate);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("ate");
}
