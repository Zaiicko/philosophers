/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:48:19 by zaiicko           #+#    #+#             */
/*   Updated: 2025/02/11 21:10:02 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	one_philo_case(t_philo *philo)
{
	mutex_lock_and_print(&philo->r_fork->fork, philo);
	opti_usleep(philo->data->time_to_die, philo->data);
	pthread_mutex_unlock(&philo->r_fork->fork);
}
