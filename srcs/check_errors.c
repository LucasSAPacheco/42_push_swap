/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:56:31 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/31 17:59:55 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i])
		return (-1);
	else
		return (0);
}

int check_argv(char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (check_digit(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

void check_errors(int argc, char **argv, t_node **node)
{
	if (argc == 1)
		exit (0);
	if (check_argv(argv, argc) == -1)
	{
		ft_printf("Error\n");
		exit (0);
	}
	if (argc >= 2)
	{
		while (argc > 1)
		{
			add_front(node, new_node(ft_atoi(argv[argc - 1])));
			argc--;
		}
		return ;
	}
}
