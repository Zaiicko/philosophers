/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:48:19 by zaiicko           #+#    #+#             */
/*   Updated: 2025/03/23 18:28:50 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	one_philo_case(t_philo *philo)
{
	mutex_lock_and_print(&philo->r_fork->fork, philo);
	opti_usleep(philo->data->time_to_die, philo->data);
	pthread_mutex_unlock(&philo->r_fork->fork);
}

void	destroy_all_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_mutex_destroy(&data->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->stop_lock);
	pthread_mutex_destroy(&data->last_meal_lock);
	pthread_mutex_destroy(&data->counter_lock);
}
