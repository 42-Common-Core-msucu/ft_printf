/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:50:44 by msucu             #+#    #+#             */
/*   Updated: 2025/06/27 23:51:52 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>

int main(void)
{
	char *str = NULL;
	ft_printf("%s\n",str);
	printf("%s\n",str);

	return (0);
}