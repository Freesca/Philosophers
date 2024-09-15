/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:00:20 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/01 12:06:55 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_thread(t_table *table)
{
	t_list		*philo_lst;

	philo_lst = table->philo_lst;
	while (philo_lst != NULL)
	{
		if ((pthread_create(&(((t_philo *)(philo_lst->content))->thread),
				NULL, &ft_philo_routine, philo_lst)) != 0)
			ft_error(4, table);
		philo_lst = philo_lst->next;
	}
	ft_monitor(table);
	philo_lst = table->philo_lst;
	while (philo_lst != NULL)
	{
		if ((pthread_join((((t_philo *)(philo_lst->content))->thread), NULL))
			!= 0)
			ft_error(5, table);
		philo_lst = philo_lst->next;
	}
}
