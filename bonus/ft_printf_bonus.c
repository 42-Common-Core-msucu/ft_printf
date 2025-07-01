/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:43 by msucu             #+#    #+#             */
/*   Updated: 2025/07/01 13:40:23 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handvar(va_list args, const char *format, t_varpro *varpro)
{
	int		writed;

	if (ft_fill_varpro(format, varpro) == -1)
		return (-1);
	ft_calculate_len(args, varpro);
	writed = ft_putvar(args, varpro);
	return (writed);
}

int	ft_var_check(const char *format, va_list args, t_varpro *varpro, int *w)
{
	int	temp;
	int	temp2;
	int	return_val;

	temp = ft_handvar(args, format + 1, varpro);
	if (temp == -1)
	{
		temp2 = ft_putchar_count(*format, 1, varpro, 0);
		if (temp2 == -1)
			return (-1);
		*w += temp2;
	}
	else
	{
		*w += temp;
		return_val = varpro->var_format_len;
	}
	*varpro = ft_reset_var(*varpro);
	return (return_val);
}

int	ft_format_check(const char **format, va_list args, t_varpro *varpro, int *w)
{
	int	temp;

	if (**format == '%')
	{
		temp = ft_var_check(*format, args, varpro, w);
		if (temp == -1)
			return (-1);
		*format += temp;
	}
	else
	{
		temp = ft_putchar_count(**format, 1, varpro, 0);
		if (temp == -1)
			return (-1);
		*w += temp;
	}
	(*format)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			writed;
	int			temp;
	t_varpro	varpro;

	if (format == FT_NULL)
		return (-1);
	varpro = ft_reset_var(varpro);
	va_start(args, format);
	writed = 0;
	while (*format)
	{
		temp = ft_format_check(&format, args, &varpro, &writed);
		if (temp == -1)
			return (-1);
	}
	va_end(args);
	return (writed);
}
