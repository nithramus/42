/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_ft4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:11:42 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:31:18 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_sti(unsigned char *str, int fd, int i)
{
	write(fd, "sti", 3);
	++i;
	if (str[i] == 0x54)
		return (fill_rrr(str, fd, i));
	if (str[i] == 0x58)
		return (fill_little_rrd(str, fd, i));
	if (str[i] == 0x64)
		return (fill_little_rdr(str, fd, i));
	if (str[i] == 0x68)
		return (fill_little_rdd(str, fd, i));
	if (str[i] == 0x74)
		return (fill_rir(str, fd, i));
	if (str[i] == 0x78)
		return (fill_little_rid(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}

int	fill_fork(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, "fork %", 6);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (2);
}

int	fill_lld(unsigned char *str, int fd, int i)
{
	write(fd, "lld ", 4);
	++i;
	if (str[i] == 0x90)
		return (fill_load_d(str, fd, i));
	if (str[i] == 0xd0)
		return (fill_load_i(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}

int	fill_lldi(unsigned char *str, int fd, int i)
{
	write(fd, "lldi", 4);
	++i;
	if (str[i] == 0x54)
		return (fill_rrr(str, fd, i));
	if (str[i] == 0x64)
		return (fill_little_rdr(str, fd, i));
	if (str[i] == 0x94)
		return (fill_little_drr(str, fd, i));
	if (str[i] == 0xa4)
		return (fill_little_ddr(str, fd, i));
	if (str[i] == 0xd4)
		return (fill_irr(str, fd, i));
	if (str[i] == 0xe4)
		return (fill_little_idr(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}
