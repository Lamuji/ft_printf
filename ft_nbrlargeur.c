/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhlel <hbouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:20:17 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/09 19:39:00 by hbouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char		ft_width(const char *str, int i, va_list args, t_flag *flag)
{
    char *stock;
    int n;
    int c;
    int v;
    int nbr;
    int compteur;
    int d;
    int r;
    int f;
	
    n = i;
    c = 0;
    v = 0;
    nbr = 0;
    compteur = 0;
    r = 0;
	while ((str[n] >= '0' && str[n] <= '9'))
    {
        n++;
        c++;
    }
    stock = malloc(sizeof(char) * c);
    while ((str[i] >= '0' && str[i] <= '9'))
    {
        stock[v] = str[i];
        i++;
        v++;
    }
    nbr = ft_atoi(stock);
    d = va_arg(args, int);
    r = ft_compte(d);
    while (compteur < nbr - r)
    {
        write(1, " ", 1);
        compteur++;
    }
	flag->type = str[i];
   // if (str[i] == TYPE)
	return (str[i]);
}
