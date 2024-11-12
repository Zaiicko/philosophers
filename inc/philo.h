/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:52:56 by zaiicko           #+#    #+#             */
/*   Updated: 2024/11/12 01:41:33 by zaiicko          ###   ########.fr       */
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

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			philo_id;
	long		meals_counter;
	long		last_meal;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_data
{
	int			philos_nbr;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_nbr;
	t_mtx		lock;
	t_fork		*forks;
	t_philo		*philos;
}	t_data;

void	error_msg(char *msg);
void	check_args(int ac, char **av);
long	ft_atol(const char *str);
void	check_if_valid_numbers(char **av);
void	parse_args(int ac, char **av, t_data *data);
void	init_data(t_data *data);
void	init_fork(t_data *data);
void	init_philo(t_data *data);
void	init_philosophers(t_data *data);

#endif
