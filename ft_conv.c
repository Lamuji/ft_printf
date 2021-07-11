/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/11 19:18:43 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conv(va_list args, t_flag *flag, const char * format, int i)
{
    int type;

	type = i;

	while (!(ft_strchr(TYPE, format[i])))
		i++;
	if (format[i] == '%')
		ft_putchar('%', flag);
	else if (format[i] == 'd' || format[i] == 'i')
		print_d_i(args, flag, format, type);
	else if (format[i] == 'u')
		print_u(args, flag, format, type);
	else if (format[i] == 'x' || format[i] == 'X')
		print_Xx(args, flag, format, type);
	else if (format[i] == 'c')
		print_char(args, flag, format, type);
	else if (format[i] == 's')
		print_str(args, flag, format, type);
	else if (format[i] == 'p')
		print_p(args, flag, format, type);
}
