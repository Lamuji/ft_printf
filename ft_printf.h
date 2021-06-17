/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:58:08 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/17 21:14:20 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

# define TYPE "csdiupxX"

typedef	struct 	s_flag
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	char	type;
	int		nbr_base;
	int		sign;
}				t_flag;

int		ft_printf(const char *format, ...);
void		ft_conv(va_list args, t_flag *flag, const char * format, int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int     ft_putnbr_base(unsigned long nbr, char *base);
void	ft_putunbr_fd(long int n, int fd);
int		case_d(int nbr, va_list args);
int 	case_xX(int nbr, int i, va_list args);
int		ft_isdigit(int c);
int		print_char(va_list args, t_flag *flag);
void	ft_check_flags(va_list args, const char * format, t_flag *flag, int i);
void	print_d_i(va_list args, t_flag *flag, const char * format, int i);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
int     ft_compte(int i);
char	*ft_itoa(int n);
char	ft_width(const char *str, int i, va_list args, t_flag *flag);



# endif