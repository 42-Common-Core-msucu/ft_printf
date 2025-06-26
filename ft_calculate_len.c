#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

// cspdiuxX%

void	ft_calculate_len(va_list args, t_varpro *varpro)
{
	va_list	args_copy;

	va_copy(args_copy, args);
	if (varpro->type == 'c')
		varpro->value_len = 1;
	if (varpro->type == 's')
		varpro->value_len = ft_str_count(va_arg(args_copy, char *));
	if (varpro->type == 'p')
		varpro->value_len = ft_digit_count_hexa((t_size_t) va_arg(args_copy, void *));
	if (varpro->type == 'd' || varpro->type == 'i')
		varpro->value_len = ft_digit_count(va_arg(args_copy, int), varpro);
	if (varpro->type == 'u')
		varpro->value_len = ft_digit_count_unsigned(va_arg(args_copy, unsigned int));
	if (varpro->type == 'x' || varpro->type == 'X')
		varpro->value_len = ft_digit_count_hexa(va_arg(args_copy, unsigned int));
	if (ft_strchr(varpro->flags, '0') && !ft_strchr(varpro->flags, '-') && varpro->is_precision == 0)
		varpro->fill_char = '0';
	va_end(args_copy);
}

int ft_str_count(char *str)
{
	int	i;

	if (str == FT_NULL)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_digit_count(int nbr, t_varpro *varpro)
{
	long int	temp;
	int			count;

	count = 0;
	temp = nbr;
	if (temp <= 0)
		varpro->sign = 1;
	if (temp < 0)
	{
		temp *= -1;
		count++;
	}
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

int ft_digit_count_hexa(t_size_t hexa)
{
	int			count;

	count = 0;
	if (hexa == 0)
		return (1);
	while (hexa != 0)
	{
		hexa /= 16;
		count++;
	}
	return (count);
}

int ft_digit_count_unsigned(unsigned int nbr)
{
	int			count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
