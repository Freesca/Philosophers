/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:40:44 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/28 14:44:58 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	ft_take_forks(philo);
	if (philo->t_table->nb_philo == 1)
		return ;
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_meal = ft_get_time() - philo->t_table->start_time;
	philo->nb_eat++;
	ft_print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(philo->t_table->time_to_eat);
	ft_leave_forks(philo);
}

static void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	ft_usleep(philo->t_table->time_to_sleep);
}

static void	ft_think(t_philo *philo)
{
	ft_print_status(philo, "is thinking");
}

void	*ft_philo_routine(void *arg)
{
	t_list		*lst;
	t_philo		*philo;

	lst = (t_list *)arg;
	philo = (t_philo *)lst->content;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	if (philo->id == 1)
		philo->t_table->start_time = ft_get_time();
	while (ft_table_end(philo->t_table) == 0)
	{
		ft_eat(philo);
		if (philo->t_table->nb_philo == 1)
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}
