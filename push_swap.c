/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/21 06:04:06 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "stdlib.h"

t_list *make_node(int value)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = value;
	new_node->next = NULL;
	return new_node;
}

t_list *insert_to_head(t_list **head, t_list *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

int main(void)
{
	t_list *head1;
	t_list *temp;
	
	int i = 0;
	head1 = NULL;
	while (i++ < 10)
	{
		temp = make_node(i);
		ft_lstadd_back(&head1, temp);
	}
	ft_lstadd_back(&head1, temp);
	// print_list(head1);
	printf("Content: %d\n", temp->content);
	printf("Addess: %p\n", temp->next);
	return (0);
}


