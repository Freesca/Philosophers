/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:31:37 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/10 11:10:28 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_monitor_death(t_philo *philo)
{
	int			end;
	long int	time;

	end = 0;
	pthread_mutex_lock(&philo->eat_mutex);
	time = ft_get_time() - philo->t_table->start_time;
	if (time - philo->last_meal > philo->t_table->time_to_die + 4)
	{
		ft_print_status(philo, "died");
		pthread_mutex_lock(&philo->t_table->end_mutex);
		philo->t_table->end_table = 1;
		pthread_mutex_unlock(&philo->t_table->end_mutex);
		end = 1;
	}
	pthread_mutex_unlock(&philo->eat_mutex);
	return (end);
}

static int	ft_monitor_nb_eat(t_philo *philo, int *satisfied)
{
	int		end;

	end = 0;
	if (philo->t_table->max_nb_eat != -1)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->nb_eat == philo->t_table->max_nb_eat && philo->full == 0)
		{
			*satisfied += 1;
			philo->full = 1;
			if (*satisfied == philo->t_table->nb_philo)
			{
				ft_print_status(philo, "All philosophers are satisfied");
				pthread_mutex_lock(&philo->t_table->end_mutex);
				philo->t_table->end_table = 1;
				pthread_mutex_unlock(&philo->t_table->end_mutex);
				end = 1;
			}
		}
		pthread_mutex_unlock(&philo->eat_mutex);
	}
	return (end);
}

void	ft_monitor(t_table *table)
{
	int		end;
	int		satisfied;
	t_list	*philo_lst;

	end = 0;
	satisfied = 0;
	ft_usleep(60);
	while (end == 0)
	{
		philo_lst = table->philo_lst;
		while (philo_lst != NULL && end == 0)
		{
			end = ft_monitor_death((t_philo *)philo_lst->content);
			if (end == 0 && table->max_nb_eat != -1)
				end = ft_monitor_nb_eat((t_philo *)philo_lst->content,
						&satisfied);
			philo_lst = philo_lst->next;
		}
	}
}
