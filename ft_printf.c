/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/19 01:30:20 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
	flag->type = 0;
	flag->nbr_base = 10;
	flag->sign = 1;
}

int		ft_printf(const char *format, ...)
{
	int			d;
	va_list		args;
	t_flag		*flag;
	int			i;

	i = 0;
	va_start(args, format);
	flag = malloc(sizeof(t_flag) * 1);
	if (!flag)
		return -1;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_init_flags(flag);
			if (!(ft_strchr(TYPE,format[i++])))
				ft_check_flags(args, format, flag, i++);
			ft_conv(args, flag, format, i);
			i++;
		}
		i++;
	}
	//i += 1;
	return i;
}
//flag->type = format[i++];