/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:09:48 by zaiicko           #+#    #+#             */
/*   Updated: 2025/01/25 19:14:04 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*monitor(void *av)
{
	t_data	*data;
	int		i;

	data = (t_data *)av;
	while (1)
	{
		i = 0;
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
			pthread_mutex_unlock(&data->lock);
			i++;
		}
		usleep(10000);
	}
}
