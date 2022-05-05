/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:14:16 by akarahan          #+#    #+#             */
/*   Updated: 2022/04/16 12:38:51 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error(short error_code)
{
	if (error_code == ARGS_ERROR)
		printf("Argument is not a digit "
			"or it overflows int "
			"or it is negative "
			"or have two plus signs\n");
	else if (error_code == ARGS_NUM_ERROR)
		printf("Wrong number of arguments\n");
	exit(1);
}
