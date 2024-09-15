/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menage_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:22:31 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/01 12:07:00 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*ft_pick_sx_fork(t_philo *philo)
{
	t_list	*fork_lst;
	t_fork	*fork;

	fork_lst = philo->fork_lst;
	while (fork_lst != NULL)
	{
		fork = (t_fork *)(fork_lst->content);
		if (philo->id == 1)
			if (fork->id == philo->t_table->nb_philo)
				return (fork);
		if (fork->id == philo->id - 1)
			return (fork);
		fork_lst = fork_lst->next;
	}
	return (NULL);
}

static t_fork	*ft_pick_dx_fork(t_philo *philo)
{
	t_list	*fork_lst;
	t_fork	*fork;

	fork_lst = philo->fork_lst;
	while (fork_lst != NULL)
	{
		fork = (t_fork *)(fork_lst->content);
		if (fork->id == philo->id)
			return (fork);
		fork_lst = fork_lst->next;
	}
	return (NULL);
}

void	ft_leave_forks(t_philo *philo)
{
	t_fork	*fork_low;
	t_fork	*fork_high;

	if (philo->id == 1)
	{
		fork_low = ft_pick_sx_fork(philo);
		fork_high = ft_pick_dx_fork(philo);
	}
	else
	{
		fork_low = ft_pick_dx_fork(philo);
		fork_high = ft_pick_sx_fork(philo);
	}
	pthread_mutex_unlock(&fork_high->fork_mutex);
	pthread_mutex_unlock(&fork_low->fork_mutex);
}

void	ft_take_forks(t_philo *philo)
{
	t_fork	*fork_low;
	t_fork	*fork_high;

	if (philo->id == 1)
	{
		fork_low = ft_pick_sx_fork(philo);
		fork_high = ft_pick_dx_fork(philo);
	}
	else
	{
		fork_low = ft_pick_dx_fork(philo);
		fork_high = ft_pick_sx_fork(philo);
	}
	pthread_mutex_lock(&fork_low->fork_mutex);
	ft_print_status(philo, "has taken a fork");
	if (philo->t_table->nb_philo == 1)
	{
		pthread_mutex_unlock(&fork_low->fork_mutex);
		return ;
	}
	pthread_mutex_lock(&fork_high->fork_mutex);
	ft_print_status(philo, "has taken a fork");
}
