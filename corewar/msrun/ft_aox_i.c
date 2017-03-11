/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aox_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:33:43 by msrun             #+#    #+#             */
/*   Updated: 2017/03/04 13:29:41 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_irr(t_process *proc, void (*f)(unsigned char
			*tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		ft_get_from_ind(tab1, ft_ind_eq_to(ft_pc(proc->pc + 2)));
		ft_get_from_reg(tab2,
				proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 6);
}

void	ft_idr(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 8)] < 17 && g_memory[ft_pc(proc->pc + 8)])
	{
		ft_get_from_ind(tab1, ft_ind_eq_to(ft_pc(proc->pc + 2)));
		ft_get_from_dir(tab2, ft_pc(proc->pc + 4));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 8)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 9);
}

void	ft_iir(t_process *proc, void (*f)(unsigned char *tab1,
			unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
	{
		ft_get_from_ind(tab1, ft_ind_eq_to(ft_pc(proc->pc + 2)));
		ft_get_from_ind(tab2, ft_ind_eq_to(ft_pc(proc->pc + 4)));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 7);
}
