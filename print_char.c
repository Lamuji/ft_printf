/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:25:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/19 00:35:15 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list args, t_flag *flags)
{
	char	c;
	
	c =	va_arg(args, int);
	/*if (flag.zero == 1)
		{
			
			printf("fahsfla fsa %c", 'k');
		}*/
	
	ft_putchar(c);
	return 0;
}
