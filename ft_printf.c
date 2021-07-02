/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/02 16:05:54 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//char *		handle_percent



void	ft_init_flags(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = 0;
	flag->type = 0;
	flag->nbr_base = 10;
	flag->sign = 1;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		*flag;
	int			i;

	i = 0;
	flag = malloc(sizeof(t_flag) * 1);
	va_start(args, format);
	if (!flag)
		return -1;
	while (format[i] != '\0' )
	{
		if (format[i] == '%')
		{
			ft_init_flags(flag);
			if (!(ft_strchr(TYPE,format[++i])))
				ft_check_flags(format, flag, i);
			ft_conv(args, flag, format, i);
			//printf("///%c///", format[i]);
			while (!(ft_strchr(TYPE,format[i])))
				i++;
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return i;
}