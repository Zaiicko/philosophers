/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:09:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/26 19:23:04 by zaiicko          ###   ########.fr       */
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

void	eat(t_data *data)
{
	long	ts;

	pthread_mutex_lock(&data->philos->r_fork->fork);
	pthread_mutex_lock(&data->philos->l_fork->fork);
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is eating\n", ts, data->philos->philo_id);
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->philos->r_fork->fork);
	pthread_mutex_unlock(&data->philos->l_fork->fork);
}

void	think(t_data *data)
{
	long	ts;

	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is thinking\n", ts, data->philos->philo_id);
}

void	*routine(void *data)
{
	while (1)
	{
		eat((t_data *)data);
		philo_sleep((t_data *)data);
		think((t_data *)data);
	}
	return (0);
}
