/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/01 20:57:42 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_conv(va_list args, t_flag *flag, const char * format, int i)
{
    int type;
    char c;

	type = i;
	//printf("///%c///", format[i]);
	while (!(ft_strchr(TYPE, format[i])))
		i++;
	//printf("///%c///", format[type]);
	if (format[i] == '%')
		ft_putchar('%');
	else if (format[i] == 'c')
		print_char(args, flag, format, type);
	else if (format[i] == 'd' || format[i] == 'i')
		print_d_i(args, flag, format, type);
	else if (format[i] == 'u')
		print_u(args, flag, format, type);
	else if (format[i] == 'x' || format[i] == 'X')
		print_Xx(args, flag, format, type);
	else if (format[i] == 's')
		print_str(args, flag, format, type);
}

