/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:28:50 by akarahan          #+#    #+#             */
/*   Updated: 2022/04/12 17:14:17 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **ph)
{
	t_philo	**head;

	head = ph;
	while (ph && *ph)
		free(*ph++);
	free(head);
}

void	free_args(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nb_philo)
		pthread_mutex_destroy(&args->forks[i]);
	free(args->forks);
	pthread_mutex_destroy(&args->printf_lock);
	pthread_mutex_destroy(&args->check_lock);
	pthread_mutex_destroy(&args->nb_lock);
	pthread_mutex_destroy(&args->death_lock);
	free(args);
}
