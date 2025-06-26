/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:37 by msucu             #+#    #+#             */
/*   Updated: 2025/06/26 18:47:03 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

# define FT_NULL 0

typedef struct s_varpro
{
	char	flags[6];
	int		width;
	int		precision;
	char	type;
	int		is_precision;
	int		var_format_len;
	int		value_len;
	int		writed;
	char	fill_char;
	int		sign;
}	t_varpro;

int		ft_printf(const char *format, ...);
void	ft_putunbr_fd(unsigned int nbr, int fd);
int ft_max(int a, int b);
int	ft_putchar_count(char c, int count, t_varpro *varpro);
int	ft_putstr_count(char *str, int count, t_varpro *varpro);
void	ft_putvar_arg(va_list args, t_varpro *varpro);
void	ft_putvar_nbr(int n, t_varpro *varpro);

// temp_func.c
void	ft_print_varpro(t_varpro *varpro);

// ft_extra_func.c
int ft_putchar_return(int c);
t_varpro ft_reset_var(t_varpro varpro);

// ft_fill_varpro.c
int ft_fill_varpro(const char *format, t_varpro *varpro);
int	ft_find_flags(const char *format, t_varpro *varpro, int i);
int	ft_calculate_width(const char *format, t_varpro *varpro, int i);
int ft_calculate_precision(const char *format, t_varpro *varpro, int i);

// ft_calculate_len.c
void	ft_calculate_len(va_list args, t_varpro *varpro);
int ft_str_count(char *str);
int ft_digit_count(int nbr, t_varpro *varpro);
int ft_digit_count_hexa(t_size_t hexa);
int ft_digit_count_unsigned(unsigned int nbr);

// ft_putvar.c
int	ft_putvar(va_list args, t_varpro *varpro);

#endif
