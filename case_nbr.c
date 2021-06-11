/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:05:06 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/11 18:22:47 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_nbr(int nbr, va_list args, t_flag flag)
{
	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	return nbr;
{
	/*if (i == 'x')
	{
		nbr = va_arg(args, unsigned int);
		ft_putnbr_base(nbr,"0123456789abcdef");
	}
	else if (i == 'X')
	{
		nbr = va_arg(args, unsigned int);
		ft_putnbr_base(nbr,"0123456789ABCDEF");
	}
	return nbr;
}