/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:13:29 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:29:24 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;
extern t_op				g_op_tab[17];

void	ft_define_op(int (*ft_op[16])(t_process *proc))
{
	ft_op[0] = &ft_live;
	ft_op[1] = &ft_load;
	ft_op[2] = &ft_store;
	ft_op[3] = &ft_add;
	ft_op[4] = &ft_sub;
	ft_op[5] = &ft_and;
	ft_op[6] = &ft_or;
	ft_op[7] = &ft_xor;
	ft_op[8] = &ft_zjmp;
	ft_op[9] = &ft_ldi;
	ft_op[10] = &ft_store_i;
	ft_op[11] = &ft_fork;
	ft_op[12] = &ft_lld;
	ft_op[13] = &ft_lldi;
	ft_op[14] = &ft_lfork;
	ft_op[15] = &ft_aff;
}

int		ft_pc(int pc)
{
	pc = pc % MEM_SIZE;
	if (pc < 0)
		pc = MEM_SIZE + pc;
	else if (pc >= MEM_SIZE)
		pc -= MEM_SIZE;
	return (pc);
}

char	ft_is_reg(int pos)
{
	if (pos >= MEM_SIZE)
		pos = pos - MEM_SIZE;
	if (g_memory[pos] > 16 || !g_memory[pos])
		return (0);
	return (1);
}

void	ft_check_op(t_process *proc)
{
	if (g_memory[proc->pc] < 17 && g_memory[proc->pc])
	{
		proc->cycle = g_op_tab[g_memory[proc->pc] - 1].nb_cycle;
		proc->op_code = g_memory[proc->pc];
	}
}

void	ft_fill_reg(t_process *proc, int pos, int reg)
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
		proc->registre[reg][i] = g_memory[pos + i];
	}
}
