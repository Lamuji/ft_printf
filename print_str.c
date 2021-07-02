/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:16:12 by ramzi             #+#    #+#             */
/*   Updated: 2021/06/29 22:04:29 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_str(va_list args, t_flag * flag, const char * format, int type)
{
    char *  str;
    int     count;
    int     j;
    char *  width;
    int     space;
 
    str = va_arg(args, char *);
    if (flag->width == 1)
    {
        j = 0;
        count = 0;
        width = malloc(sizeof(char *) * 1);
        while (ft_isdigit(format[type]))
        {
            width[j] = format[type];
            type++;
            j++;
        }
        space = atoi(width) - ft_strlen(str);
        if (space > 0)
        {
            while (space > count)
            {
               ft_putchar(' ');
              count++;
            }
        }
        else
            free(width);
    }
    ft_putstr(str);
}