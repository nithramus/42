/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:00:47 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:31:02 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;
t_process	*g_list_process;

void	ft_fork_reg_cpy(unsigned char reg[REG_NUMBER][REG_SIZE],
		unsigned char new_reg[REG_NUMBER][REG_SIZE])
{
	int	i;
	int	u;

	i = -1;
	while (++i < REG_NUMBER)
		u = -1;
	while (++u < REG_SIZE)
		new_reg[i][u] = reg[i][u];
}

int		ft_fork(t_process *proc)
{
	t_process	*new_proc;
	int			pos;

	if (!(new_proc = malloc(sizeof(t_process))))
		quit_clean(1);
	ft_fork_reg_cpy(proc->registre, new_proc->registre);
	new_proc->live = proc->live;
	new_proc->carry = proc->carry;
	if ((pos = ft_ind_eq_to(g_memory[ft_pc(proc->pc + 1)])) > 32767)
		pos -= 65536;
	g_memory[ft_pc(proc->pc)] == 12 ? pos = pos % IDX_MOD : pos;
	new_proc->pc = ft_pc(proc->pc + pos);
	new_proc->cycle = 0;
	new_proc->atc_cycle = 0;
	ft_check_op(new_proc);
	new_proc->next = g_list_process;
	new_proc->previous = 0;
	g_list_process = new_proc;
	proc->pc = ft_pc(proc->pc + 3);
	ft_check_op(proc);
	return (-1);
}

int	ft_lfork(t_process *proc)
{
	ft_fork(proc);
	return (-1);
}
