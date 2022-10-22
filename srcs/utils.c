/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 04:47:00 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 06:43:05 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void push(t_node **send, t_node **recep)
// {
// 	t_node *aux;
// 	t_node *temp;
	
// 	aux = new_node((*send)->value);
// 	add_front(recep, aux);
// 	temp = *send;
// 	*send = (*send)->next;
// 	free(temp);
// }

void push2dot0(t_node **no1, t_node **no2, char *str)
{
	t_node *temp;
	(void)str;
	if (*no1 == 0)
		return;
	temp = (*no1)->next;
	(*no1)->next = *no2;
	*no2 = *no1;
	*no1 = temp;
	// printf("%s\n", str);
}

void rotate(t_node **no, char *str)
{
	(void)str;
	t_node *temp;
	
	temp = (*no)->next;
	find_last(*no)->next = *no;
	(*no)->next = NULL;
	*no = temp;
}

void swap(t_node **no, char *str)
{
	(void)str;
	t_node *temp;

	temp = (*no)->next;
	(*no)->next = (*no)->next->next;
	temp->next = (*no);
	(*no) = temp;
}

void r_rotate(t_node **no, char *str)
{
	(void)str;
	t_node *temp;

	temp = find_last(*no);
	before_last(*no)->next = NULL;
	temp->next = *no;
	*no = temp;
}
