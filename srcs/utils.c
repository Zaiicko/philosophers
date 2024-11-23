/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:56:14 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/23 15:56:19 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_msg(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

long	ft_atol(const char *str)
{
	size_t			i;
	int				signe;
	unsigned long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * signe);
}

long	gettime_in_ms(void)
{
	long	ms;
	struct timeval tv;

	ms = 0;
	if (gettimeofday(&tv, NULL))
		return (-1);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	free_all_data(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	error_msg_free(char *msg, t_data *data)
{
	free_all_data(data);
	error_msg(msg);
}
