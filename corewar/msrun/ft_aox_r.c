/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aox_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:30:23 by msrun             #+#    #+#             */
/*   Updated: 2017/03/04 13:38:06 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_rrr(t_process *proc, void (*f)(unsigned char
			*tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)]
	&& g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
		g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
	{
		ft_get_from_reg(tab1,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		ft_get_from_reg(tab2,
				proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]);
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 5);
}

void	ft_rir(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		ft_get_from_reg(tab1,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		ft_get_from_ind(tab2,
				ft_ind_eq_to(ft_pc(proc->pc + 3)));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 6);
}

void	ft_rdr(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)]
	&& g_memory[ft_pc(proc->pc + 7)] < 17 && g_memory[ft_pc(proc->pc + 7)])
	{
		ft_get_from_reg(tab1,
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		ft_get_from_dir(tab2, ft_pc(proc->pc + 3));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 7)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 8);
}
