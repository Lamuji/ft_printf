/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:46 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/17 21:20:59 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_check_flags(va_list args, const char * format, t_flag *flag, int i)
{
	/*if (format[i] == 0 && flag.width == 0 && flag.prec == -1)
		flag.zero = 1;
	else if (format[i] == '-')
		flag.minus = 1;
	else if (format[i] == '.')
		flag.prec = 0;*/
	if (ft_isdigit(format[i]) == 1)
		flag->width = 1;
}