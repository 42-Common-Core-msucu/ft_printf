/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:50:44 by msucu             #+#    #+#             */
/*   Updated: 2025/06/26 18:59:21 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
	char isim[] = "Miraç";
	char soyisim[] = "SUCU";
	int	yas = 42;
	
	// ft_printf("|%5s|\n", "NULL");
	// printf("%d\n", printf("%s", NULL));
	printf("%d\n", ft_printf("|%010d|\n", 15));
	printf("%d\n", printf("|%010d|\n", 15));
	return (0);
}
