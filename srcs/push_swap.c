/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/10 03:49:51 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "stdio.h"
#include "stdlib.h"

void	free_nodes(t_node *no)
{
	t_node	*aux;

	aux = no;
	while (aux)
	{
		aux = no->next;
		free(no);
		no = aux;
	}
	no = NULL;
}

void	choose_sort(t_node **no1, t_node **no2, int argc)
{
	if (check_order(no1) == 0)
		return ;
	if (argc == 2)
	{
		sort_two(no1);
		check_order(no1);
	}
	else if (argc == 3)
		sort_three(no1);
	else if (argc == 4)
		sort_four(no1, no2);
	else if (argc == 5)
		sort_five(no1, no2);
	else if (argc > 5)
		more_than_five(no1, no2, argc);
	check_order(no1);
	return ;
}

int	main(int argc, char **argv)
{
	t_node	*no1;
	t_node	*no2;

	no1 = 0;
	no2 = 0;
	check_errors(argc, argv);
	create_list(argc, argv, &no1);
	order_index (argc - 1, argv + 1, &no1);
	choose_sort(&no1, &no2, argc - 1);
	free_nodes(no1);
	free_nodes(no2);
	return (0);
}
