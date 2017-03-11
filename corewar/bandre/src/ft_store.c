/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:20:27 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 18:39:45 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void		ft_fill_reg_at_mem(t_process *proc, int pos, int reg)
{
	int	i;

	if (pos < 0)
		pos += MEM_SIZE;
	pos = pos % MEM_SIZE;
	i = -1;
	while (++i < 4)
	{
		if (pos + i >= MEM_SIZE)
			pos = -i;
		g_memory[pos + i] = proc->registre[reg][i];
	}
}

static int	ft_store_at_i(t_process *proc)
{
	int	mod;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)])
	{
		mod = g_memory[ft_pc(proc->pc + 3)] * 256 +
			g_memory[ft_pc(proc->pc + 4)];
		if (mod > 32767)
			mod = mod - 65536;
		ft_fill_reg_at_mem(proc, ft_pc(proc->pc + mod),
				g_memory[ft_pc(proc->pc + 2)] - 1);
	}
	return (ft_pc(proc->pc + mod));
}

static void	ft_store_r(t_process *proc)
{
	int	i;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)])
	{
		i = -1;
		while (++i < 4)
			proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1][i] =
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1][i];
	}
}

int			ft_store(t_process *proc)
{
	int	i;

	i = -1;
	if (g_memory[ft_pc(proc->pc + 1)] == 112)
	{
		i = ft_store_at_i(proc);
		proc->pc = ft_pc(proc->pc + 5);
	}
	else if (g_memory[ft_pc(proc->pc + 1)] == 80)
	{
		ft_store_r(proc);
		proc->pc = ft_pc(proc->pc + 4);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (i);
}
