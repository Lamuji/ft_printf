/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:16:12 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/11 18:43:00 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_str(t_flag *flag, char *str, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	space = ft_atoi(width) - ft_strlen(str);
	while(space > count++)
		ft_putchar(' ', flag);
}

void	fill_zero_str(t_flag *flag, char *str, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	space = ft_atoi(width) - ft_strlen(str);
	while(space > count++)
		ft_putchar('0', flag);
}

void	minus_str(t_flag *flag, char *str, const char * format, int type)
{
	int     j;
    char *  width;
    int     space;
    int     count;

    j = 0;
    count = 0;
    width = NULL;
	while (ft_isdigit(format[type]))
	{
		width[j] = format[type];
		type++;
		j++;
	}
	space = ft_atoi(width) - ft_strlen(str);
	while (space > count++)
		ft_putchar(' ', flag);
}

void    print_str(va_list args, t_flag * flag, const char * format, int type)
{
    char *  str;

    str = va_arg(args, char *);
    if (flag->width == 1)
        width_str(flag, str, format, type);
	if (flag->zero == 1)
		fill_zero_str(flag, str, format, type);
    ft_putstr(str, flag);
	if(flag->minus == 1)
		minus_str(flag, str, format, type + 1);
}