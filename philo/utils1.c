/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:57:01 by mnadir            #+#    #+#             */
/*   Updated: 2023/01/01 10:42:50 by mnadir           ###   ########.fr       */
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
	printf("%ld %d %s\n", currenttime() - philo->data->ss, philo->inx + 1, str);
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

void	mutextroy(t_data *data, pthread_mutex_t *print, pthread_mutex_t *fork)
{
	int	inx;

	inx = 0;
	while (inx < data->phn)
		pthread_mutex_destroy(&fork[inx++]);
	pthread_mutex_destroy(print);
	free(fork);
	free(print);
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
