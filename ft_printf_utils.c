/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:54 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/02 20:01:04 by rfkaier          ###   ########.fr       */
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

// int     ft_putnbr_base(unsigned long nbr, char *base)
// {
//     unsigned long len_base;

//     len_base = ft_strlen(base);
// 	if (nbr < 0)
// 		nbr = nbr * -1;
// 	if (nbr == 0)
// 		ft_putchar('0');
// 	if (nbr >= len_base)
// 	{
// 		ft_putnbr_base(nbr / len_base, base);
// 		ft_putchar(base[nbr % len_base]);
// 	}
// 	else if (nbr <= len_base)
// 	ft_putchar(base[nbr]);
// 	return(nbr);
//}

char	*ft_rev(char *dest, int i)
{
	char	*str;
	int		j;
	j = 0;
	str = ft_calloc(sizeof(str), i);
	i--;
	while (i >= 0)
	{
		str[j] = dest[i];
		i--;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa_base(unsigned long long int nbr, char *base)
{
	char	*dest;
	char	*str;
	int		i;
	int		len;
	int		remain;

	i = 0;
	remain = 0;
	len = ft_strlen(base);
	dest = ft_calloc(sizeof(dest), 20);
	if (!dest)
		return (NULL);
	while (nbr > 0)
	{
		remain = nbr % len;
		if (remain < 10)
			dest[i] = remain + '0';
		else
			dest[i] = 'a' + (remain - 10);
		nbr = nbr / len;
		i++;
	}
	str = ft_rev(dest, i);
	free(dest);
	return (str);
}


int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

int     ft_compte(int i)
{
    int e;
    char *c;

    e = 0;
    c = ft_itoa(i);
    while (c[e])
        e++;
    return (e);
}
static	int	ft_itoa_size(int n)
{
	int	size;
	int	neg;

	size = 0;
	neg = 0;
	if (n < 0 && n > -2147483648)
	{
		neg = 1;
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static	int	ft_makepos(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

static	int	ft_isneg(int x)
{
	if (x < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				i;
	int				size;
	int				neg;
	unsigned int	tmp;

	i = 1;
	size = ft_itoa_size(n);
	neg = ft_isneg(n);
	tmp = ft_makepos(n);
	s = (char *)malloc(sizeof(char) * ft_itoa_size(n) + 1);
	if (!s)
		return (NULL);
	if (tmp == 0)
		s[tmp] = '0';
	while (tmp >= 1)
	{
		s[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (neg)
		*s = '-';
	s[size] = '\0';
	return (s);
}

void	ft_putnbr(int n)
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
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	else
		ft_putchar(nbr + 48);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}