/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/06 18:35:24 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, format);

	while (format[i])
	{
		if (!format)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			ft_conv(args, format, i);
			i++;
		}
		ft_putchar(format[i]);
		i++;
	}
return 0;
}

