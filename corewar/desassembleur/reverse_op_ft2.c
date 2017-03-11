/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_ft2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:08:57 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:31:37 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_st_i(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ", ", 2);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (4);
}

int	fill_st_r(unsigned char *str, int fd, int i)
{
	++i;
	put_reg(str, fd, i);
	write(fd, ",", 1);
	++i;
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (3);
}

int	fill_st(unsigned char *str, int fd, int i)
{
	write(fd, "st", 2);
	++i;
	if (str[i] == 0x70)
		return (fill_st_i(str, fd, i));
	if (str[i] == 0x50)
		return (fill_st_r(str, fd, i));
	write(fd, "\n", 1);
	return (2);
}

int	fill_add(unsigned char *str, int fd, int i)
{
	write(fd, "add", 3);
	++i;
	if (str[i] == 0x54)
	{
		++i;
		put_reg(str, fd, i);
		++i;
		write(fd, ",", 1);
		put_reg(str, fd, i);
		++i;
		write(fd, ",", 1);
		put_reg(str, fd, i);
		write(fd, "\n", 1);
		return (4);
	}
	write(fd, "\n", 1);
	return (2);
}

int	fill_sub(unsigned char *str, int fd, int i)
{
	write(fd, "sub", 3);
	++i;
	if (str[i] == 0x54)
	{
		++i;
		put_reg(str, fd, i);
		++i;
		write(fd, ",", 1);
		put_reg(str, fd, i);
		++i;
		write(fd, ",", 1);
		put_reg(str, fd, i);
		write(fd, "\n", 1);
		return (4);
	}
	write(fd, "\n", 1);
	return (2);
}
