/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:31:55 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/11 18:43:42 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	width_u(t_flag *flag, int n, const char * format, int type)
{
	int     count;
    int     space;
    char *  width;
    int		j;
    char *	p;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	if (n < 0)
		p = ft_itoa(2147483647 + n);
	else
		p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while(space > count++)
		ft_putchar(' ', flag);
}

void	fill_zero_u(t_flag *flag, int n, const char * format, int type)
{
	int     count;
    int     space;
    char *  width;
    int		j;
    char *	p;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	if (n < 0)
		p = ft_itoa(2147483647 + n);
	else
		p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while(space > count++)
		ft_putchar('0', flag);
}

void	minus_u(t_flag *flag, int n, const char * format, int type)
{
	int     count;
    int     space;
    char *  width;
    int		j;
    char *	p;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	if (n < 0)
		p = ft_itoa(2147483647 + n);
	else
		p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while(space > count++)
		ft_putchar(' ', flag);
}

void    print_u(va_list args, t_flag *flag, const char *format, int type)
{
    int     n;

    n = va_arg(args, unsigned int);
	if (flag->width == 1)
		width_u(flag, n, format, type);
	if (flag->zero == 1)
		fill_zero_u(flag, n, format, type);
    ft_putunbr_fd(n, 1, flag);
	if (flag->minus == 1)
		minus_u(flag, n, format, type + 1);
}
