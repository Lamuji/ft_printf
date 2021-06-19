/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/19 01:24:14 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_conv(va_list args, t_flag *flag, const char * format, int i)
{
    int percent;
    char c;
	char type;

	percent = i - 1;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '%')
		ft_putchar(format[i]);
	else if (format[i] == 'c')
		print_char(args, flag);
	else if (format[i] == 'd' || format[i] == 'i')
	{
		i = percent + 1;
		print_d_i(args, flag, format, i);
	}

}

