/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:44 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 18:53:19 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->type = 0;
	flag->count = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flag		*flag;
	int			i;
//	int			tl = 0;

	i = 0;
	flag = malloc(sizeof(t_flag));
	va_start(args, format);
	if (!flag || format == NULL)
		return (-1);
	ft_init_flags(flag);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (!(ft_strchr(TYPE,format[++i])))
				ft_check_flags(format, flag, i);
			ft_conv(args, flag, format, i);
			while (!(ft_strchr(TYPE,format[i])))
				i++;
			i++;
		}
		//tl += write(1, &format[i], 1);
		ft_putchar(format[i], flag);
		i++;
	}
	//tl += flag->count;
	va_end(args);
	free(flag);
	return (flag->count);
}