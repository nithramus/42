/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op_ft5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:12:30 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:30:58 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

int	fill_lfork(unsigned char *str, int fd, int i)
{
	unsigned int	nb;

	write(fd, "lfork %", 7);
	++i;
	nb = ind_uint(str + i);
	ft_putunbr_fd(nb, fd);
	write(fd, "\n", 1);
	return (2);
}

int	fill_aff(unsigned char *str, int fd, int i)
{
	write(fd, "aff ", 4);
	i += 2;
	put_reg(str, fd, i);
	write(fd, "\n", 1);
	return (2);
}
