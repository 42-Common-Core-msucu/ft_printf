/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:17:57 by msucu             #+#    #+#             */
/*   Updated: 2025/07/02 19:50:13 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putarg_p(t_size_t nbr)
{
	int	writed;
	int	temp;

	if (nbr == 0)
	{
		temp = ft_putstr("(nil)");
		if (temp == -1)
			return (-1);
		return (temp);
	}
	writed = 0;
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	writed += temp;
	temp = ft_putnbr_hexa(nbr, 0);
	if (temp == -1)
		return (-1);
	writed += temp;
	return (writed);
}

int	ft_putarg(va_list args, char type)
{
	int	temp;

	temp = 1;
	if (type == '%')
		temp = ft_putchar('%');
	if (type == 'c')
		temp = ft_putchar(va_arg(args, int));
	if (type == 's')
		temp = ft_putstr(va_arg(args, char *));
	if (type == 'p')
		temp = ft_putarg_p(va_arg(args, t_size_t));
	if (type == 'd' || type == 'i')
		temp = ft_putnbr(va_arg(args, int));
	if (type == 'u')
		temp = ft_putunbr(va_arg(args, unsigned int));
	if (type == 'x')
		temp = ft_putnbr_hexa(va_arg(args, unsigned int), 0);
	if (type == 'X')
		temp = ft_putnbr_hexa(va_arg(args, unsigned int), 1);
	return (temp);
}

int	ft_var_check(va_list args, const char **format, int *writed)
{
	int	temp;

	if (*(*format + 1) != '\0' && ft_strchr("cspdiuxX%", *(*format + 1)))
	{
		temp = ft_putarg(args, *(*format + 1));
		if (temp == -1)
			return (-1);
		*writed += temp;
		(*format)++;
	}
	else
	{
		if (write(1, *format, 1) == -1)
			return (-1);
		*writed += 1;
	}
	return (1);
}

int	ft_format_while(va_list args, const char **format, int *writed)
{
	if (**format == '%')
	{
		if (ft_var_check(args, format, writed) == -1)
			return (-1);
	}
	else
	{
		if (write(1, (*format), 1) == -1)
			return (-1);
		(*writed) += 1;
	}
	(*format)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		writed;

	if (format == FT_NULL)
		return (-1);
	writed = 0;
	va_start(args, format);
	while (*format)
		ft_format_while(args, &format, &writed);
	va_end(args);
	return (writed);
}
