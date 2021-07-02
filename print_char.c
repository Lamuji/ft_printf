/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:25:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/02 20:13:45 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	width_c(const char * format, int type)
{
	char *	width;
	int 	j;
	int		space;
	int 	count;

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
	printf("///%d///", space);
	while(space > count++)
		ft_putchar(' ');
	free(width);
}

void	fill_zero_c(const char * format, int type)
{
	char *	width;
	int 	j;
	int		space;
	int 	count;
	
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
	printf("///%d///", space);
	while(space > count++)
		ft_putchar('0');
	free(width);
}

void	minus_c(const char * format, int type)
{
	char *	width;
	int 	j;
	int		space;
	int 	count;
	
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
	//printf("///%d///", space);
	while(space > count++)
		ft_putchar(' ');
	free(width);
}

void	print_char(va_list args, t_flag *flag, const char * format, int type)
{
	char	c;

	c =	va_arg(args, unsigned int);
	if (flag->width == 1)
		width_c(format, type);
	if (flag->zero == 1)
		fill_zero_c(format, type);
	ft_putchar(c);
	if (flag->minus == 1)
		minus_c(format, type + 1);
}
