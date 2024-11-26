/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:28:28 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/26 20:21:12 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thread_managing(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_create(&data->philos[i].thread_id, NULL, routine,
			&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}
