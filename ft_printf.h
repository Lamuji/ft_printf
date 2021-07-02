/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:58:08 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/01 19:28:22 by ramzi            ###   ########.fr       */
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

# define TYPE "%csdiupxX"

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
void	ft_conv(va_list args, t_flag *flag, const char * format, int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int     ft_putnbr_base(unsigned long nbr, char *base);
void	ft_putunbr_fd(long int n, int fd);
int		ft_isdigit(int c);
void	ft_check_flags(va_list args, const char * format, t_flag *flag, int i);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
int     ft_compte(int i);
char	*ft_itoa(int n);
char	ft_width(const char *str, int i, va_list args, t_flag *flag);
void    print_u(va_list args, t_flag *flag, const char * format, int type);
void    print_Xx(va_list args, t_flag *flag, const char * format, int type);
void	print_d_i(va_list args, t_flag *flag, const char * format, int type);
void	print_char(va_list args, t_flag *flag, const char * format, int type);
void    print_str(va_list args, t_flag *flag, const char * format, int type);
void	width(int n, const char * format, int type);

# endif