/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/16 18:33:40 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_conv(va_list args, t_flag flag)
{
    int nbr;
    char c;
	char type;

	type = flag.type;
	if (type == '%')
		ft_putchar(type);
	else if (type == 'c')
		print_char(args, flag);
	else if (type == 'd' || type == 'i')
		print_d_i(args, flag);
	
	return type;
}
	