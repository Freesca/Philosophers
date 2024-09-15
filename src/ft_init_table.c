/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:19:13 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/10 18:39:25 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_list	*ft_init_fork_lst(t_table *table)
{
	int		i;
	t_fork	*fork;
	t_list	*fork_lst;

	i = 0;
	fork_lst = NULL;
	while (i < table->nb_philo)
	{
		fork = malloc(sizeof(t_fork));
		if (fork == NULL)
			ft_error(3, table);
		fork->id = i + 1;
		fork->used = 0;
		pthread_mutex_init(&fork->used_mutex, NULL);
		pthread_mutex_init(&fork->fork_mutex, NULL);
		ft_lstadd_back(&fork_lst, ft_lstnew(fork));
		if (fork_lst == NULL)
			ft_error(3, table);
		i++;
	}
	return (fork_lst);
}

static void	ft_init_philo_lst(t_table *table)
{
	int		i;
	t_philo	*philo;
	t_list	*fork_lst;

	i = 0;
	table->philo_lst = NULL;
	fork_lst = ft_init_fork_lst(table);
	while (i < table->nb_philo)
	{
		philo = malloc(sizeof(t_philo));
		if (philo == NULL)
			ft_error(3, table);
		*philo = (t_philo){0};
		philo->id = i + 1;
		philo->fork_lst = fork_lst;
		philo->t_table = table;
		pthread_mutex_init(&philo->eat_mutex, NULL);
		pthread_mutex_init(&philo->safe_mutex, NULL);
		ft_lstadd_back(&table->philo_lst, ft_lstnew(philo));
		if (table->philo_lst == NULL)
			ft_error(3, table);
		i++;
	}
}

t_table	*ft_init_table(t_table *table, int argc, char **argv)
{
	*table = (t_table){0};
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->max_nb_eat = ft_atoi(argv[5]);
	else
		table->max_nb_eat = -1;
	if (table->nb_philo <= 0 || table->nb_philo > 200 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0
		|| table->max_nb_eat == 0)
		ft_error(2, table);
	table->end_table = 0;
	pthread_mutex_init(&table->end_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	ft_init_philo_lst(table);
	return (table);
}
