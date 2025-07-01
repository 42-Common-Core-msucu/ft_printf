/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:29 by msucu             #+#    #+#             */
/*   Updated: 2025/07/01 15:31:58 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (str == FT_NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr(int nbr)
{
	long	n;
	char	c;
	int		writed;
	int		temp;

	writed = 1;
	n = nbr;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		writed++;
	}
	if (n >= 10)
	{
		temp = ft_putnbr(n / 10);
		if (temp == -1)
			return (-1);
		writed += temp;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (writed);
}

int	ft_putunbr(unsigned int nbr)
{
	char	c;
	int		writed;
	int		temp;

	writed = 0;
	if (nbr >= 10)
	{
		temp = ft_putunbr(nbr / 10);
		if (temp == -1)
			return (-1);
		writed += temp;
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	writed++;
	return (writed);
}

int	ft_putnbr_hexa(t_size_t nbr, int is_upper)
{
	char	*base;
	int		temp;
	int		writed;

	writed = 0;
	base = "0123456789abcdef";
	if (is_upper == 1)
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		temp = ft_putnbr_hexa(nbr / 16, is_upper);
		if (temp == -1)
			return (-1);
		writed += temp;
	}
	if (write(1, &base[nbr % 16], 1) == -1)
		return (-1);
	writed++;
	return (writed);
}
