/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:31 by msucu             #+#    #+#             */
/*   Updated: 2025/06/24 21:47:34 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putunbr_fd(unsigned int nbr, int fd)
{
	char	c;

	if (nbr >= 10)
		ft_putunbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}
