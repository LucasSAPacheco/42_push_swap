/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:16:40 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/24 21:39:46 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../push_swap.h"

# define UP_HEX "0123456789ABCDEF"
# define LOW_HEX "0123456789abcdef"

int		ft_printf(const char *str, ...);
void	picked_char(int c, int *count);
void	picked_str(char *str, int *count);
void	picked_ito_up_hex(unsigned int n, int *count);
void	picked_ito_low_hex(unsigned int n, int *count);
void	picked_i_or_d(int n, int *count);
void	picked_u(unsigned int n, int *count);
void	picked_pointer(void *c, int *count);

#endif