/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:25:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/25 17:14:28 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list args, t_flag *flags, char * format, int i)
{
	char	c;
	char *	p;
	char *	width;

	
	c =	va_arg(args, int);
		if (flag->width == 1)
	{
		while (ft_isdigit(format[i]))
		{
			width[j] = format[i];
			i++;
			j++;
		}
		p = ft_itoa(n);
		space = ft_atoi(width) - ft_strlen(p);
		while(space > count)
		{
			ft_putchar(' ');
			count++;
		}
	}
	/*if (flag.zero == 1)
		{
			
			printf("fahsfla fsa %c", 'k');
		}*/
	
	ft_putchar(c);
	return 0;
}
