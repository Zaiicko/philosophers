/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:09:48 by zaiicko           #+#    #+#             */
/*   Updated: 2025/03/23 13:55:18 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->last_meal_lock);
	if (gettime_in_ms() - data->philos[i].last_meal
		>= data->time_to_die)
	{
		printf("%ld %d died\n",
			(gettime_in_ms() - data->start_time), data->philos[i].id);
		set_stop_flag(data, 1);
		pthread_mutex_unlock(&data->last_meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->last_meal_lock);
	return (0);
}

int	check_status(t_data *data, int	*eating_philos)
{
	int	i;

	i = 0;
	*eating_philos = 0;
	while (i < data->philos_nbr)
	{
		pthread_mutex_lock(&data->lock);
		if (philo_dead(data, i))
		{
			pthread_mutex_unlock(&data->lock);
			return (1);
		}
		pthread_mutex_lock(&data->counter_lock);
		if (data->philos[i].meals_counter < data->meals_nbr)
			*eating_philos = 0;
		else
			(*eating_philos)++;
		pthread_mutex_unlock(&data->counter_lock);
		pthread_mutex_unlock(&data->lock);
		i++;
	}
	return (0);
}

void	*monitor(void *av)
{
	t_data	*data;
	int		eating_philos;

	data = (t_data *)av;
	while (1)
	{
		if (check_status(data, &eating_philos))
			return (NULL);
		if (data->meals_nbr != -1 && eating_philos == data->philos_nbr)
		{
			printf("That was a good meal ! %d times in a row.\n",
				data->meals_nbr);
			set_stop_flag(data, 1);
			return (NULL);
		}
		usleep(10000);
	}
}
