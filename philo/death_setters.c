/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:23:12 by akarahan          #+#    #+#             */
/*   Updated: 2022/04/13 22:23:13 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_meals(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->check_lock);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->args->check_lock);
}

void	set_nb(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->nb_lock);
	++ph->nb_eat;
	pthread_mutex_unlock(&ph->args->nb_lock);
}

void	set_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->death_lock);
	ph->args->stop_sim = 1;
	pthread_mutex_unlock(&ph->args->death_lock);
}
