/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_par2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:46:50 by msrun             #+#    #+#             */
/*   Updated: 2017/03/10 15:42:05 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_ldi_irr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 2));
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
			ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->carry =
	(g_memory[proc->pc] == 14 &&
	ft_dir_uint(proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1])) ? 0 : 1;
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_idr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 2));
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 4), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		proc->carry =
	(g_memory[proc->pc] == 14 &&
	ft_dir_uint(proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1])) ? 0 : 1;
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_define_op_ldi(void (*ft_ldi[6])(t_process *proc))
{
	ft_ldi[0] = &ft_ldi_rrr;
	ft_ldi[1] = &ft_ldi_rdr;
	ft_ldi[2] = &ft_ldi_drr;
	ft_ldi[3] = &ft_ldi_ddr;
	ft_ldi[4] = &ft_ldi_irr;
	ft_ldi[5] = &ft_ldi_idr;
}
