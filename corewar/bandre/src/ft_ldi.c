/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:50:09 by msrun             #+#    #+#             */
/*   Updated: 2017/03/10 17:20:37 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void	ft_ldi_fill_reg(unsigned char *tab, unsigned char *reg)
{
	reg[0] = tab[0];
	reg[1] = tab[1];
	reg[2] = tab[2];
	reg[3] = tab[3];
}

int		ft_ind_eq_to2(int pos, unsigned char *mem)
{
	return (mem[pos] * 256 + mem[ft_pc(pos + 1)]);
}

void	ft_get_from_ind_ldi(unsigned char *tab, int pos)
{
	int	i;

	i = -1;
	while (++i < 4)
		tab[i] = g_memory[ft_pc(pos + i)];
}

int		ft_ldi(t_process *proc)
{
	void	(*ft_ldi[6])(t_process *proc);

	ft_define_op_ldi(ft_ldi);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 &&
			g_memory[ft_pc(proc->pc + 1)] <= 228 &&
			!((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 116 &&
			g_memory[ft_pc(proc->pc + 1)] != 132 &&
			g_memory[ft_pc(proc->pc + 1)] != 180 &&
			g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_ldi[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
			((g_memory[ft_pc(proc->pc + 1)] - 84) / 60) * 2](proc);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
	return (-1);
}

int		ft_lldi(t_process *proc)
{
	ft_ldi(proc);
	return (-1);
}
