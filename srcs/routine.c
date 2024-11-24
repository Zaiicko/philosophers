/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:09:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/24 20:49:28 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_data *data)
{
	long	ts;

	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is sleeping\n", ts, data->philos->philo_id);
	usleep(data->time_to_sleep * 1000);
}

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
