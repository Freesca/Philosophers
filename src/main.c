/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:51:51 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/28 12:24:16 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		ft_error (1, NULL);
	if (ft_check_args(argc, argv) == 0)
		ft_error(2, NULL);
	ft_init_table(&table, argc, argv);
	ft_init_thread(&table);
	ft_free_all(&table);
	return (0);
}
