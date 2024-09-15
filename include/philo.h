/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:52:05 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/10 11:09:09 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include "get_next_line.h"
# include "printf.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <errno.h>

typedef struct s_fork
{
	int				id;
	int				used;
	pthread_mutex_t	used_mutex;
	pthread_mutex_t	fork_mutex;
}				t_fork;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				full;
	int				safe_meal;
	long int		last_meal;
	pthread_t		thread;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	safe_mutex;
	t_list			*fork_lst;
	struct s_table	*t_table;
}				t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				max_nb_eat;
	int				time_to_eat;
	int				time_to_sleep;
	long int		time_to_die;
	long int		start_time;
	int				end_table;
	t_list			*philo_lst;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_mutex;
}				t_table;

t_table	*ft_init_table(t_table *table, int ac, char **av);
void	ft_init_thread(t_table *table);
void	*ft_philo_routine(void *arg);
void	ft_monitor(t_table *table);
void	ft_take_forks(t_philo *philo);
void	ft_leave_forks(t_philo *philo);
void	ft_print_status(t_philo *philo, char *status);
void	ft_usleep(int time);
int		ft_get_time(void);
int		ft_table_end(t_table *table);
int		ft_check_args(int argc, char **argv);
void	ft_error(int error, t_table *table);
void	ft_free_all(t_table *table);

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

#endif