#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_print_varpro(t_varpro *varpro)
{
	printf("----- varpro ------\n");
	printf("Flags: %s\n", varpro->flags);
	printf("Is precision: %d\n", varpro->is_precision);
	printf("Precision: %d\n", varpro->precision);
	printf("Width: %d\n", varpro->width);
	printf("Type: %c\n", varpro->type);
	printf("Value Len: %d\n", varpro->value_len);
	printf("Variable format: %d\n", varpro->var_format_len);
	printf("Writed: %d\n", varpro->writed);
}
