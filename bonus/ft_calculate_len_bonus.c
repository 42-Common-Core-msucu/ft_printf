/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:55:56 by msucu             #+#    #+#             */
/*   Updated: 2025/07/01 13:33:16 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_calculate_len(va_list args, t_varpro *varpro)
{
	va_list	args_copy;

	va_copy(args_copy, args);
	if (varpro->type == '%')
		varpro->value_len = 1;
	if (varpro->type == 'c')
		varpro->value_len = 1;
	if (varpro->type == 's')
		varpro->value_len = ft_str_count(va_arg(args_copy, char *), varpro);
	if (varpro->type == 'p')
		varpro->value_len = ft_digit_count_hexa(
				(t_size_t) va_arg(args_copy, void *), varpro) + 2;
	if (varpro->type == 'd' || varpro->type == 'i')
		varpro->value_len = ft_digit_count(va_arg(args_copy, int), varpro);
	if (varpro->type == 'u')
		varpro->value_len = ft_digit_count_unsigned(
				va_arg(args_copy, unsigned int), varpro);
	if (varpro->type == 'x' || varpro->type == 'X')
		varpro->value_len = ft_digit_count_hexa(
				va_arg(args_copy, unsigned int), varpro);
	if (ft_is_flag(varpro, '0') && !ft_is_flag(varpro, '-')
		&& varpro->is_precision == 0)
		varpro->fill_char = '0';
	va_end(args_copy);
}

int	ft_str_count(char *str, t_varpro *varpro)
{
	int	i;

	if (str == FT_NULL)
	{
		varpro->sign = 0;
		return (6);
	}
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_digit_count(int nbr, t_varpro *varpro)
{
	long int	temp;
	int			count;

	count = 0;
	temp = nbr;
	if (temp > 0)
		varpro->sign = 1;
	if (temp == 0)
		varpro->sign = 0;
	if (temp < 0)
		temp *= -1;
	if (varpro->is_precision == 1 && varpro->precision == 0 && temp == 0)
		return (0);
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

int	ft_digit_count_hexa(t_size_t hexa, t_varpro *varpro)
{
	int	count;

	count = 0;
	if (hexa == 0)
	{
		varpro->sign = 0;
		if (varpro->is_precision == 0)
			return (1);
		return (0);
	}
	while (hexa != 0)
	{
		hexa /= 16;
		count++;
	}
	return (count);
}

int	ft_digit_count_unsigned(unsigned int nbr, t_varpro *varpro)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		if (varpro->is_precision == 0)
			return (1);
		return (0);
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
