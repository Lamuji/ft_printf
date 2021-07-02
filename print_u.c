/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:31:55 by ramzi             #+#    #+#             */
/*   Updated: 2021/07/01 21:06:50 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_u(va_list args, t_flag *flag, const char *format, int type)
{
    int     n;
    int     count;
    int     space;
    char *  width;
    int     j;
    char *    p;

    n = va_arg(args, unsigned int);
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
			space--;
		}
        free(width);
	}
    ft_putunbr_fd(n, 1);
}