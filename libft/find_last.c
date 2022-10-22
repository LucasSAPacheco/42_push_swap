/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:59:15 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 02:22:34 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *find_last(t_node *node)
{
	if (node == 0)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}
