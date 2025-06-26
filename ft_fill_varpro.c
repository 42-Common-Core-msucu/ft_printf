#include "ft_printf.h"
#include "libft/libft.h"

int ft_fill_varpro(const char *format, t_varpro *varpro)
{
	int i;

	i = 0;
	i = ft_find_flags(format, varpro, i);
	i = ft_calculate_width(format, varpro, i);
	i = ft_calculate_precision(format, varpro, i);
	if (ft_strchr("cspdiuxX%", format[i]))
		varpro->type = format[i++];
	else
		return (-1);
	varpro->var_format_len = i;
	return (i);
}

int	ft_find_flags(const char *format, t_varpro *varpro, int i)
{
	while (ft_strchr("-0# +", format[i]))
	{
		varpro->flags[ft_strlen(varpro->flags)] = format[i];
		i++;
	}
	return (i);
}

int	ft_calculate_width(const char *format, t_varpro *varpro, int i)
{
	while (ft_isdigit(format[i]))
	{
		varpro->width *= 10;
		varpro->width += format[i] - '0';
		i++;
	}
	return (i);
}

int ft_calculate_precision(const char *format, t_varpro *varpro, int i)
{
	if (format[i] == '.')
	{
		i++;
		varpro->is_precision = 1;
		while (ft_isdigit(format[i]))
		{
			varpro->precision *= 10;
			varpro->precision += format[i] - '0';
			i++;
		}
	}
	return (i);
}
