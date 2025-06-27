/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:43 by msucu             #+#    #+#             */
/*   Updated: 2025/06/27 18:42:56 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*
Types:
	0: c for char
	1: s for string
	2: p for pointer
	3: d for decimal (signed integer)
	4: i for integer (signed integer, same as %d)
	5: u for unsigned (unsigned decimal integer)
	6: x for hexadecimal (lowercase)
	7: X for heXadecimal (uppercase)
	8: % for percent sign

Yapılması gerekenler:
-> Yazdırılan karakter sayılması lazım

Formatlar özet:
-> % sayi (all - %)  minimum genişlik belirtme (boşluk)
-> % 0 sayi (int p)  minimum genişlik belirtme (sıfır)
	Diğer türler olduğunda sıfırı görmezden gelerek yazdırmak lazım
-> % - sayi (d) sola yaslayarak minimum genişlik (boşluk)
	Eğer - ile 0 bayrağı beraber kullanılırsa (%-05d veya %0-5d gibi)
	o zaman - bayrağı 0 bayrağını yok sayar
-> % . sayi (int p)
	Eğer precision ile 0 bayrağı beraber kullanılırsa (%-05d veya %0-5d gibi)
	o zaman - bayrağı 0 bayrağını yok sayar

+ -> di
- -> all
# -> xX
(boşluk) -> di
0 -> diuxXp
	
all: c/s/p/d/i/u/x/X/%
int: d/i/u/x/X
str: c/s

all: cspdiuxX%
int: diuxX
str: cs

flags: - 0 # (boşluk) +
width: sayi
precision: .sayi
type: all

syntax: % flags width precision type

İstisnalar:
% sayi % -> Sayı görmezden gelinip direkt yüzde yazdırılır
% 0 (all) -> 0 görmezden gelinir ve normal yazdırılır
% - (all) -> - görmezden gelinir ve normal yazdırılır
% . (all) -> . sayi varsayılan olarak 0 gibi hesaplanır normal yazdırılır
% . sayi (c) -> sayida görmezden gelinerek direkt harf yazdırılır. Eğer . olmasaydı sayi-1 kadar
	boşluk olurdu
0 ve . beraber kullanıldığında int için zaten 0 koymaya devam eder, s için kırpma yapılır, c'de yine sadece harf yazılır
*/

int	ft_args_end_return(va_list args)
{
	va_end(args);
	return (-1);
}

int ft_handvar(va_list args, const char *format, t_varpro *varpro)
{
	int		writed;
	
	if (ft_fill_varpro(format, varpro) == -1)
		return (-1);
	ft_calculate_len(args, varpro);
	writed = ft_putvar(args, varpro);
	// format += varpro->var_format_len;
	return (writed);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int writed;
	int temp;
	t_varpro varpro;

	varpro = ft_reset_var(varpro);
	va_start(args, format);
	writed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			temp = ft_handvar(args, format + 1, &varpro);
			if (temp == -1)
				writed += ft_putchar_return(*format);
			else
			{
				// ft_print_varpro(&varpro);
				writed += temp;
				format += varpro.var_format_len;
			}
			varpro = ft_reset_var(varpro);
		}
		else
			writed += ft_putchar_return(*format);
		format++;
	}
	va_end(args);
	return (writed);
}
