/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 02:42:37 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "stdlib.h"

void free_nodes(t_node *no)
{
	t_node *aux;

	aux = no;
	while(aux)
	{
		aux = no->next;
		free(no);
		no = aux;
	}
	no = NULL;
}

void print_no(t_node *no)
{
	t_node *aux;

	aux = no;
	while(aux)
	{
		printf("Valor do nó: %d\n", aux->value);
		aux = aux->next;
	}
	printf("\n-----------------------\n");
}

void push(t_node **send, t_node **recep)
{
	t_node *aux;
	t_node *temp;
	
	aux = new_list(find_last(*send)->value);
	add_last(recep, aux);
	temp = *send;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next);
	temp->next = 0;
}

int main(void)
{
	t_node *no1;
	t_node *no2;

	no1 = 0;
	no2 = 0;
	add_last(&no1, new_list(10));
	add_last(&no1, new_list(2));
	add_last(&no1, new_list(155));

	push(&no1, &no2);
	push(&no1, &no2);
	print_no(no1);
	print_no(no2);
	free_nodes(no1);
	free_nodes(no2);
	return (0);
}
