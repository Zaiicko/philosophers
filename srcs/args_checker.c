/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:03:48 by zaiicko           #+#    #+#             */
/*   Updated: 2024/09/27 20:20:58 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_if_args_are_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
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
	check_if_args_are_int(av);
}
