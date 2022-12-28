/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsassign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:13:21 by mnadir            #+#    #+#             */
/*   Updated: 2022/12/28 15:47:26 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

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
	if (data->phn < 1)
		return (printf("invalid arguments.\n"), exit(0), NULL);
	if (argc == 6)
		data->m2e = ft_atoi(argv[5]) * data->phn;
	else
		data->m2e = -1;
	return (data);
}

void	child_create(t_philo *philo)
{
	int	inx;

	inx = 0;
	while (inx < philo->data->phn)
	{
		philo->pid[inx] = fork();
		philo->inx = inx;
		if (!philo->pid[inx])
			child_routine(philo);
		else if (philo->pid[inx] < 0)
		{
			killmychilds(philo->pid, philo);
			exit(-1);
		}
		inx++;
		usleep(100);
	}
}

t_philo	*philo_init(t_data *data)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(*philo));
	if (!philo)
		return (NULL);
	philo->data = data;
	philo->pid = ft_calloc(data->phn, sizeof(*(philo->pid)));
	if (!(philo->pid))
		return (free(philo), NULL);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("ate");
	philo->fork = sem_open("fork", O_CREAT, 0666, data->phn);
	philo->print = sem_open("print", O_CREAT, 0666, 1);
	philo->ate = sem_open("ate", O_CREAT, 0666, 0);
	philo->tlm = currenttime();
	data->ss = currenttime();
	child_create(philo);
	return (philo);
}

t_philo	*parassign(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (is_vint(argv[1]) < 0 || is_vint(argv[2]) < 0 || is_vint(argv[3]) < 0 \
		|| is_vint(argv[4]) < 0 || (argc == 6 && is_vint(argv[5]) < 0))
		return (printf("invalid arguments.\n"), exit(0), NULL);
	data = data_init(argc, argv);
	if (!data)
		return (exit(0), NULL);
	philo = philo_init(data);
	if (!philo)
		return (free(data), exit(0), NULL);
	return (philo);
}
