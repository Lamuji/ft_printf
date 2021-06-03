/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/03 20:32:05 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv(va_list args, char const *format, int i)
{
    int nbr;
    char c;
	char *str;

	if (format[i] == 'd')
	{
		nbr = va_arg(args, int);
		ft_putnbr_fd(nbr, 1);
	}
    if (format[i] == 'c')
    {
        c = va_arg(args, int);
        ft_putchar_fd(c, 1);
    }
	if (format[i] == 's')
	{
		str = va_arg(args, int);
		ft_putstr(str);
	}
		return nbr;
}
