/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:58:08 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 18:19:58 by rfkaier          ###   ########.fr       */
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
	int		count;
}				t_flag;

int		ft_printf(const char *format, ...);
void	ft_conv(va_list args, t_flag *flag, const char * format, int i);
void	ft_putnbr(int n,t_flag *flag);
void	ft_putchar(char c, t_flag *flag);
void	ft_putstr(char *str, t_flag *flag);
void	ft_putunbr_fd(long int n, int fd, t_flag *flag);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
void	ft_check_flags(const char * format, t_flag *flag, int i);
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
void	print_p(va_list args, t_flag *flag, const char * format, int type);
void	width_d(t_flag *flag, int n, const char * format, int type);
void 	width_u(t_flag *flag, int n, const char * format, int type);
void	width_c(t_flag *flag, const char * format, int type);
void	width_Xx(t_flag *flag, int n, const char * format, int type);
void	width_p(t_flag *flag, char *str, const char * format, int type);
void	width_str(t_flag *flag, char *str, const char * format, int type);
void	fill_zero_d(t_flag *flag, int n, const char * format, int type);
void	fill_zero_u(t_flag *flag, int n, const char * format, int type);
void	fill_zero_Xx(t_flag *flag, int n, const char * format, int type);
void	fill_zero_c(t_flag *flag, const char * format, int type);
void	fill_zero_p(t_flag *flag, char *str, const char * format, int type);
void	fill_zero_str(t_flag *flag, char *str, const char * format, int type);
void	minus_d(t_flag *flag, int n, const char * format, int type);
void	minus_u(t_flag *flag, int n, const char * format, int type);
void	minus_Xx(t_flag *flag, int n, const char * format, int type);
void	minus_c(t_flag *flag, const char * format, int type);
void	minus_p(t_flag *flag, char *str, const char * format, int type);
void	minus_str(t_flag *flag, char *str, const char * format, int type);
char	*ft_itoa_base(unsigned long long int nbr, char *base);
char	*ft_itoa_base_maj(unsigned long long int nbr, char *base);

# endif