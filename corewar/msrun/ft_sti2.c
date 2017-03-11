/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:58:11 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:52:15 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

int		ft_sti_rrd(t_process *proc)
{
	int	pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)])
	{
		pos = ft_ind_eq_to2(2,
				proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]) +
				ft_ind_eq_to2(ft_pc(proc->pc + 4), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	return (ft_pc(proc->pc + pos));
}

int		ft_sti_rdr(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to2(2,
				proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]) +
				ft_ind_eq_to2(ft_pc(proc->pc + 3), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	return (ft_pc(proc->pc + pos));
}

int		ft_sti_rdd(t_process *proc)
{
	int	pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)])
	{
		pos = ft_ind_eq_to2(ft_pc(proc->pc + 3), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 5), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	return (ft_pc(proc->pc + pos));
}

int		ft_sti_rir(t_process *proc)
{
	int	pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 3));
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
			ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	return (ft_pc(proc->pc + pos));
}

int		ft_sti_rid(t_process *proc)
{
	int	pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 3));
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 5), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	return (ft_pc(proc->pc + pos));
}
