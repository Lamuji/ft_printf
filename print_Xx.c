/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:24:24 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/11 19:25:48 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_Xx(t_flag *flag, int n, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while(space > count++)
		ft_putchar(' ', flag);
}

void	fill_zero_Xx(t_flag *flag, int n, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while(space > count++)
		ft_putchar('0', flag);
}

void	minus_Xx(t_flag *flag, int n, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while(space > count++)
		ft_putchar(' ', flag);
}

void    print_Xx(va_list args, t_flag *flag, const char * format, int type)
{
    unsigned long long	n;
	char				*str;
	int					letter;
	
	letter = type;
	str = NULL;
	n = va_arg(args, unsigned long);
	if (flag->width == 1)
		width_Xx(flag , n, format, type);
	if (flag->zero == 1)
		fill_zero_Xx(flag, n, format, type);
	while (!(ft_isalpha(format[letter])))
		letter++;
	if (format[letter] == 'x')
		str = ft_itoa_base(n, "0123456789abcdef");
	else if (format[letter] == 'X')
		str = ft_itoa_base_maj(n, "0123456789ABCDEF");
	ft_putstr(str, flag);
	if (flag->minus == 1)
		minus_Xx(flag, n, format, type + 1);
}
