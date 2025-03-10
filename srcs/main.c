/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:54:58 by zaiicko           #+#    #+#             */
/*   Updated: 2025/03/09 16:59:06 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av + 1);
	parse_args(ac, av, &data);
	init_data(&data);
	thread_managing(&data);
	destroy_all_mutex(&data);
	free_all_data(&data);
}
