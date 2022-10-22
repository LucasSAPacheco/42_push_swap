/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:02:16 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 02:12:55 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void add_last(t_node **node, t_node *to_add)
{
	if (to_add == 0)
		return;
	if (*node == 0)
		*node = to_add;
	else
		find_last(*node)->next = to_add;
}
