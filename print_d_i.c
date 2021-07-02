/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:21:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/02 19:16:43 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_d(int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		space;

	j = 0;
	count = 0;
	width = malloc(sizeof(char *) * 1);
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	p = ft_itoa(n);
	space = ft_atoi(width) - ft_strlen(p);
	while (space > count++)
		ft_putchar(' ');
	free(width);
}

void	fill_zero_d(int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		zero;

	j = 0;
	count = 0;
	width = malloc(sizeof(char *) * 1);
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	p = ft_itoa(n);
	zero = ft_atoi(width) - ft_strlen(p);
	while (zero > count++)
		ft_putchar('0');
	free(width);
}

void	minus_d(int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		zero;

	j = 0;
	count = 0;
	width = malloc(sizeof(char *) * 1);
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	p = ft_itoa(n);
	zero = ft_atoi(width) - ft_strlen(p);
	while (zero > count++)
		ft_putchar(' ');
	free(width);
}

void	print_d_i(va_list args, t_flag *flag , const char *format, int type)
{
	int 	n;
	//printf("///%c///", format[type]);
	printf("///%d///", flag->minus);
	n = va_arg(args, int);
	if (flag->width == 1)
		width_d(n, format, type);
	if (flag->zero == 1)
		fill_zero_d(n, format, type);
	ft_putnbr_fd(n, 1);
	if (flag->minus == 1)
		minus_d(n, format, type + 1);
}





