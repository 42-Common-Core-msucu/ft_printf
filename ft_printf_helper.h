/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:37 by msucu             #+#    #+#             */
/*   Updated: 2025/06/30 18:23:02 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPER_H
# define FT_PRINTF_HELPER_H

# include "libft/libft.h"
# include <stdarg.h>

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

// ft_printf.c
int			ft_handvar(va_list args, const char *format, t_varpro *varpro);
int			ft_var_check(const char *format, va_list args,
				t_varpro *varpro, int *w);
int			ft_format_check(const char **format, va_list args,
				t_varpro *varpro, int *w);
int			ft_printf(const char *format, ...);

// ft_fill_varpro.c
int			ft_fill_varpro(const char *format, t_varpro *varpro);
int			ft_find_flags(const char *format, t_varpro *varpro, int i);
int			ft_calculate_width(const char *format, t_varpro *varpro, int i);
int			ft_calculate_precision(const char *format, t_varpro *varpro, int i);

// ft_calculate_len.c
void		ft_calculate_len(va_list args, t_varpro *varpro);
int			ft_str_count(char *str, t_varpro *varpro);
int			ft_digit_count(int nbr, t_varpro *varpro);
int			ft_digit_count_hexa(t_size_t hexa, t_varpro *varpro);
int			ft_digit_count_unsigned(unsigned int nbr, t_varpro *varpro);

// ft_extra_func.c
t_varpro	ft_reset_var(t_varpro varpro);
int			ft_is_flag(t_varpro *varpro, char c);
int			ft_putchar_count(char c, int count,
				t_varpro *varpro, int add_writed);
int			ft_putstr_count(char *str, int count,
				t_varpro *varpro, int add_writed);
int			ft_putstr_max(char *str, int max);

// ft_extra_func_2.c
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_putnbr(int nbr);
int			ft_putunbr(unsigned int n);
int			ft_putnbr_hexa(t_size_t n, int is_upper);

// ft_putvar.c
int			ft_putvar(va_list args, t_varpro *varpro);
int			ft_dash_check(va_list args, t_varpro *varpro, int zc, int sp);
int			ft_putvar_arg(va_list args, t_varpro *varpro);

// ft_putvar_helper.c
int			ft_putvar_nbr(int n, t_varpro *varpro);
int			ft_putvar_unbr(unsigned int n, t_varpro *varpro);
int			ft_putvar_str(char *str, t_varpro *varpro);
int			ft_putvar_p(t_size_t p, t_varpro *varpro);
int			ft_putvar_x(t_size_t x, t_varpro *varpro);

// ft_putvar_helper_2.c
void		ft_fill_val_pre(t_varpro *varpro, int n);
void		ft_putvar_check(t_varpro *varpro);
void		ft_putvar_check_2(t_varpro *varpro, int *sc);
int			ft_putvar_put_extra(t_varpro *varpro);

#endif
