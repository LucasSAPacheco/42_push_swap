/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:56:31 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/09 21:17:52 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_digit(char *str)
{
	int i;

	i = 0;
	
	if (ft_strlen(str) == 1 && (str[i] == '-' || str[i] == '+'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
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

int check_size_arg(char **argv)
{
	unsigned int keep;
	int neg;
	int i;
	int j;

	i = 1;
	j = 0;
	neg = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (ft_strlen(argv[i]) >= 10)
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (argv[i][j] == '-')
					neg = 1;
				j++;
			}
			keep = (unsigned int)ft_atoi(&argv[i][j]);
			if (((keep > INT_W_SIG) && neg) || (keep > MAX && !neg))
				return (-1);
		}
		i++;
	}
	return (0);
}

int check_repeated_number(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = i;
		while (str[j + 1])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j + 1]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void check_errors(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	if (check_argv(argv, argc) == -1)
	{
		ft_printf("Error\n");
		exit (0);
	}
	if (check_size_arg(argv) == -1)
	{
		ft_printf("Error\n");
		exit (0);
	}
	if (check_repeated_number(argv) == -1)
	{
		ft_printf("Error\n");
		exit (0);
	}
}
