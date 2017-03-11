/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:38:24 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:45:11 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_define_op_aox(void (*ft_aox[9])(t_process *proc,
	void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)))
{
	ft_aox[0] = &ft_rrr;
	ft_aox[1] = &ft_rdr;
	ft_aox[2] = &ft_rir;
	ft_aox[3] = &ft_drr;
	ft_aox[4] = &ft_ddr;
	ft_aox[5] = &ft_dir;
	ft_aox[6] = &ft_irr;
	ft_aox[7] = &ft_idr;
	ft_aox[8] = &ft_iir;
}

int		ft_and(t_process *proc)
{
	void	(*ft_aox[9])(t_process *proc,

	void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
	ft_define_op_aox(ft_aox);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 &&
			g_memory[ft_pc(proc->pc + 1)] <= 244 &&
			!((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 132 &&
			g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_aox[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
		((g_memory[ft_pc(proc->pc + 1)] - 84) / 48)](proc, &ft_and_fill_reg);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}

int		ft_or(t_process *proc)
{
	void	(*ft_aox[9])(t_process *proc,

	void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
	ft_define_op_aox(ft_aox);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 &&
			g_memory[ft_pc(proc->pc + 1)] <= 244 &&
			!((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 132 &&
			g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_aox[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
		((g_memory[ft_pc(proc->pc + 1)] - 84) / 48)](proc, &ft_or_fill_reg);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}

int		ft_xor(t_process *proc)
{
	void	(*ft_aox[9])(t_process *proc,

	void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
	ft_define_op_aox(ft_aox);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 &&
			g_memory[ft_pc(proc->pc + 1)] <= 244 &&
			!((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 132 &&
			g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_aox[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
		((g_memory[ft_pc(proc->pc + 1)] - 84) / 48)](proc, &ft_xor_fill_reg);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}
