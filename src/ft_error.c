/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:39:55 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/28 12:13:46 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_fork_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp != NULL)
	{
		next = tmp->next;
		pthread_mutex_destroy(&((t_fork *)(tmp->content))->fork_mutex);
		pthread_mutex_destroy(&((t_fork *)(tmp->content))->used_mutex);
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

static void	ft_philo_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	if (((t_philo *)(tmp->content))->fork_lst != NULL)
		ft_fork_lstclear(&((t_philo *)(tmp->content))->fork_lst);
	while (tmp != NULL)
	{
		next = tmp->next;
		pthread_mutex_destroy(&((t_philo *)(tmp->content))->eat_mutex);
		pthread_mutex_destroy(&((t_philo *)(tmp->content))->safe_mutex);
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	ft_free_all(t_table *table)
{
	t_list	*philo_lst;

	philo_lst = table->philo_lst;
	if (philo_lst != NULL)
		ft_philo_lstclear(&philo_lst);
	pthread_mutex_destroy(&table->end_mutex);
	pthread_mutex_destroy(&table->print_mutex);
}

void	ft_error(int error, t_table *table)
{
	if (error == 1)
		ft_printf(2, "Error: wrong number of arguments\n");
	if (error == 2)
		ft_printf(2, "Error: wrong arguments\n");
	if (error == 3)
		ft_printf(2, "Error: table initialization failed\n");
	if (error == 4)
		ft_printf(2, "Error: thread creation failed\n");
	if (error == 5)
		ft_printf(2, "Error: thread join failed\n");
	if (table != NULL)
		ft_free_all(table);
	exit(1);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_strncmp(argv[i], "goku", 4) == 0)
			{
				ft_printf(2, "You are not Goku\n");
				return (0);
			}
			if (ft_isdigit(argv[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
