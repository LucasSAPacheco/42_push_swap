/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/09 21:28:56 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
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

int main(int argc, char **argv)
{
	t_node *no1;
	t_node *no2;
    
	no1 = 0;
	no2 = 0;
    check_errors(argc, argv);
    create_list(argc, argv, &no1);
    order_index(argc - 1, argv + 1, &no1);
	choose_sort(&no1, &no2, argc - 1);
	free_nodes(no1);
	free_nodes(no2);
	return (0);
}
