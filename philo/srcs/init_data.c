/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:59:09 by zaiicko           #+#    #+#             */
/*   Updated: 2025/04/13 13:23:07 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->stop_lock, NULL) == 0)
		data->stop_init = 1;
	else
		destroy_mutex_and_cleanup(data);
	if (pthread_mutex_init(&data->print_lock, NULL) == 0)
		data->print_init = 1;
	else
		destroy_mutex_and_cleanup(data);
	if (pthread_mutex_init(&data->last_meal_lock, NULL) == 0)
		data->last_meal_init = 1;
	else
		destroy_mutex_and_cleanup(data);
	if (pthread_mutex_init(&data->counter_lock, NULL) == 0)
		data->counter_init = 1;
	else
		destroy_mutex_and_cleanup(data);
	if (pthread_mutex_init(&data->eating_lock, NULL) == 0)
		data->eating_init = 1;
	else
		destroy_mutex_and_cleanup(data);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_counter = 0;
		data->philos[i].last_meal = gettime_in_ms();
		data->philos[i].r_fork = &data->forks[(i + 1) % data->philos_nbr];
		data->philos[i].l_fork = &data->forks[i];
		if ((i + 1) % 2)
		{
			data->philos[i].r_fork = &data->forks[i];
			data->philos[i].l_fork = &data->forks[(i + 1) % data->philos_nbr];
		}
		data->philos[i].data = data;
		data->philos[i].is_eating = 0;
		i++;
	}
}

void	init_philo(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_nbr);
	if (!data->philos)
	{
		free(data->forks);
		destroy_all_mutex(data);
		error_msg("Error\nphilosopher struct allocation failed\n");
	}
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
			destroy_all_mutex(data);
			free(data->forks);
			error_msg("Error\nmutex init failed\n");
		}
		data->forks[i].init = 1;
		data->forks[i].id = i;
		i++;
	}
}

void	init_data(t_data *data)
{
	init_fork(data);
	init_mutex(data);
	init_philo(data);
	data->start_time = gettime_in_ms();
	data->stop_flag = 0;
}
