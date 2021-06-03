/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/03 19:32:53 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_conv(va_list args, char const *format, int i)
{
    int nbr;
    char car;

	if (format[i] == 'd')
		{
			nbr = va_arg(args, int);
			ft_putnbr_fd(nbr, 1);
		}
    if (format[i] == 'c')
    {
        car = va_arg(args, int);
        ft_putchar_fd(car,1);
    }
		return nbr;
}
