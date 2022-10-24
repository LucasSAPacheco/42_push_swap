/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:15:02 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/24 21:37:10 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}			t_node;

t_node *new_node(int num);
t_node *find_last(t_node *node);
void add_last(t_node **node, t_node *to_add);
void add_front(t_node **node, t_node *to_add);
void push(t_node **no1, t_node **no2, char *str);
void rotate(t_node **no, char *str);
void swap(t_node **no, char *str);
t_node *before_last(t_node *node);
void r_rotate(t_node **no, char *str);
int	ft_atoi(const char *nptr);
void check_errors(int argc, char **argv, t_node **node);
int check_argv(char **argv, int argc);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *str);
size_t	ft_strlen(char const *s);

#endif