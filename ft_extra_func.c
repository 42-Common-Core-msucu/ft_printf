#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

int ft_putchar_return(int c)
{
	write(1, &c, 1);
	return (1);
}

t_varpro ft_reset_var(t_varpro varpro)
{
	ft_memset(varpro.flags, '\0', 6);
	varpro.width = 0;
	varpro.precision = 0;
	varpro.type = '0';
	varpro.is_precision = 0;
	varpro.var_len = 0;
	return (varpro);
}
