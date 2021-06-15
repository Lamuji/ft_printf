/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:58:08 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/15 17:08:12 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

# define TYPE "csdiupxX"

typedef	struct 	s_flag
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		type;
	int		nbr_base;
	int		sign;
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_conv(va_list args ,char const *format, int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int     ft_putnbr_base(unsigned long nbr, char *base);
void	ft_putunbr_fd(long int n, int fd);
int		case_d(int nbr, va_list args);
int 	case_xX(int nbr, int i, va_list args);
int		ft_isdigit(int c);

# endif