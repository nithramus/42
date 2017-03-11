/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_comb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:58:42 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 14:00:55 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_rrr(unsigned char *str, int fd, int i)
{
	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, ",", 1);
	++i;
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (4);
}

int	fill_rdr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ", %", 3);
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (7);
}

int	fill_rir(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ", ", 2);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (5);
}

int	fill_drr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " %", 2);
	++i;
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	++i;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (7);
}

int	fill_ddr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " %", 2);
	++i;
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ", %", 3);
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (10);
}
