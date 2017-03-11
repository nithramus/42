/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:49:07 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 14:37:23 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

void	define_get_op(int (*get_op[16])(unsigned char *str, int fd, int i))
{
	get_op[0] = &fill_live;
	get_op[1] = &fill_load;
	get_op[2] = &fill_st;
	get_op[3] = &fill_add;
	get_op[4] = &fill_sub;
	get_op[5] = &fill_and;
	get_op[6] = &fill_or;
	get_op[7] = &fill_xor;
	get_op[8] = &fill_zjmp;
	get_op[9] = &fill_ldi;
	get_op[10] = &fill_sti;
	get_op[11] = &fill_fork;
	get_op[12] = &fill_lld;
	get_op[13] = &fill_lldi;
	get_op[14] = &fill_lfork;
	get_op[15] = &fill_aff;
}

void	fill_ops(unsigned char *str, int fd, int len)
{
	int	i;
	int	(*get_op[16])(unsigned char *str, int fd, int i);

	define_get_op(get_op);
	i = -1;
	write(fd, "\n", 1);
	while (++i < len)
	{
		if (str[i] && str[i] < 17)
			i += get_op[str[i] - 1](str, fd, i);
	}
}
