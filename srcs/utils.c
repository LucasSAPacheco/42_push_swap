/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 04:47:00 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/25 02:27:42 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_node **no1, t_node **no2, char *str)
{
	t_node *temp;

	if (*no1 == 0)
		return;
	temp = (*no1)->next;
	(*no1)->next = *no2;
	*no2 = *no1;
	*no1 = temp;
	ft_printf("%s\n", str);
}

void rotate(t_node **no, char *str)
{
	t_node *temp;
	
	temp = (*no)->next;
	find_last(*no)->next = *no;
	(*no)->next = NULL;
	*no = temp;
	ft_printf("%s\n", str);
}

void swap(t_node **no, char *str)
{
	t_node *temp;

	temp = (*no)->next;
	(*no)->next = (*no)->next->next;
	temp->next = (*no);
	(*no) = temp;
	ft_printf("%s\n", str);
}

void r_rotate(t_node **no, char *str)
{
	t_node *temp;

	temp = find_last(*no);
	before_last(*no)->next = NULL;
	temp->next = *no;
	*no = temp;
	ft_printf("%s\n", str);
}

int search_bigger(t_node **node)
{
	t_node *aux;
	int keep;
	int index;
	int bigger;

	aux = (*node);
	index = 0;
	bigger = 0;
	keep = (*node)->value;
	while (aux)
	{
		if (aux->value > keep)
		{
			keep = aux->value;
			bigger = index;
		}
		aux = aux->next;
		index++;
	}
	return (bigger);
}

int check_order(t_node **node)
{
	t_node *aux;
	
	aux = *node;
	while (aux)
	{
		if (aux->next != NULL && aux->value > aux->next->value)
			return (-1);
		aux = aux->next;
	}
	ft_printf("The order is ok!\n");
	return (0);
}
