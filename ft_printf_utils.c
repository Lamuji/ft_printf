/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:54 by rfkaier           #+#    #+#             */
/*   Updated: 2021/06/16 19:11:51 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = (n * -1);
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar((nbr % 10) + 48);
	}
	else
		ft_putchar(nbr + 48);
}

void	ft_putunbr_fd(long int n, int fd)
{
	unsigned long int nbr;

	if (n < 0)
	{
		n = 4294967296 + n;
		nbr = n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putunbr_fd(nbr / 10, fd);
		ft_putchar((nbr % 10) + 48);
	}
	else
		ft_putchar(nbr + 48);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int     ft_putnbr_base(unsigned long nbr, char *base)
{
    unsigned long len_base;

    len_base = ft_strlen(base);
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr == 0)
		ft_putchar('0');
	if (nbr >= len_base)
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putchar(base[nbr % len_base]);
	}
	else if (nbr <= len_base)
	ft_putchar(base[nbr]);
	return(nbr);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 49 && c <= 57)
		return (1);
	return (0);
}

static int	ft_isspace(char str)
{
	if (str == '\t' || str == '\n' || str == '\r'
		|| str == '\v' || str == '\f' || str == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	nbr;
	size_t	n;

	n = 0;
	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		else if (str[i] == '-')
			n++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	if (n % 2 == 0)
		return (nbr * 1);
	return (nbr * -1);
}
