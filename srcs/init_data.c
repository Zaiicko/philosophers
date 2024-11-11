/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:59:09 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/11 19:20:22 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philo(t_data *data)
{	
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
			error_msg("Error\nmutex init failed\n");
		data->forks[i].fork_id = i;
		i++;
	}
}

void	init_data(t_data *data)
{
	init_fork();
	init_philo();
}
