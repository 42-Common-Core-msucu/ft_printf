/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:43 by msucu             #+#    #+#             */
/*   Updated: 2025/06/24 21:59:58 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

// Types:
// 0: c for char
// 1: s for string
// 2: p for pointer
// 3: d for decimal (signed integer)
// 4: i for integer (signed integer, same as %d)
// 5: u for unsigned (unsigned decimal integer)
// 6: x for hexadecimal (lowercase)
// 7: X for heXadecimal (uppercase)
// 8: % for percent sign

static void	ft_check_sign(va_list args, int c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
		return (2);
	if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		temp;
	char	c;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			c = *(format + 1);
			if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
				|| c == 'u' || c == 'x' || c == 'X' || c == '%')
			{
				ft_check_sign(args, c);
				format++;
			}
			else
				write(1, format, 1);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
}
