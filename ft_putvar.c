#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

#include <stdio.h>

int	ft_putvar(va_list args, t_varpro *varpro)
{
	int	space_count;
	int zero_count;

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
			{
				varpro->value_len = 0;
				varpro->precision = 0;
			}
			else
			{
				varpro->value_len = 6;
				varpro->precision = 6;
			}
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

	space_count = varpro->width - ft_max(varpro->value_len, varpro->precision);
	zero_count = varpro->precision - varpro->value_len;
	// printf("%d\n", space_count);
	// printf("%d\n", zero_count);
	// printf("%d\n", varpro->sign);
	if (varpro->type == 'd' || varpro->type == 'i')
	{
		if ((ft_strchr(varpro->flags, '+') || ft_strchr(varpro->flags, ' '))
		&& (varpro->sign == 1 || varpro->sign == 0))
			space_count--;
		if (varpro->sign == -1)
			space_count--;
	}
	if (varpro->type == 'x' || varpro->type == 'X')
	{
		if (ft_strchr(varpro->flags, '#'))
			space_count -= 2;
	}
	if (!ft_strchr(varpro->flags, '-'))
	{
		if (varpro->fill_char == '0')
		{
			if (varpro->type == 'd' || varpro->type == 'i')
			{
				if (ft_strchr(varpro->flags, '+') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count('+', 1, varpro);
				else if (ft_strchr(varpro->flags, ' ') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count(' ', 1, varpro);
				else if (varpro->sign == -1)
					ft_putchar_count('-', 1, varpro);
			}
			if (varpro->type == 'x' || varpro->type == 'X')
			{
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'x' && varpro->sign != 0)
					ft_putstr_count("0x", 1, varpro);
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'X' && varpro->sign != 0)
					ft_putstr_count("0X", 1, varpro);
			}
		}
		ft_putchar_count(varpro->fill_char, space_count, varpro);
		if (varpro->fill_char != '0')
		{
			if (varpro->type == 'd' || varpro->type == 'i')
			{
				if (ft_strchr(varpro->flags, '+') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count('+', 1, varpro);
				else if (ft_strchr(varpro->flags, ' ') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count(' ', 1, varpro);
				else if (varpro->sign == -1)
					ft_putchar_count('-', 1, varpro);
			}
			if (varpro->type == 'x' || varpro->type == 'X')
			{
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'x' && varpro->sign != 0)
					ft_putstr_count("0x", 1, varpro);
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'X' && varpro->sign != 0)
					ft_putstr_count("0X", 1, varpro);
			}
		}
		ft_putstr_count("0", zero_count, varpro);
		ft_putvar_arg(args, varpro);
	}
	else
	{
		if (varpro->fill_char == '0')
		{
			if (varpro->type == 'd' || varpro->type == 'i')
			{
				if (ft_strchr(varpro->flags, '+') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count('+', 1, varpro);
				else if (ft_strchr(varpro->flags, ' ') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count(' ', 1, varpro);
				else if (varpro->sign == -1)
					ft_putchar_count('-', 1, varpro);
			}
			if (varpro->type == 'x' || varpro->type == 'X')
			{
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'x' && varpro->sign != 0)
					ft_putstr_count("0x", 1, varpro);
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'X' && varpro->sign != 0)
					ft_putstr_count("0X", 1, varpro);
			}
		}

		if (varpro->fill_char != '0')
		{
			if (varpro->type == 'd' || varpro->type == 'i')
			{
				if (ft_strchr(varpro->flags, '+') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count('+', 1, varpro);
				else if (ft_strchr(varpro->flags, ' ') && (varpro->sign == 1 || varpro->sign == 0))
					ft_putchar_count(' ', 1, varpro);
				else if (varpro->sign == -1)
					ft_putchar_count('-', 1, varpro);
			}
			if (varpro->type == 'x' || varpro->type == 'X')
			{
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'x' && varpro->sign != 0)
					ft_putstr_count("0x", 1, varpro);
				if (ft_strchr(varpro->flags, '#') && varpro->type == 'X' && varpro->sign != 0)
					ft_putstr_count("0X", 1, varpro);
			}
		}
		ft_putstr_count("0", zero_count, varpro);
		ft_putvar_arg(args, varpro);
		ft_putchar_count(varpro->fill_char, space_count, varpro);
	}
	return (varpro->writed);
	// ft_putextra(varpro);
}

void	ft_putvar_unbr(unsigned int n, t_varpro *varpro);
void	ft_putvar_c(int c, t_varpro *varpro);
void	ft_putvar_str(char *str, t_varpro *varpro);
void	ft_putvar_p(t_size_t p, t_varpro *varpro);
void	ft_putvar_x(t_size_t x, t_varpro *varpro);

void	ft_putvar_arg(va_list args, t_varpro *varpro)
{
	if (varpro->type == '%')
		ft_putvar_c('%', varpro);
	if (varpro->type == 'c')
		ft_putvar_c(va_arg(args, int), varpro);
	if (varpro->type == 's')
		ft_putvar_str(va_arg(args, char *), varpro);
	if (varpro->type == 'p')
		ft_putvar_p(va_arg(args, t_size_t), varpro);
	if (varpro->type == 'd' || varpro->type == 'i')
		ft_putvar_nbr(va_arg(args, int), varpro);
	if (varpro->type == 'u')
		ft_putvar_unbr(va_arg(args, unsigned int), varpro);
	if (varpro->type == 'x' || varpro->type == 'X')
		ft_putvar_x(va_arg(args, unsigned int), varpro);
}

// Prototipler
void	ft_putnbr(int nbr);
void	ft_putunbr(unsigned int n);
void	ft_putnbr_hexa(t_size_t n, int is_upper);
void	ft_putstr(char *str, int max);

// Genel Yazdırma Fonksiyonları
void	ft_putvar_nbr(int n, t_varpro *varpro)
{
	if (!(varpro->is_precision == 1 && varpro->precision == 0 && varpro->sign == 0))
	{
		ft_putnbr(n);
		varpro->writed += varpro->value_len;
	}
}

void	ft_putvar_unbr(unsigned int n, t_varpro *varpro)
{
	if (n == 0 && varpro->is_precision == 1)
		return ;
	ft_putunbr(n);
	varpro->writed += varpro->value_len;
}

void	ft_putvar_c(int c, t_varpro *varpro)
{
	ft_putchar_fd(c, 1);
	varpro->writed += varpro->value_len;
}

void	ft_putvar_str(char *str, t_varpro *varpro)
{
	if (str == FT_NULL)
	{
		if ((varpro->is_precision == 1 && varpro->precision >= 6) || varpro->is_precision == 0)
			ft_putstr_count("(null)", 1, varpro);
		return ;
	}
	ft_putstr(str, varpro->value_len);
	varpro->writed += varpro->value_len;
}

void	ft_putvar_p(t_size_t p, t_varpro *varpro)
{
	if (p == 0)
	{
		ft_putstr_count("(nil)", 1, varpro);
		return ;
	}
	ft_putstr("0x", 2);
	ft_putnbr_hexa(p, 0);
	varpro->writed += varpro->value_len;
}

void	ft_putvar_x(t_size_t x, t_varpro *varpro)
{
	if (x == 0 && varpro->is_precision == 1)
		return ;
	if (varpro->type == 'x')
		ft_putnbr_hexa(x, 0);
	if (varpro->type == 'X')
		ft_putnbr_hexa(x, 1);
	varpro->writed += varpro->value_len;
}

// Yazdırma Fonksiyonları

void	ft_putnbr(int nbr)
{
	long	n;
	char	c;

	n = (long) nbr;
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1);
}

void	ft_putunbr(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1);
}

void	ft_putnbr_hexa(t_size_t n, int is_upper)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (is_upper == 1)
		base = "0123456789ABCDEF";
	
	if (n >= 16)
		ft_putnbr_hexa(n / 16, is_upper);
	c = base[n % 16];
	ft_putchar_fd(c, 1);
}

void	ft_putstr(char *str, int max)
{
	write(1, str, ft_min(max, ft_strlen(str)));
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

int ft_min(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

int	ft_putstr_count(char *str, int count, t_varpro *varpro)
{
	int	i;
	int len;

	if (count <= 0)
		return (0);
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

	if (count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	varpro->writed += count;
	return (count);
}
