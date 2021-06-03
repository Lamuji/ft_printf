/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/03 18:26:18 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;

	va_start(args, format);

	while (format)
	
	{
		if (format[i] == '%')
		{
			i++;
			ft_conv(args, format, i);
		}
		else
		{	
			ft_putchar_fd(i, 1);
			i++;
		}
	}
return 0;
}

