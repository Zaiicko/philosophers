/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:09:48 by zaiicko           #+#    #+#             */
/*   Updated: 2025/02/26 15:46:49 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_status(t_data *data, int	*eating_philos)
{
	int	i;

	i = 0;
	*eating_philos = 0;
	while (i < data->philos_nbr)
	{
		pthread_mutex_lock(&data->lock);
		if (gettime_in_ms() - data->philos[i].last_meal
			>= data->time_to_die)
		{
			printf("%ld The philo nbr |%d| died ! Rip bozo\n",
				(gettime_in_ms() - data->start_time), data->philos[i].id);
			set_stop_flag(data, 1);
			pthread_mutex_unlock(&data->lock);
			return (1);
		}
		if (data->philos[i].meals_counter < data->meals_nbr)
			*eating_philos = 0;
		else
			(*eating_philos)++;
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

/*void	*monitor(void *av)
{
	t_data	*data;
	int		i;
	int		eating_philos;

	data = (t_data *)av;
	while (1)
	{
		i = 0;
		eating_philos = 0;
		while (i < data->philos_nbr)
		{
			pthread_mutex_lock(&data->lock);
			if (gettime_in_ms() - data->philos[i].last_meal
				>= data->time_to_die)
			{
				printf("%ld The philo nbr |%d| died ! Rip bozo\n",
					(gettime_in_ms() - data->start_time), data->philos[i].id);
				set_stop_flag(data, 1);
				pthread_mutex_unlock(&data->lock);
				return (NULL);
			}
			if (data->philos[i].meals_counter < data->meals_nbr)
				eating_philos = 0;
			else
				eating_philos++;
			pthread_mutex_unlock(&data->lock);
			i++;
		}
		if (data->meals_nbr != -1 && eating_philos == data->philos_nbr)
		{
			printf("That was a good meal ! %d times in a row.\n", data->meals_nbr);
			set_stop_flag(data, 1);
			return (NULL);
		}
		usleep(10000);
	}
}*/
