/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:25:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 18:35:09 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	width_c(t_flag *flag, const char * format, int type)
{
	char *	width;
	int 	j;
	int		space;
	int 	count;

	count = 1;
	j = 0;
	width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	space = ft_atoi(width);
	while(space > count++)
		ft_putchar(' ', flag);
}

void	fill_zero_c(t_flag *flag, const char * format, int type)
{
	char *	width;
	int 	j;
	int		space;
	int 	count;
	
	count = 1;
	j = 0;
	width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	space = ft_atoi(width);
	while(space > count++)
		ft_putchar('0', flag);
}

void	minus_c(t_flag *flag, const char * format, int type)
{
	char *	width;
	int 	j;
	int		space;
	int 	count;
	
	count = 1;
	j = 0;
	width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	space = ft_atoi(width);
	while(space > count++)
		ft_putchar(' ', flag);
}

void	print_char(va_list args, t_flag *flag, const char * format, int type)
{
	char	c;

	c =	va_arg(args, unsigned int);
	if (flag->width == 1)
		width_c(flag, format, type);
	if (flag->zero == 1)
		fill_zero_c(flag, format, type);
	ft_putchar(c, flag);
	if (flag->minus == 1)
		minus_c(flag, format, type + 1);
}
