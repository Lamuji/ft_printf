/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:24:24 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/02 20:14:50 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	width_Xx(int n, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

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
	while(space > count++)
		ft_putchar(' ');
    free(width);
}

void	fill_zero_Xx(int n, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

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
	while(space > count++)
		ft_putchar('0');
    free(width);
}

void	minus_Xx(int n, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

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
	while(space > count++)
		ft_putchar(' ');
    free(width);
}

void    print_Xx(va_list args, t_flag *flag, const char * format, int type)
{
    unsigned long long	n;
	char			*str;
	
	str = NULL;
	n = va_arg(args, unsigned long);
	if (flag->width == 1)
		width_Xx(n, format, type);
	if (flag->zero == 1)
		fill_zero_Xx(n, format, type);
    if (format[type] == 'X')
		str = ft_itoa_base(n, "0123456789ABCDEF");
    else
        str = ft_itoa_base(n, "0123456789abcdef");
	ft_putstr(str);
	if (flag->minus == 1)
		minus_Xx(n, format, type + 1);
}