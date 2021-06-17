/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/17 21:22:37 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_conv(va_list args, t_flag *flag, const char * format, int i)
{
    int nbr;
    char c;
	
	if(flag->width == 1)
	{
		ft_width(format, i, args, flag);
		if (format[i] == '%')
			ft_putchar(format[i]);
		else if (format[i] == 'c')
			print_char(args, flag);
		else if (format[i] == 'd' || format[i] == 'i')
			print_d_i(args, flag, format, i);
	}

}
