/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:11:25 by mnadir            #+#    #+#             */
/*   Updated: 2023/01/01 12:29:48 by mnadir           ###   ########.fr       */
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
	sem_post(philo->ate);
	sem_close(philo->ate);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("ate");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
