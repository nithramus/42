/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:18:00 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:31:49 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

static void	ft_load_i(t_process *proc)
{
	int	mod;

	if (ft_is_reg(ft_pc(proc->pc + 4)))
	{
		mod = g_memory[ft_pc(proc->pc + 2)] * 256 +
			g_memory[ft_pc(proc->pc + 3)];
		if (mod > 32767)
			mod = mod - 65536;
		g_memory[proc->pc] == 2 ? mod = mod % IDX_MOD : mod;
		ft_fill_reg(proc, ft_pc(proc->pc + mod % IDX_MOD),
				g_memory[ft_pc(proc->pc + 4)] - 1);
		proc->carry = 1;
	}
}

static void	ft_load_d(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 6)] < 17 &&
			g_memory[ft_pc(proc->pc + 6)])
	{
		ft_fill_reg(proc, ft_pc(proc->pc + 2),
				g_memory[ft_pc(proc->pc + 6)] - 1);
		proc->carry = 1;
	}
}

int			ft_load(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 1)] == 144)
	{
		ft_load_d(proc);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else if (g_memory[ft_pc(proc->pc + 1)] == 208)
	{
		ft_load_i(proc);
		proc->pc = ft_pc(proc->pc + 5);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}

int			ft_lld(t_process *proc)
{
	ft_load(proc);
	return (-1);
}
