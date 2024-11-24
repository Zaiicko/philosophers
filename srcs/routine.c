/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:09:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/24 19:20:33 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//void	sleep(t_data *data)

//void	eat(t_data *data)

void	think(t_data *data)
{
	long	ts;

	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is thinking\n", ts, data->philos->philo_id);
}

/*void	*routine(void *philo)
{
}*/
