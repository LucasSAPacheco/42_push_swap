/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:54:15 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/25 01:49:44 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void two_arguments(t_node **no1)
{
	if ((*no1)->value > (*no1)->next->value)
		swap(no1, "sa");
	else
		return ;
}

// void three_arguments(t_node **node, int bigger)
// {
	
// }

void choose_sort(t_node **no1, t_node **no2, int argc)
{
	int buffer;

	buffer = search_bigger(no1);
	ft_printf("%d\n", buffer);
	if (check_order(no1) == 0)
		return;
	(void)no2;
	if (argc == 2)
		two_arguments(no1);
		
	// else if (argc == 3)
	// 	three_arguments(no1, buffer);
	return;
}