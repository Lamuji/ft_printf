/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:46 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/01 18:46:46 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_check_flags(va_list args, const char * format, t_flag *flag, int i)
{
	if (format[i] == 0 && flag->width == 0 && flag->prec == -1)
		flag->zero = 1;
	else if (format[i] == '-')
		flag->minus = 1;
	else if (format[i] == '.')
		flag->prec = 1;
	if (format[i] >= '1' && format[i] <= '9')
		flag->width = 1;
}