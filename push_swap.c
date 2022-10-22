/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 05:18:18 by lsantana         ###   ########.fr       */
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

void    print_stacks(t_node *a, t_node *b)
{
    int    lst_size_a = 0;
    int lst_size_b = 0;
    int max;
    t_node    *aux_a;
    t_node    *aux_b;

    aux_a = a;
    aux_b = b;
    while (aux_a)
    {
        lst_size_a++;
        aux_a = aux_a->next;
    }
    while (aux_b)
    {
        lst_size_b++;
        aux_b = aux_b->next;
    }
    max = lst_size_a > lst_size_b ? lst_size_a : lst_size_b;
    while (max)
    {
        if (a && max <= lst_size_a)
		{
            printf("\t%3d\t", a->value);
			a = a->next;
		}
        else
            printf("\t \t");
        if (b && max <= lst_size_b)
		{
            printf("\t%3d\n", b->value);
			b = b->next;
		}
        else
            printf("\n");
		max--;
    }
	printf("\t___\t\t___\n");
    printf("\t A\t\t B\n");
}

int main(void)
{
	t_node *no1;
	t_node *no2;

	no1 = 0;
	no2 = 0;
	add_last(&no1, new_node(10));
	add_last(&no1, new_node(2));
	add_last(&no1, new_node(155));
	add_front(&no1, new_node(36));
	add_front(&no1, new_node(69));
	add_front(&no1, new_node(100));
	push2dot0(&no1, &no2, "pb");
	push2dot0(&no1, &no2, "pb");
	push2dot0(&no1, &no2, "pb");
	push2dot0(&no1, &no2, "pb");
	// rotate(&no2, "");
	// rotate(&no1, "");
	// rotate(&no1, "");
	print_stacks(no1, no2);
	free_nodes(no1);
	free_nodes(no2);
	return (0);
}
