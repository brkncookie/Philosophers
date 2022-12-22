/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:32:13 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/22 16:09:12 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

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
	int				e;
	int				s;
	int				t;
	t_data			*data;
}	t_philo;
#endif
