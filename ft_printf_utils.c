/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:06:54 by rfkaier           #+#    #+#             */
/*   Updated: 2021/07/11 18:45:04 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_flag *flag)
{
	flag->count += write(1, &c, 1);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void	ft_putunbr_fd(long int n, int fd, t_flag *flag)
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
		ft_putunbr_fd(nbr / 10, fd, flag);
		ft_putchar((nbr % 10) + 48, flag);
	}
	else
		ft_putchar(nbr + 48, flag);
}

void	ft_putstr(char *str, t_flag *flag)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], flag);
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	max;

	max = nmemb * size;
	tab = malloc(max);
	if (!tab)
		return (NULL);
	i = 0;
	while (max--)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}

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

char	*ft_itoa_base_maj(unsigned long long int nbr, char *base)
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
			dest[i] = 'A' + (remain - 10);
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

void	ft_putnbr(int n, t_flag *flag)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar('-', flag);
		nbr = (n * -1);
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, flag);
		ft_putchar((nbr % 10) + 48, flag);
	}
	else
		ft_putchar(nbr + 48, flag);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len_s2;
	char		*dest;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + len_s2 + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	len_s2 = -1;
	while (s2[++len_s2])
	{
		dest[i] = s2[len_s2];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}