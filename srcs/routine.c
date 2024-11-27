/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:09:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/27 18:55:14 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is sleeping\n", ts, philo->id);
	usleep(data->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	pthread_mutex_lock(&philo->r_fork->fork);
	pthread_mutex_lock(&philo->l_fork->fork);
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is eating\n", ts, philo->id);
	philo->meals_counter++;
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->r_fork->fork);
	pthread_mutex_unlock(&philo->l_fork->fork);
}

void	think(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is thinking\n", ts, philo->id);
}

void	*routine(void *philo)
{
	t_data	*data;

	data = ((t_philo *)philo)->data;
	while (1)
	{
		eat((t_philo *)philo);
		philo_sleep((t_philo *)philo);
		think((t_philo *)philo);
		if (((t_philo *)philo)->meals_counter == data->meals_nbr)
			break ;
	}
	return (0);
}
