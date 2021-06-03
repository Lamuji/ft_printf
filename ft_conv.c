/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/03 18:20:57 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"


int		ft_conv(va_list args ,char const *format, int i)
{
	i++;
	if (format[i] == 'd')
		{
			i = va_arg(args, int);
			ft_putnbr_fd(i, 1);
		}
		return i;
}
