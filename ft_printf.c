/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/15 17:11:28 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
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
	if (!flag)
		return NULL;
	va_start(args, format);
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar(format[i++]);
		while (format[i] == '%')
		{
			ft_init_flags(flag);
			if (format[i++] != TYPE && format[i] != '\0')
				ft_check_flags(args, format, flag, i)
			ft_conv(args, t_flag);
		}
	}
	return 0;
}

