/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:07:17 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/28 15:44:44 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_table_end(t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_table == 1)
	{
		pthread_mutex_unlock(&table->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

int	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(int time)
{
	long int	start;
	long int	end;

	start = ft_get_time();
	end = start + time;
	while (ft_get_time() < end)
		usleep(1);
}

void	ft_print_status(t_philo *philo, char *status)
{
	long int		time;

	pthread_mutex_lock(&philo->t_table->print_mutex);
	time = ft_get_time() - philo->t_table->start_time;
	if (ft_table_end(philo->t_table) == 0)
		ft_printf(1, "%d %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->t_table->print_mutex);
}
