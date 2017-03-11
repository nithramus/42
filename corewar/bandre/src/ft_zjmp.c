/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:42:36 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:35:13 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_zjmp(t_process *proc)
{
	int	pos;

	if (proc->carry == 1)
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 1));
		if (pos > 32767)
			pos = pos - 65536;
		pos = pos % IDX_MOD;
		proc->pc = ft_pc(proc->pc + pos);
	}
	else
		proc->pc = ft_pc(proc->pc + 3);
	ft_check_op(proc);
	return (-1);
}
