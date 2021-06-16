/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:21:59 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/16 19:20:18 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		print_d_i(va_list args, t_flag flag)
{
	int n;
	int j;
	int large;
	int p;
	char *larg;

	n = 0;
	j = 0;
	large = 0;
	p = 0;
	if (flag.width = 1)
	{
		while(format[i]) != ft_isalpha(format[i])
		{
			larg[j] = format[i];
			i++;
			j++;
		}
		larg[j] = '\0';
		large = ft_atoi(larg);
	} 
	
	n = va_arg(args, int);
	while (large > p)
	{
		putchar(' ');
		//ft_putnbr_fd(n,1);
		p++;
	}
	return n;
}
