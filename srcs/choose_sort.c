/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lousin <lousin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:54:15 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/25 00:33:44 by lousin           ###   ########.fr       */
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

void sort_three(t_node **node)
{
	int index;
	
	index = search_bigger(node);
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

void sort_four(t_node **node1, t_node **node2)
{
	int index;

	index = search_lower(node1);
	if (index == 0)
	{
		push(node1, node2, "pb");
		sort_three(node1);
		push(node2, node1, "pa");
	}
	else if (index == 3)
	{
		r_rotate(node1, "rra");
		push(node1, node2, "pb");
		sort_three(node1);
		push(node2, node1, "pa");
	}
	else
	{
		r_rotate(node1, "rra");
		sort_four(node1, node2);
	}
}

void sort_five(t_node **node1, t_node **node2)
{
	int index;
	
	index = search_lower(node1);
	if (index == 0)
	{
		push(node1, node2, "pb");
		sort_four(node1, node2);
		push(node2, node1, "pa");
	}
	else if (index == 4)
	{
		r_rotate(node1, "rra");
		sort_five(node1, node2);
	}
	else if (index > 0 && index < 3)
	{
		rotate(node1, "ra");
		sort_five(node1, node2);
	}
	else
	{
		r_rotate(node1, "rra");
		sort_five(node1, node2);
	}
}

void sort_more(t_node **node1, t_node **node2, int size)
{
	int index;
	t_node *aux;

	aux = (*node2);
	index = search_lower(node1);
	// if (size <= 5)
	// 	sort_five(node1, node2);
	if (index == 0)
	{
		push(node1, node2, "pb");
		if(!check_rev_order(node1))
		{
			sort_more(node1, node2, size);
		}
	}
	else if (index == (size - 1))
	{
		r_rotate(node1, "rra");
		push(node1, node2, "pb");
		sort_more(node1, node2, size);
	}
	else if ((size / index) > 2)
	{
		rotate(node1, "ra");
		sort_more(node1, node2, size);
	}
	else if ((size / index) < 2)
	{
		r_rotate(node1, "rra");
		sort_more(node1, node2, size);
	}
	while (aux)
	{
		push(node2, node1, "pa");
		aux = aux->next;
		push(node2, node1, "pa");
	}
}

void choose_sort(t_node **no1, t_node **no2, int argc)
{
	int size;

	size = find_size(no1);
	if (check_order(no1) == 0)
		return;
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
	else
		sort_more(no1, no2, size);
	check_order(no1);
	return;
}