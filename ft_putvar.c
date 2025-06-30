/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:54:38 by msucu             #+#    #+#             */
/*   Updated: 2025/06/30 18:47:03 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"

int	ft_putvar(va_list args, t_varpro *varpro)
{
	int	space_count;
	int	zero_count;

	ft_putvar_check(varpro);
	space_count = varpro->width - ft_max(varpro->value_len, varpro->precision);
	zero_count = varpro->precision - varpro->value_len;
	ft_putvar_check_2(varpro, &space_count);
	if (ft_dash_check(args, varpro, zero_count, space_count) == -1)
		return (-1);
	return (varpro->writed);
}

int	ft_dash_check(va_list args, t_varpro *varpro, int zc, int sp)
{
	if (!ft_is_flag(varpro, '-'))
	{
		if (varpro->fill_char == '0')
			if (ft_putvar_put_extra(varpro) == -1)
				return (-1);
		if (ft_putchar_count(varpro->fill_char, sp, varpro, 1) == -1)
			return (-1);
		if (varpro->fill_char != '0')
			if (ft_putvar_put_extra(varpro) == -1)
				return (1);
		if (ft_putstr_count("0", zc, varpro, 1) == -1)
			return (-1);
		ft_putvar_arg(args, varpro);
		return (1);
	}
	if (ft_putvar_put_extra(varpro) == -1)
		return (-1);
	if (ft_putstr_count("0", zc, varpro, 1) == -1)
		return (-1);
	if (ft_putvar_arg(args, varpro) == -1)
		return (-1);
	if (ft_putchar_count(varpro->fill_char, sp, varpro, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putvar_arg(va_list args, t_varpro *varpro)
{
	int	temp;

	temp = 1;
	if (varpro->type == '%')
		temp = ft_putchar_count('%', 1, varpro, 1);
	if (varpro->type == 'c')
		temp = ft_putchar_count(va_arg(args, int), 1, varpro, 1);
	if (varpro->type == 's')
		temp = ft_putvar_str(va_arg(args, char *), varpro);
	if (varpro->type == 'p')
		temp = ft_putvar_p(va_arg(args, t_size_t), varpro);
	if (varpro->type == 'd' || varpro->type == 'i')
		temp = ft_putvar_nbr(va_arg(args, int), varpro);
	if (varpro->type == 'u')
		temp = ft_putvar_unbr(va_arg(args, unsigned int), varpro);
	if (varpro->type == 'x' || varpro->type == 'X')
		temp = ft_putvar_x(va_arg(args, unsigned int), varpro);
	return (temp);
}
