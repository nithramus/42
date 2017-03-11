/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:54:44 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:00:40 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

unsigned int	dir_uint(unsigned char *str)
{
	unsigned int	nb;

	nb = str[0] * 256 * 256 * 256;
	nb += str[1] * 256 * 256;
	nb += str[2] * 256;
	nb += str[3];
	return (nb);
}

unsigned int	ind_uint(unsigned char *str)
{
	unsigned int	nb;

	nb = str[0] * 256;
	nb += str[1];
	return (nb);
}

void			put_reg(unsigned char *str, int fd, int i)
{
	write(fd, " r", 2);
	ft_putnbr_fd(str[i], fd);
}
