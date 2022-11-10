/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:54:15 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/10 03:50:00 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_node **no1)
{
	if ((*no1)->value > (*no1)->next->value)
		swap(no1, "sa");
	else
		return ;
}

void	sort_three(t_node **node)
{
	int	index;

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

void	sort_four(t_node **node1, t_node **node2)
{
	int	index;

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

void	sort_five(t_node **node1, t_node **node2)
{
	int	index;

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

void	more_than_five(t_node **no1, t_node **no2, int size)
{
	int	size_bits;
	int	i;
	int	j;

	size_bits = 0;
	i = 0;
	while ((size >> size_bits))
		size_bits++;
	while (i < size_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*no1)->index >> i) & 1) == 1)
				rotate(no1, "ra");
			else
				push(no1, no2, "pb");
			j++;
		}
		while ((*no2))
			push(no2, no1, "pa");
		i++;
	}
}
