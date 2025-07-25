/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_varpro_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:43:44 by msucu             #+#    #+#             */
/*   Updated: 2025/07/02 19:58:48 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_fill_varpro(const char *format, t_varpro *varpro)
{
	int	i;

	i = 0;
	i = ft_find_flags(format, varpro, i);
	i = ft_calculate_width(format, varpro, i);
	i = ft_calculate_precision(format, varpro, i);
	if (format[i] != '\0' && ft_strchr("cspdiuxX%", format[i]))
		varpro->type = format[i++];
	else
		return (-1);
	varpro->var_format_len = i;
	return (i);
}

int	ft_find_flags(const char *format, t_varpro *varpro, int i)
{
	while (format[i] != '\0' && ft_strchr("-0# +", format[i]))
	{
		if (!ft_is_flag(varpro, format[i]))
			varpro->flags[ft_strlen(varpro->flags)] = format[i];
		i++;
	}
	return (i);
}

int	ft_calculate_width(const char *format, t_varpro *varpro, int i)
{
	while (format[i] != '\0' && ft_isdigit(format[i]))
	{
		varpro->width *= 10;
		varpro->width += format[i] - '0';
		i++;
	}
	return (i);
}

int	ft_calculate_precision(const char *format, t_varpro *varpro, int i)
{
	if (format[i] == '.')
	{
		i++;
		varpro->is_precision = 1;
		while (format[i] != '\0' && ft_isdigit(format[i]))
		{
			varpro->precision *= 10;
			varpro->precision += format[i] - '0';
			i++;
		}
	}
	return (i);
}
