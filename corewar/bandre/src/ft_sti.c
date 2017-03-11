/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:55:54 by msrun             #+#    #+#             */
/*   Updated: 2017/03/10 17:20:46 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_sti_reg_pos(t_process *proc, int pos, unsigned char *reg)
{
	int	i;

	i = -1;
	while (++i < 4)
		g_memory[ft_pc(proc->pc + pos + i)] = reg[i];
}

int		ft_sti_rrr(t_process *proc)
{
	int	pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
		g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
		g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
	{
		pos = ft_ind_eq_to2(2,
				proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1])
		+ ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 5);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	return (ft_pc(proc->pc + pos - 5));
}

void	ft_define_op_sti(int (*ft_sti[6])(t_process *proc))
{
	ft_sti[0] = &ft_sti_rrr;
	ft_sti[1] = &ft_sti_rrd;
	ft_sti[2] = &ft_sti_rdr;
	ft_sti[3] = &ft_sti_rdd;
	ft_sti[4] = &ft_sti_rir;
	ft_sti[5] = &ft_sti_rid;
}

int		ft_store_i(t_process *proc)
{
	int		(*ft_sti[6])(t_process *proc);
	int		i;

	i = -1;
	ft_define_op_sti(ft_sti);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 &&
			g_memory[ft_pc(proc->pc + 1)] <= 120 &&
			!((g_memory[ft_pc(proc->pc + 1)] - 84) % 4) &&
			g_memory[ft_pc(proc->pc + 1)] != 92 &&
			g_memory[ft_pc(proc->pc + 1)] != 96 &&
			g_memory[ft_pc(proc->pc + 1)] != 108 &&
			g_memory[ft_pc(proc->pc + 1)] != 112)
	{
		i = ft_sti[((g_memory[ft_pc(proc->pc + 1)] - 84) / 4) -
			((g_memory[ft_pc(ft_pc(proc->pc + 1))] - 84) / 16 * 2)](proc);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (i);
}
