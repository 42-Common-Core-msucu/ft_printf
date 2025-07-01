/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_func_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:13:29 by msucu             #+#    #+#             */
/*   Updated: 2025/07/01 15:52:32 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

t_varpro	ft_reset_var(t_varpro varpro)
{
	ft_memset(varpro.flags, '\0', 6);
	varpro.width = 0;
	varpro.precision = 0;
	varpro.type = '0';
	varpro.is_precision = 0;
	varpro.var_format_len = 0;
	varpro.value_len = 0;
	varpro.writed = 0;
	varpro.fill_char = ' ';
	varpro.sign = -1;
	return (varpro);
}

int	ft_is_flag(t_varpro *varpro, char c)
{
	if (ft_strchr(varpro->flags, c))
		return (1);
	return (0);
}

int	ft_putchar_count(char c, int count, t_varpro *varpro, int add_writed)
{
	int	i;

	if (count <= 0)
		return (0);
	i = 0;
	while (i < count)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		i++;
	}
	if (add_writed == 1)
		varpro->writed += count;
	if (count != -1)
		return (count);
	return (1);
}

int	ft_putstr_count(char *str, int count, t_varpro *varpro, int add_writed)
{
	int	i;
	int	len;

	if (count <= 0)
		return (0);
	len = (int) ft_strlen(str);
	i = 0;
	while (i < count)
	{
		if (write(1, str, ft_strlen(str)) == -1)
			return (-1);
		i++;
	}
	if (add_writed == 1)
		varpro->writed += count * len;
	if (count * len != -1)
		return (count * len);
	return (1);
}

int	ft_putstr_max(char *str, int max)
{
	if (write(1, str, ft_min(max, ft_strlen(str))) == -1)
		return (-1);
	return (1);
}
