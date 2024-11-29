/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:28:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/29 03:43:45 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thread_managing(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &routine,
			&data->philos[i]);
		i++;
	}
	pthread_create(&data->monitor_thread_id, NULL, &monitor, data);

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(data->monitor_thread_id, NULL);
}
