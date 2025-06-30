/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:13:28 by msucu             #+#    #+#             */
/*   Updated: 2025/06/30 18:20:30 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"

int	ft_putvar_nbr(int n, t_varpro *varpro)
{
	int	temp;

	if (!(varpro->is_precision == 1 && varpro->precision == 0
			&& varpro->sign == 0))
	{
		temp = ft_putnbr(n);
		if (temp == -1)
			return (-1);
		varpro->writed += varpro->value_len;
	}
	return (1);
}

int	ft_putvar_unbr(unsigned int n, t_varpro *varpro)
{
	int	temp;

	if (n == 0 && varpro->is_precision == 1)
		return (1);
	temp = ft_putunbr(n);
	if (temp == -1)
		return (-1);
	varpro->writed += varpro->value_len;
	return (1);
}

int	ft_putvar_str(char *str, t_varpro *varpro)
{
	if (str == FT_NULL)
	{
		if ((varpro->is_precision == 1 && varpro->precision >= 6)
			|| varpro->is_precision == 0)
			if (ft_putstr_count("(null)", 1, varpro, 1) == -1)
				return (-1);
		return (1);
	}
	if (ft_putstr_max(str, varpro->value_len) == -1)
		return (-1);
	varpro->writed += varpro->value_len;
	return (1);
}

int	ft_putvar_p(t_size_t p, t_varpro *varpro)
{
	if (p == 0)
	{
		if (ft_putstr_count("(nil)", 1, varpro, 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_putstr_max("0x", 2) == -1)
		return (-1);
	if (ft_putnbr_hexa(p, 0) == -1)
		return (-1);
	varpro->writed += varpro->value_len;
	return (1);
}

int	ft_putvar_x(t_size_t x, t_varpro *varpro)
{
	if (x == 0 && varpro->is_precision == 1)
		return (1);
	if (varpro->type == 'x')
		if (ft_putnbr_hexa(x, 0) == -1)
			return (-1);
	if (varpro->type == 'X')
		if (ft_putnbr_hexa(x, 1) == -1)
			return (-1);
	varpro->writed += varpro->value_len;
	return (1);
}
