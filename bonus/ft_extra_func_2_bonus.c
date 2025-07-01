/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_func_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:46:29 by msucu             #+#    #+#             */
/*   Updated: 2025/07/01 14:35:25 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

int	ft_putnbr(int nbr)
{
	long	n;
	char	c;

	n = (long) nbr;
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		if (ft_putnbr(n / 10) == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putunbr(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		if (ft_putunbr(n / 10) == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_hexa(t_size_t n, int is_upper)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (is_upper == 1)
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (ft_putnbr_hexa(n / 16, is_upper) == -1)
			return (-1);
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
