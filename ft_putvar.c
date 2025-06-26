#include <stdarg.h>
#include "ft_printf.h"

#include <stdio.h>

int	ft_putvar(va_list args, t_varpro *varpro)
{
	int	space_count;
	int zero_count;

	space_count = varpro->width - ft_max(varpro->value_len, varpro->precision);
	zero_count = varpro->precision - varpro->value_len;
	// printf("%d\n", space_count);
	// printf("%d\n", zero_count);
	if (!ft_strchr(varpro->flags, '-'))
	{
		ft_putchar_count(varpro->fill_char, space_count, varpro);
		ft_putstr_count("0", zero_count, varpro);
		ft_putvar_arg(args, varpro);
	}
	else
	{
		ft_putvar_arg(args, varpro);
		ft_putstr_count("0", zero_count, varpro);
		ft_putchar_count(varpro->fill_char, space_count, varpro);
	}
	return (varpro->writed);
	// ft_putextra(varpro);
}

void	ft_putvar_arg(va_list args, t_varpro *varpro)
{
	if (varpro->type == 'd' || varpro->type == 'i')
		ft_putvar_nbr(va_arg(args, int), varpro);
}

void	ft_putvar_nbr(int n, t_varpro *varpro)
{
	if (ft_strchr(varpro->flags, '+') && n > 0)
		ft_putchar_count('+', 1, varpro);
	if (ft_strchr(varpro->flags, ' ') && n > 0)
		ft_putchar_count(' ', 1, varpro);
	ft_putnbr_fd(n, 1);
	varpro->writed += varpro->value_len;
}

// void	ft_putextra(t_varpro *varpro)
// {
// 	if (varpro->type == 'x' && ft_strchr(varpro->flags, '#') && varpro->fill_char == '0')
// 		varpro->width -= ft_putstr_count("0x", 1, varpro);
// 	if (varpro->type == 'X' && ft_strchr(varpro->flags, '#') && varpro->fill_char == '0')
// 		varpro->width -= ft_putstr_count("0X", 1, varpro);
// 	if (ft_strchr("di", varpro->type) && ft_strchr(varpro->flags, '+') && varpro->sign == 1)
// 		varpro->width -= ft_putstr_count("+", 1, varpro);
// 	if (ft_strchr("di", varpro->type) && ft_strchr(varpro->flags, ' ') && varpro->sign == 1)
// 		varpro->width -= ft_putstr_count(" ", 1, varpro);
// }

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_putstr_count(char *str, int count, t_varpro *varpro)
{
	int	i;
	int len;

	len = (int) ft_strlen(str);
	i = 0;
	while (i < count)
	{
		ft_putstr_fd(str, 1);
		i++;
	}
	varpro->writed += count * len;
	return (count * len);
}

int	ft_putchar_count(char c, int count, t_varpro *varpro)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	varpro->writed += count;
	return (count);
}
