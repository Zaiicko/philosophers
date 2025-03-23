/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:52:56 by zaiicko           #+#    #+#             */
/*   Updated: 2025/03/23 19:56:48 by zaiicko          ###   ########.fr       */
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

struct	s_data;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			meals_counter;
	long			last_meal;
	int				is_eating;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philos_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_nbr;
	int				stop_flag;
	long			start_time;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	last_meal_lock;
	pthread_mutex_t	counter_lock;
	pthread_mutex_t	eating_lock;
	pthread_t		monitor_thread_id;
	t_fork			*forks;
	t_philo			*philos;
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
long	gettime_in_ms(void);
void	thread_managing(t_data *data);
void	free_all_data(t_data *data);
void	error_msg_free(char *msg, t_data *data);
void	think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	eat(t_philo *philo);
void	*routine(void *philo);
void	*monitor(void *av);
void	set_stop_flag(t_data *data, int flag);
int		get_stop_flag(t_data *data);
void	opti_usleep(long time, t_data *data);
void	fork_unlock(t_philo *philo, int left_lock);
void	mutex_lock_and_print(pthread_mutex_t *fork, t_philo *philo);
void	one_philo_case(t_philo *philo);
void	destroy_all_mutex(t_data *data);
int		check_status(t_data *data, int	*eating_philos);
int		philo_dead(t_data *data, int i);
void	update_meal_status(t_philo *philo, t_data *data);

#endif
