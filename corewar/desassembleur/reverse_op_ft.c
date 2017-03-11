/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:05:30 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:30:07 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_live(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, "live %", 6);
	++i;
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (4);
}

int	fill_load_d(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, "%", 1);
	++i;
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (6);
}

int	fill_load_i(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (4);
}

int	fill_load(unsigned char *str, int fd, int i)
{
	write(fd, "ld ", 3);
	++i;
	if (str[i] == 0x90)
		return (fill_load_d(str, fd, i));
	if (str[i] == 0xd0)
		return (fill_load_i(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}
