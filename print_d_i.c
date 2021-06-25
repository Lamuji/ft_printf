/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:21:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/25 17:05:25 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		print_d_i(va_list args, t_flag *flag , const char *format, int i)
{
	char * 	width;
	int		space;
	int 	n;
	int		j;
	int		count;
	char *		p;

	
	j = 0;
	count = 0;
	n = va_arg(args, int);
	width = malloc(sizeof(char *) * 1);
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
	ft_putnbr_fd(n,1);
	free(width);
}




