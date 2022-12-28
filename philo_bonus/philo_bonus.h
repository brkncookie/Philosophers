/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:32:55 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/28 12:22:01 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int				t2d;	
	int				t2e;	
	int				t2s;	
	int				phn;
	int				m2e;
	long			ss;
}	t_data;
typedef struct s_philo
{
	pid_t			*pid;
	int				inx;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*ate;
	long			tlm;
	t_data			*data;
}	t_philo;
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
t_philo	*parassign(int argc, char **argv);
void	mssleep(long time_ms);
long	currenttime(void);
void	locknprint(t_philo *philo, char *str, int dead);
void	child_routine(t_philo *philo);
void	*enough_eating(void *parm);
void	killmychilds(pid_t *pid, t_philo *philo);
#endif
