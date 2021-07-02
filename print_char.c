/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:25:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/01 19:21:46 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args, t_flag *flag, const char * format, int type)
{
	char	c;
	char *	width;
	int 	j;
	int		space;
	int 	count;
	
	c =	va_arg(args, unsigned int);
	if (flag->width == 1)
	{
		count = 1;
		j = 0;
		width = malloc(sizeof(char *) * 1);
		while (ft_isdigit(format[type]))
		{
			width[j] = format[type];
			type++;
			j++;
		}
		space = ft_atoi(width);
		while(space > count)
		{
			ft_putchar(' ');
			count++;
		}
		free(width);
	}
	ft_putchar(c);
}