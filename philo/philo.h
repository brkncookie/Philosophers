/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:32:13 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/23 15:39:44 by mnadir           ###   ########.fr       */
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
}	t_data;
typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	int				tlm;
	int				inx;
	t_data			*data;
}	t_philo;
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
t_philo	*parassign(int argc, char **argv);
void	*watcher(void	*parm);
void	*philostat(void *parm);
#endif
