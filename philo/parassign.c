/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsassign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:13:21 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/25 11:16:29 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	is_vint(char *s)
{
	while (s && *s && ft_isspace(*s))
		s++;
	while (s && *s && ft_isdigit(*s))
		s++;
	if (*s)
		return (-1);
	return (0);
}

t_data	*data_init(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(*data));
	if (!data)
		return (NULL);
	data->phn = ft_atoi(argv[1]);
	data->t2d = ft_atoi(argv[2]);
	data->t2e = ft_atoi(argv[3]);
	data->t2s = ft_atoi(argv[4]);
	if (argc == 6)
		data->m2e = ft_atoi(argv[5]) * data->phn;
	else
		data->m2e = -1;
	return (data);
}

void	threads_create(t_philo *philo)
{
	int	inx;

	inx = 1;
	while (inx < philo->data->phn)
	{
		pthread_create(&(philo[inx].philo), NULL, philostat, &philo[inx]);
		pthread_detach(philo[inx].philo);
		inx += 2;
	}
	usleep(100);
	inx = 0;
	while (inx < philo->data->phn)
	{
		pthread_create(&(philo[inx].philo), NULL, philostat, &philo[inx]);
		pthread_detach(philo[inx].philo);
		inx += 2;
	}
}

t_philo	*philo_init(t_data *data, int inx)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;

	fork = ft_calloc(data->phn, sizeof(*fork));
	print = ft_calloc(1, sizeof(*print));
	if (!fork || !print)
		return (free(fork), free(print), NULL);
	while (inx < data->phn)
		pthread_mutex_init(&fork[inx++], NULL);
	pthread_mutex_init(print, NULL);
	philo = ft_calloc(data->phn, sizeof(*philo));
	if (!philo)
		return (free(fork), free(print), NULL);
	inx = 0;
	while (inx < data->phn)
	{
		philo[inx].fork = fork;
		philo[inx].print = print;
		philo[inx].tlm = currenttime();
		philo[inx].inx = inx;
		philo[inx].data = data;
		inx++;
	}
	return (philo);
}

t_philo	*parassign(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (is_vint(argv[1]) < 0 || is_vint(argv[2]) < 0 || is_vint(argv[3]) < 0 \
		|| is_vint(argv[4]) < 0 || (argc == 6 && is_vint(argv[5]) < 0))
		return (printf("invalid arguments.\n"), NULL);
	data = data_init(argc, argv);
	if (!data)
		return (NULL);
	philo = philo_init(data, 0);
	if (!philo)
		return (free(data), NULL);
	data->ss = currenttime();
	threads_create(philo);
	return (philo);
}
