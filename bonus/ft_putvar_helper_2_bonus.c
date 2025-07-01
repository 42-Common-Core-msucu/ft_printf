/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar_helper_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:53:58 by msucu             #+#    #+#             */
/*   Updated: 2025/07/01 13:33:16 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_fill_val_pre(t_varpro *varpro, int n)
{
	varpro->value_len = n;
	varpro->precision = n;
}

void	ft_putvar_check(t_varpro *varpro)
{
	if (varpro->type == 's' && varpro->is_precision == 1 && varpro->sign != 0)
	{
		varpro->precision = ft_min(varpro->value_len, varpro->precision);
		varpro->value_len = ft_min(varpro->value_len, varpro->precision);
	}
	if (varpro->type == 's' && varpro->sign == 0)
	{
		if (varpro->is_precision == 1)
		{
			if (varpro->precision < 6)
				ft_fill_val_pre(varpro, 0);
			else
				ft_fill_val_pre(varpro, 6);
		}
	}
	if (varpro->type == 'p' && varpro->sign == 0)
		varpro->value_len = 5;
	if (varpro->type == '%')
	{
		varpro->width = 1;
		varpro->is_precision = 0;
		varpro->precision = 0;
	}
}

void	ft_putvar_check_2(t_varpro *varpro, int *sc)
{
	if (varpro->type == 'd' || varpro->type == 'i')
	{
		if ((ft_is_flag(varpro, '+') || ft_is_flag(varpro, ' '))
			&& (varpro->sign == 1 || varpro->sign == 0))
			(*sc)--;
		if (varpro->sign == -1)
			(*sc)--;
	}
	if (varpro->type == 'x' || varpro->type == 'X')
	{
		if (ft_is_flag(varpro, '#'))
			(*sc) -= 2;
	}
}

int	ft_putvar_put_extra(t_varpro *varpro)
{
	if (varpro->type == 'd' || varpro->type == 'i')
	{
		if (ft_is_flag(varpro, '+') && (varpro->sign == 1 || varpro->sign == 0)
			&& ft_putchar_count('+', 1, varpro, 1) == -1)
			return (-1);
		else if (ft_is_flag(varpro, ' ')
			&& (varpro->sign == 1 || varpro->sign == 0)
			&& ft_putchar_count(' ', 1, varpro, 1) == -1)
			return (-1);
		else if (varpro->sign == -1
			&& ft_putchar_count('-', 1, varpro, 1) == -1)
			return (-1);
	}
	if (varpro->type == 'x' || varpro->type == 'X')
	{
		if (ft_is_flag(varpro, '#') && varpro->type == 'x' && varpro->sign != 0)
			if (ft_putstr_count("0x", 1, varpro, 1) == -1)
				return (-1);
		if (ft_is_flag(varpro, '#') && varpro->type == 'X' && varpro->sign != 0)
			if (ft_putstr_count("0X", 1, varpro, 1) == -1)
				return (-1);
	}
	return (1);
}
