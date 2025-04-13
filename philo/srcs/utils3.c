/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:48:19 by zaiicko           #+#    #+#             */
/*   Updated: 2025/04/13 13:23:17 by zaiicko          ###   ########.fr       */
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
		if (data->forks[i].init == 1)
		{
			pthread_mutex_destroy(&data->forks[i].fork);
		}
		i++;
	}
	if (data->stop_init == 1)
		pthread_mutex_destroy(&data->stop_lock);
	if (data->print_init == 1)
		pthread_mutex_destroy(&data->print_lock);
	if (data->last_meal_init == 1)
		pthread_mutex_destroy(&data->last_meal_lock);
	if (data->counter_init == 1)
		pthread_mutex_destroy(&data->counter_lock);
	if (data->eating_init == 1)
		pthread_mutex_destroy(&data->eating_lock);
}

void	destroy_mutex_and_cleanup(t_data *data)
{
	destroy_all_mutex(data);
	error_msg_free("Error\nmutex init failed\n", data);
}
