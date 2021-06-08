/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/06 19:00:10 by rfkaier          ###   ########.fr       */
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
	{
		nbr = va_arg(args, int);
		ft_putnbr_fd(nbr, 1);
	}
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
	else if (format[i] == 'x')
	{
		nbr = va_arg(args, unsigned long);
		ft_putnbr_base(nbr,"0123456789abcdef");
	}
	else if (format[i] == 'X')
	{
		nbr = va_arg(args, unsigned long);
		ft_putnbr_base(nbr,"0123456789ABCDEF");
	}
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
	else if (format[i] == 'p')
	{
		str = va_arg(args, unsigned int);
		
		
	}
		return 0;
}
