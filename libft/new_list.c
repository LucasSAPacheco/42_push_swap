/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:56:14 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/22 02:13:36 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *new_list(int num)
{
	t_node *new;
	
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = num;
	new->next = 0;
	return (new);
}
