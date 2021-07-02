/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:24:24 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/29 20:38:39 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_Xx(va_list args, t_flag *flag, const char * format, int type)
{
    unsigned long    n;
    int     j;
    char *  width;
    int     space;
    int     count;
    char *   p;

    n = va_arg(args, unsigned long);
	if (flag->width == 1)
	{
        j = 0;
        count = 0;
        width = malloc(sizeof(char *) * 1);
		while (ft_isdigit(format[type]))
		{
			width[j] = format[type];
			type++;
			j++;
		}
		p = ft_itoa(n);
		space = ft_atoi(width) - ft_strlen(p);
		while(space > count)
		{
			ft_putchar(' ');
			count++;
		}
        free(width);
	}
    if (format[type] == 'x')
        ft_putnbr_base(n, "0123456789abcdef");
    else
        ft_putnbr_base(n, "0123456789ABCDEF");
}