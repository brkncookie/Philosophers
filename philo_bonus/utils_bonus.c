/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:11:36 by mnadir            #+#    #+#             */
/*   Updated: 2023/01/01 12:11:37 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

int	ft_isspace(int c)
{
	return ((c == 32 || (c > 8 && c < 14)));
}

int	ft_isdigit(int c)
{
	return ((c > 47 && c < 58));
}

int	ft_atoi(const char *str)
{
	int	sum;
	int	sgn;
	int	inx;

	sum = 0;
	sgn = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn *= -1;
		str++;
	}
	inx = 0;
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - 48);
		if (inx >= 19)
			return (-(sgn > 0));
		inx++;
		str++;
	}
	return (sum * sgn);
}

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}
