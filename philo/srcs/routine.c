/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:09:28 by zaiicko           #+#    #+#             */
/*   Updated: 2025/03/23 17:56:34 by zaiicko          ###   ########.fr       */
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
	pthread_mutex_lock(&data->print_lock);
	printf("%ld %d is sleeping\n", ts, philo->id);
	pthread_mutex_unlock(&data->print_lock);
	opti_usleep(data->time_to_sleep, data);
}

void	eat(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	if (get_stop_flag(data))
		return ;
	mutex_lock_and_print(&philo->r_fork->fork, philo);
	if (get_stop_flag(data))
		return (fork_unlock(philo, 0));
	mutex_lock_and_print(&philo->l_fork->fork, philo);
	if (get_stop_flag(data))
		return (fork_unlock(philo, 1));
	ts = gettime_in_ms() - data->start_time;
	pthread_mutex_lock(&data->print_lock);
	printf("%ld %d is eating\n", ts, philo->id);
	pthread_mutex_unlock(&data->print_lock);
	pthread_mutex_lock(&data->last_meal_lock);
	philo->last_meal = gettime_in_ms();
	pthread_mutex_unlock(&data->last_meal_lock);
	pthread_mutex_lock(&data->counter_lock);
	philo->meals_counter++;
	pthread_mutex_unlock(&data->counter_lock);
	opti_usleep(data->time_to_eat, data);
	fork_unlock(philo, 1);
}

void	think(t_philo *philo)
{
	t_data	*data;
	long	ts;

	data = ((t_philo *)philo)->data;
	if (get_stop_flag(data))
		return ;
	ts = gettime_in_ms() - data->start_time;
	pthread_mutex_lock(&data->print_lock);
	printf("%ld %d is thinking\n", ts, philo->id);
	pthread_mutex_unlock(&data->print_lock);
}

void	*routine(void *philo)
{
	t_data	*data;

	data = ((t_philo *)philo)->data;
	if (data->philos_nbr == 1)
	{
		one_philo_case(philo);
		return (0);
	}
	while (!get_stop_flag(data))
	{
		eat((t_philo *)philo);
		philo_sleep((t_philo *)philo);
		think((t_philo *)philo);
		if (((t_philo *)philo)->meals_counter == data->meals_nbr)
			break ;
	}
	return (0);
}
