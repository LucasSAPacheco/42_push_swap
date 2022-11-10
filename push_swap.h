/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:15:02 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/10 03:59:08 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./printf/ft_printf.h"
# define PLUS '+'
# define MINUS '-'
# define MIN -2147483648
# define INT_W_SIG 2147483648
# define MAX 2147483647

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}			t_node;

// Libft Functions
size_t			ft_strlen(char const *s);
void			ft_putstr_fd(char *s, int fd);
char			*ft_itoa(int n);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *nptr);

// Manipulating LinkedList
t_node			*find_last(t_node *node);
t_node			*before_last(t_node *node);
void			push(t_node **no1, t_node **no2, char *str);
void			r_rotate(t_node **no, char *str);
void			rotate(t_node **no, char *str);
void			swap(t_node **no, char *str);

// Creating LinkedList
t_node			*new_node(int num);
void			add_front(t_node **node, t_node *to_add);
void			add_last(t_node **node, t_node *to_add);

// Errors Functions
void			check_errors(int argc, char **argv);
int				check_argv(char **argv, int argc);

// Sort Functions
void			choose_sort(t_node **no1, t_node **no2, int argc);
void			sort_five(t_node **node1, t_node **node2);
void			sort_four(t_node **node1, t_node **node2);
void			sort_three(t_node **node);
void			sort_two(t_node **no1);
int				check_order(t_node **node);
int				search_bigger(t_node **node);
int				search_lower(t_node **node);
int				find_size(t_node **node);
int				check_rev_order(t_node **node);
void			create_list(int argc, char **argv, t_node **node);
void			order_index(int argc, char **argv, t_node **node);
void			more_than_five(t_node **no1, t_node **no2, int size);
int				check_size_arg(char **argv);

#endif