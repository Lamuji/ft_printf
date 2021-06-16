/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:46 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/16 18:55:41 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_check_flags(va_list args, const char * format, t_flag flag, int i)
{
	if (format[i] == 0 && flag.width == 0 && flag.prec == -1)
		flag.zero = 1;
	else if (format[i] == '-')
		flag.minus = 1;
	else if (format[i] == '.')
		flag.prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		flag.width = 1;
	return 0;
}	