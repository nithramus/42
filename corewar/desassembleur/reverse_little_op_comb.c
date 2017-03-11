/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_little_op_comb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:02:55 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:28:43 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_little_rdr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (5);
}

int	fill_little_drr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " %", 2);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	++i;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (5);
}

int	fill_little_ddr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " %", 2);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (6);
}

int	fill_little_idr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " ", 1);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (6);
}

int	fill_little_rrd(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	++i;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (5);
}
