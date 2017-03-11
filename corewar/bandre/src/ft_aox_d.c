/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aox_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:35:45 by msrun             #+#    #+#             */
/*   Updated: 2017/03/10 15:44:47 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char	*g_memory;

void	ft_ddr(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 10)] < 17 && g_memory[ft_pc(proc->pc + 10)])
	{
		ft_get_from_dir(tab1, ft_pc(proc->pc + 2));
		ft_get_from_dir(tab2, ft_pc(proc->pc + 6));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 10)] - 1]);
		proc->carry =
	(ft_dir_uint(proc->registre[g_memory[ft_pc(proc->pc + 10)] - 1])) ? 0 : 1;
	}
	proc->pc = ft_pc(proc->pc + 11);
}

void	ft_drr(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)] &&
			g_memory[ft_pc(proc->pc + 7)] < 17 && g_memory[ft_pc(proc->pc + 7)])
	{
		ft_get_from_dir(tab1, ft_pc(proc->pc + 2));
		ft_get_from_reg(tab2,
				proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 7)] - 1]);
		proc->carry =
	(ft_dir_uint(proc->registre[g_memory[ft_pc(proc->pc + 7)] - 1])) ? 0 : 1;
	}
	proc->pc = ft_pc(proc->pc + 8);
}

void	ft_dir(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 8)] < 17 && g_memory[ft_pc(proc->pc + 8)])
	{
		ft_get_from_dir(tab1, ft_pc(proc->pc + 2));
		ft_get_from_ind(tab2, ft_ind_eq_to(ft_pc(proc->pc + 6)));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 8)] - 1]);
		proc->carry =
	(ft_dir_uint(proc->registre[g_memory[ft_pc(proc->pc + 8)] - 1])) ? 0 : 1;
	}
	proc->pc = ft_pc(proc->pc + 9);
}
