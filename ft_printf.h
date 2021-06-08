/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:58:08 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/06 16:52:09 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

/*typedef	struct 	s_printf
{
    
}				t_printf;*/

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_conv(va_list args ,char const *format, int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int     ft_putnbr_base(unsigned long nbr, char *base);
void	ft_putunbr_fd(long int n, int fd);

# endif