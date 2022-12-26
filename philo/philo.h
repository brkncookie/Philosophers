/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:32:13 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/26 10:58:47 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				t2d;	
	int				t2e;	
	int				t2s;	
	int				phn;
	int				ate;
	int				m2e;
	long			ss;
}	t_data;
typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	long			tlm;
	int				inx;
	t_data			*data;
}	t_philo;
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
t_philo	*parassign(int argc, char **argv);
void	*philostat(void *parm);
void	*watcher(void	*parm);
long	currenttime(void);
void	mutextroy(t_data *data, pthread_mutex_t *print, pthread_mutex_t *fork);
void	mssleep(long time_ms);
long	currenttime(void);
void	locknprint(t_philo *philo, char *str, int dead);
#endif
