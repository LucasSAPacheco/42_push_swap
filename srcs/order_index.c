/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:55 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/10 03:48:00 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *array, int argc)
{
	int	i;

	while (argc)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (array[i] > array[i + 1])
			{
				array[i] = array[i] ^ array[i + 1];
				array[i + 1] = array[i] ^ array[i + 1];
				array[i] = array[i] ^ array[i + 1];
			}
			i++;
		}
		argc--;
	}
}

int	*creating_index(int *order, int *desorder, int *map, int argc)
{
	int	*desorder_map;
	int	i;
	int	j;

	desorder_map = malloc(sizeof(int) * argc);
	j = 0;
	while (j < argc)
	{
		i = 0;
		while (i < argc)
		{
			if (desorder[j] == order[i])
				desorder_map[j] = map[i];
			i++;
		}
		j++;
	}
	return (desorder_map);
}

void	put_index(int *index, t_node **node)
{
	t_node	*aux;
	int		i;

	aux = (*node);
	i = 0;
	while (aux)
	{
		aux->index = index[i];
		aux = aux->next;
		i++;
	}
}

void	order_index(int argc, char **argv, t_node **node)
{
	int	*copy;
	int	*aux;
	int	*map;
	int	*desorder_array;
	int	i;

	aux = malloc(sizeof(int) * argc);
	copy = malloc(sizeof(int) * argc);
	map = malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		aux[i] = ft_atoi(argv[i]);
		copy[i] = aux[i];
		map[i] = i;
		i++;
	}
	bubble_sort(aux, argc);
	desorder_array = creating_index(aux, copy, map, argc);
	put_index(desorder_array, node);
	free(copy);
	free(aux);
	free(map);
	free(desorder_array);
}
