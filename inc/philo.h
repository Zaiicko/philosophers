/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:52:56 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/08 02:43:48 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
}	t_philo;

typedef struct s_data
{
	int			philos_nbr;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_nbr;
	t_philo		*philos;
}	t_data;

void	error_msg(char *msg);
void	check_args(int ac, char **av);
long	ft_atol(const char *str);
void	check_if_valid_numbers(char **av);

#endif
