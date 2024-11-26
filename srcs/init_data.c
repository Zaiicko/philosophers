/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:59:09 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/26 18:53:26 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals_counter = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].r_fork = &data->forks[(i + 1) % data->philos_nbr];
		data->philos[i].l_fork = &data->forks[i];
		if ((i + 1) % 2)
		{
			data->philos[i].r_fork = &data->forks[i];
			data->philos[i].l_fork = &data->forks[(i + 1) % data->philos_nbr];
		}
		data->philos[i].data = data;
		i++;
	}
}

void	init_philo(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_nbr);
	if (!data->philos)
		error_msg_free("Error\nphilo struc allocation failed\n", data);
	init_philosophers(data);
}

void	init_fork(t_data *data)
{
	int	i;

	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->philos_nbr);
	if (!data->forks)
		error_msg("Error\nfork struct allocation failed\n");
	i = 0;
	while (i < data->philos_nbr)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL))
		{
			free(data->forks);
			error_msg("Error\nmutex init failed\n");
		}
		data->forks[i].fork_id = i;
		i++;
	}
}

void	init_data(t_data *data)
{
	init_fork(data);
	init_philo(data);
	data->start_time = gettime_in_ms();
}
