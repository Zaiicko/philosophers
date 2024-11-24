/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_managing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:03:48 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/24 04:14:09 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_if_valid_numbers(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) < 0 || ft_atol(av[i]) > INT_MAX)
			error_msg("Error\nInvalid number in args");
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				error_msg("Error\nThe args need only digits in it\n");
			j++;
		}
		i++;
	}
}

void	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		error_msg("Error\nWrong number of args\n");
	check_if_valid_numbers(av);
}

void	parse_args(int ac, char **av, t_data *data)
{
	data->philos_nbr = atol(av[1]);
	data->time_to_die = atol(av[2]);
	data->time_to_eat = atol(av[3]);
	data->time_to_sleep = atol(av[4]);
	if (ac == 6)
		data->meals_nbr = atol(av[5]);
	else
		data->meals_nbr = -1;
}
