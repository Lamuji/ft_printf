/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:58:08 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/03 20:25:30 by rfkaier          ###   ########.fr       */
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
//#include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_conv(va_list args ,char const *format, int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *str);

# endif