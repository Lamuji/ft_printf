/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:46 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 16:30:32 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_flags(const char * format, t_flag *flag, int i)
{
	if (format[i] == '0') //&& flag->width == 0 && flag->prec == 0)
		flag->zero = 1;
	else if (format[i] == '-')
		flag->minus = 1;
	else if (format[i] == '.')
		flag->prec = 1;
	else if (format[i] >= '1' && format[i] <= '9')
		flag->width = 1;
}