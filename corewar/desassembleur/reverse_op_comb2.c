/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_comb2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:00:11 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:30:37 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_dir(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " %", 2);
	++i;
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ", ", 2);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (8);
}

int	fill_irr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " ", 1);
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

int	fill_idr(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " ", 1);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ", %", 3);
	nb = dir_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 4;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (8);
}

int	fill_iir(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, " ", 1);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ", ", 2);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ",", 1);
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (6);
}
