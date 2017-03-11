/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_ft3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:10:15 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:31:58 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_and(unsigned char *str, int fd, int i)
{
	write(fd, "and", 3);
	++i;
	if (str[i] == 0x54)
		return (fill_rrr(str, fd, i));
	if (str[i] == 0x64)
		return (fill_rdr(str, fd, i));
	if (str[i] == 0x74)
		return (fill_rir(str, fd, i));
	if (str[i] == 0x94)
		return (fill_drr(str, fd, i));
	if (str[i] == 0xa4)
		return (fill_ddr(str, fd, i));
	if (str[i] == 0xb4)
		return (fill_dir(str, fd, i));
	if (str[i] == 0xd4)
		return (fill_irr(str, fd, i));
	if (str[i] == 0xe4)
		return (fill_idr(str, fd, i));
	if (str[i] == 0xf4)
		return (fill_iir(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}

int	fill_or(unsigned char *str, int fd, int i)
{
	write(fd, "or", 2);
	++i;
	if (str[i] == 0x54)
		return (fill_rrr(str, fd, i));
	if (str[i] == 0x64)
		return (fill_rdr(str, fd, i));
	if (str[i] == 0x74)
		return (fill_rir(str, fd, i));
	if (str[i] == 0x94)
		return (fill_drr(str, fd, i));
	if (str[i] == 0xa4)
		return (fill_ddr(str, fd, i));
	if (str[i] == 0xb4)
		return (fill_dir(str, fd, i));
	if (str[i] == 0xd4)
		return (fill_irr(str, fd, i));
	if (str[i] == 0xe4)
		return (fill_idr(str, fd, i));
	if (str[i] == 0xf4)
		return (fill_iir(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}

int	fill_xor(unsigned char *str, int fd, int i)
{
	write(fd, "xor", 3);
	++i;
	if (str[i] == 0x54)
		return (fill_rrr(str, fd, i));
	if (str[i] == 0x64)
		return (fill_rdr(str, fd, i));
	if (str[i] == 0x74)
		return (fill_rir(str, fd, i));
	if (str[i] == 0x94)
		return (fill_drr(str, fd, i));
	if (str[i] == 0xa4)
		return (fill_ddr(str, fd, i));
	if (str[i] == 0xb4)
		return (fill_dir(str, fd, i));
	if (str[i] == 0xd4)
		return (fill_irr(str, fd, i));
	if (str[i] == 0xe4)
		return (fill_idr(str, fd, i));
	if (str[i] == 0xf4)
		return (fill_iir(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}

int	fill_zjmp(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, "zjmp %", 6);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (2);
}

int	fill_ldi(unsigned char *str, int fd, int i)
{
	write(fd, "ldi", 3);
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
