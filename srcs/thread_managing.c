/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:28:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/29 02:58:36 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thread_managing(t_data *data)
{
	int	i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &routine,
			&data->philos[i]);
		i++;
	}
	pthread_create(&monitor_thread, NULL, &monitor, &data);

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
