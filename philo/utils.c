/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:31:30 by akarahan          #+#    #+#             */
/*   Updated: 2022/04/16 12:02:38 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	psleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

int	ft_isdigit(char *s)
{
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || (*s == '+' && *(s + 1) != '+')))
			return (0);
		++s;
	}
	return (1);
}

long	ft_atol(char *s)
{
	int		sign;
	long	out;

	out = 0;
	sign = -1;
	while (*s == ' ' || *s == '\r' || *s == '\t')
		++s;
	if (*s == '-' && ++s)
		sign = 1;
	else if (*s == '+')
		++s;
	while (*s >= '0' && *s <= '9')
		out = out * 10 - (*s++ - '0');
	return (sign * out);
}
