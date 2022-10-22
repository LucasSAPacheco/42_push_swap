/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:15:02 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 04:47:38 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}			t_node;

t_node *new_node(int num);
t_node *find_last(t_node *node);
void add_last(t_node **node, t_node *to_add);
void add_front(t_node **node, t_node *to_add);
void push2dot0(t_node **no1, t_node **no2, char *str);
void push(t_node **send, t_node **recep);

#endif