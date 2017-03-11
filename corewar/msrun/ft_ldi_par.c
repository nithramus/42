/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_par.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:45:06 by msrun             #+#    #+#             */
/*   Updated: 2017/03/04 17:57:10 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_ldi_rrr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
		g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
		g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
	{
		pos = ft_ind_eq_to2(2,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1])
		+ ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		proc->pc = ft_pc(proc->pc + 5);
		proc->carry = 1;
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_rdr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to2(2,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1])
				+ ft_ind_eq_to2(ft_pc(proc->pc + 3), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
		proc->carry = 1;
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_drr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to2(2,
				proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1])
				+ ft_ind_eq_to2(ft_pc(proc->pc + 2), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
		proc->carry = 1;
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_ddr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
	{
		pos = ft_ind_eq_to2(ft_pc(proc->pc + 2), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 4), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
		proc->carry = 1;
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}
