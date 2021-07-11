/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:33:35 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 19:24:41 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_p(t_flag *flag, char *str, const char * format, int type)
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

void	fill_zero_p(t_flag *flag, char *str, const char * format, int type)
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
		ft_putchar('0', flag);
}

void	minus_p(t_flag *flag, char *str, const char * format, int type)
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

char 	*conv_str(unsigned long long int n, char *str)
{
	char	*pre_str;

	pre_str = "0x";
	str = ft_itoa_base(n, "0123456789abcdef");
	str = ft_strjoin(pre_str, str);
	if (ft_strcmp(str, "0x") == 0)
		str = ft_strcat(str, "0");
	return (str);
}

void	print_p(va_list args, t_flag *flag, const char * format, int type)
{
	unsigned long long n;
	char	*str;

	str = NULL;
	n = va_arg(args, unsigned long long);
	str = conv_str(n, str);
	if (flag->width == 1)
		width_p(flag, str, format, type);
	if (flag->zero == 1)
		fill_zero_p(flag, str, format, type);
	ft_putstr(str, flag);
	if (flag->minus == 1)
		minus_p(flag, str, format, type + 1);
	free(str);
}
