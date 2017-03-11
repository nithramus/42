/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_little_op_comb2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:04:12 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:28:12 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_little_rdd(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (6);
}

int	fill_little_rid(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	++i;
	put_reg(str, fd, i);
	++i;
	write(fd, ", ", 2);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	i += 2;
	write(fd, ", %", 3);
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (6);
}
