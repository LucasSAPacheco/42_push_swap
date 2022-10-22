/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 04:46:57 by lsantana         ###   ########.fr       */
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



int main(void)
{
	t_node *no1;
	t_node *no2;

	no1 = 0;
	no2 = 0;
	// add_last(&no1, new_node(10));
	// add_last(&no1, new_node(2));
	// add_last(&no1, new_node(155));
	// add_front(&no1, new_node(36));
	// add_front(&no1, new_node(69));
	// add_front(&no1, new_node(100));
	printf("Antes do push\n");
	print_no(no1);
	print_no(no2);
	push2dot0(&no1, &no2, "pb");
	// push2dot0(&no1, &no2);
	printf("Depois do push\n");
	print_no(no1);
	print_no(no2);
	free_nodes(no1);
	free_nodes(no2);
	return (0);
}
