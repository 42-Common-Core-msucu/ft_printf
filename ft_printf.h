/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:04:37 by msucu             #+#    #+#             */
/*   Updated: 2025/06/26 08:09:40 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FT_NULL 0

typedef struct s_varpro
{
	char	flags[6];
	int		width;
	int		precision;
	char	type;
	int		is_precision;
	int		var_len;
}	t_varpro;

int		ft_printf(const char *format, ...);
void	ft_putunbr_fd(unsigned int nbr, int fd);

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

#endif
