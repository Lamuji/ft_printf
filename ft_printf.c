/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/11 18:53:44 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flag *flag)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		flag;
	int			i;

	i = 0;
	flag = malloc(sizeof(t_flag) * 1);
	if (!flag)
		return NULL;
	va_start(args, format);
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar(format[i++]);
		while (format[i] == '%')
		{
			ft_init_flags(flag);
			if (format[i + 1] != '')
			
		}
		

	}
	return 0;
}

