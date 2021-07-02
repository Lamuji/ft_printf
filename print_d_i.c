/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:21:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/01 20:53:43 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(int n, const char * format, int type)
{
	int		j;
	int		count;
	char *		p;
	char * 	width;
	int		space;

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
	while (space > count++)
		ft_putchar(' ');
	free(width);
}

void		print_d_i(va_list args, t_flag *flag , const char *format, int type)
{
	int 	n;

	n = va_arg(args, int);
	if (flag->width == 1)
		width(n, format, type);
	ft_putnbr_fd(n, 1);
}





