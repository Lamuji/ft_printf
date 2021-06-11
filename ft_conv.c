/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/11 16:50:50 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_conv(va_list args, char const *format, int i)
{
    int nbr;
    char c;
	char *str;

	if (format[i] == 'd' || format[i] == 'i')
		return case_d(nbr, args);
    else if (format[i] == 'c')
    {
        c = va_arg(args, int);
        ft_putchar(c);
    }
	else if (format[i] == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(str);
	}
	else if (format[i] == 'x' || format[i] == 'X')
		return case_xX(nbr, i, args);
	else if (format[i] == 'u')
	{
		nbr = va_arg(args, unsigned long);
		ft_putunbr_fd(nbr, 1);
	}
	else if (format[i] == '%')
	{
		c = va_arg(args, int);
		ft_putchar(format[i]);
	}
	/*else if (format[i] == 'p')
	{
		str = va_arg(args, unsigned int);
	}*/ 
		return 0;
}
