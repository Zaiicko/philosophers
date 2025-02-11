/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:51:56 by zaiicko           #+#    #+#             */
/*   Updated: 2025/02/11 18:38:43 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_stop_flag(t_data *data, int flag)
{
	pthread_mutex_lock(&data->stop_lock);
	data->stop_flag = flag;
	pthread_mutex_unlock(&data->stop_lock);
}

int	get_stop_flag(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->stop_lock);
	flag = data->stop_flag;
	pthread_mutex_unlock(&data->stop_lock);
	return (flag);
}

void	opti_usleep(long time, t_data *data)
{
	long	start;

	start = gettime_in_ms();
	while ((gettime_in_ms() - start) < time)
	{
		if (get_stop_flag(data))
			break ;
		usleep(500);
	}
}

void	fork_unlock(t_data *data, int left_lock)
{
	pthread_mutex_unlock(&data->philos->r_fork->fork);
	if (left_lock)
		pthread_mutex_unlock(&data->philos->l_fork->fork);
}

void	mutex_lock_and_print(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(fork);
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%ld %d has taken a fork\n", gettime_in_ms()
		- philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_lock);
}
