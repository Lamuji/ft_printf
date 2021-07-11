/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:21:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 18:35:53 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_d(t_flag *flag, int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		space;

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
	while (space > count++)
		ft_putchar(' ', flag);
}

void	fill_zero_d(t_flag *flag, int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		zero;

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
	zero = ft_atoi(width) - ft_strlen(p);
	while (zero > count++)
		ft_putchar('0', flag);
}

void	minus_d(t_flag *flag, int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		zero;

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
	zero = ft_atoi(width) - ft_strlen(p);
	while (zero > count++)
		ft_putchar(' ', flag);
}

void	print_d_i(va_list args, t_flag *flag , const char *format, int type)
{
	int 	n;
	n = va_arg(args, int);
	if (flag->width == 1)
		width_d(flag, n, format, type);
	if (flag->zero == 1)
		fill_zero_d(flag, n, format, type);
	ft_putnbr(n, flag);
	if (flag->minus == 1)
		minus_d(flag, n, format, type + 1);
}





