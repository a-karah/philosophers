/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:31:36 by akarahan          #+#    #+#             */
/*   Updated: 2022/04/16 12:20:00 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ARGS_ERROR 1
# define ARGS_NUM_ERROR 2

typedef struct s_args
{
	int				nb_philo;
	int				max_eat;
	int				philo_ate;
	size_t			die_t;
	int				eat_t;
	int				sleep_t;
	int				stop_sim;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_lock;
	pthread_mutex_t	check_lock;
	pthread_mutex_t	nb_lock;
	pthread_mutex_t	death_lock;
}				t_args;

typedef struct s_philo
{
	pthread_t	tid;
	t_args		*args;
	int			num;
	size_t		start_t;
	size_t		last_meal;
	int			nb_eat;
	short		is_finished;
	int			r_fork;
	int			l_fork;
}				t_philo;

/* utils.c */
size_t	get_time(void);
void	psleep(size_t ms);
long	ft_atol(char *s);
int		ft_isdigit(char *s);

/* philo_utils.c */
void	eat_time(t_philo *ph);
void	sleep_time(t_philo *ph);
void	think_time(t_philo *ph);
void	die_time(t_philo *ph);

/* init.c */
t_philo	**init_philo(t_args *args);
void	init_mutex(t_args *args);

/* parse.c */
int		check_args(char **s);
t_args	*parse_args(char **s);

/* free_all.c */
void	free_philo(t_philo **ph);
void	free_args(t_args *args);

/* death_checkers.c */
size_t	check_meals(t_philo *ph);
int		check_nb(t_philo *ph);
int		check_death(t_philo *ph);

/* death_setters.c */
void	set_meals(t_philo *ph);
void	set_nb(t_philo *ph);
void	set_death(t_philo *ph);

/* error.c */
void	handle_error(short error_code);

#endif
