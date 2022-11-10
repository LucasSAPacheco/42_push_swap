/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 03:43:30 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/10 03:32:05 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_front(t_node **node, t_node *to_add)
{
	if (to_add == 0)
		return ;
	if (*node == 0)
	{
		*node = to_add;
		return ;
	}
	to_add->next = *node;
	*node = to_add;
}
