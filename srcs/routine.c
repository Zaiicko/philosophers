/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:09:28 by zaiicko           #+#    #+#             */
/*   Updated: 2025/02/01 18:37:04 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	if (get_stop_flag(data))
		return ;
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is sleeping\n", ts, philo->id);
	opti_usleep(data->time_to_sleep, data);
}

void	eat(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	if (get_stop_flag(data))
		return ;
	pthread_mutex_lock(&philo->r_fork->fork);
	if (get_stop_flag(data))
	{
		pthread_mutex_unlock(&philo->r_fork->fork);
		return ;
	}
	pthread_mutex_lock(&philo->l_fork->fork);
	if (get_stop_flag(data))
	{
		pthread_mutex_unlock(&philo->r_fork->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
		return ;
	}
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is eating\n", ts, philo->id);
	pthread_mutex_lock(&data->lock);
	philo->last_meal = gettime_in_ms();
	philo->meals_counter++;
	pthread_mutex_unlock(&data->lock);
	opti_usleep(data->time_to_eat, data);
	pthread_mutex_unlock(&philo->r_fork->fork);
	pthread_mutex_unlock(&philo->l_fork->fork);
}

void	think(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	if (get_stop_flag(data))
		return ;
	ts = gettime_in_ms() - data->start_time;
	printf("%ld %d is thinking\n", ts, philo->id);
}

void	*routine(void *philo)
{
	t_data	*data;

	data = ((t_philo *)philo)->data;
	while (1)
	{
		if (get_stop_flag(data))
			break ;
		eat((t_philo *)philo);
		philo_sleep((t_philo *)philo);
		think((t_philo *)philo);
		if (((t_philo *)philo)->meals_counter == data->meals_nbr)
			break ;
	}
	return (0);
}
