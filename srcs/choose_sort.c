/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:54:15 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/25 02:55:26 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two(t_node **no1)
{
	if ((*no1)->value > (*no1)->next->value)
		swap(no1, "sa");
	else
		return ;
}

void sort_three(t_node **node, int index)
{
	if (index == 2)
		sort_two(node);
	else if (index == 1)
	{
		r_rotate(node, "rra");
		sort_two(node);
	}
	else
	{
		rotate(node, "ra");
		sort_two(node);
	}
}

void choose_sort(t_node **no1, t_node **no2, int argc)
{
	int saved_index;

	(void)no2;
	saved_index = search_bigger(no1);
	if (check_order(no1) == 0)
		return;
	if (argc == 2)
	{
		sort_two(no1);
		check_order(no1);
	}
	else if (argc == 3)
		sort_three(no1, saved_index);
	// else if (argc == 4)
	// 	sort_four(no1, no2, saved_index);
	return;
}