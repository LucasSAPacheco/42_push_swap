/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:09:25 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/27 13:11:52 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int search_lower(t_node **node)
{
	t_node *aux;
	int keep;
	int index;
	int lower;

	aux = (*node);
	index = 0;
	lower = 0;
	keep = (*node)->value;
	while (aux)
	{
		if (aux->value < keep)
		{
			keep = aux->value;
			lower = index;
		}
		aux = aux->next;
		index++;
	}
	return (lower);
}

int check_rev_order(t_node **node)
{
	t_node *aux;
	
	aux = *node;
	while (aux)
	{
		if (aux->next != NULL && aux->value < aux->next->value)
			return (-1);
		aux = aux->next;
	}
	ft_printf("The rev order is ok!\n");
	return (0);
}

int find_size(t_node **node)
{
	t_node *aux;
	int index;

	aux = (*node);
	index = 0;
	while (aux)
	{
		aux = aux->next;
		index++;
	}
	return (index);
}

t_node *find_middle(t_node *head)
{
	t_node *slow;
	t_node *fast;

	slow = head;
	fast = head->next;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return(slow);
}
