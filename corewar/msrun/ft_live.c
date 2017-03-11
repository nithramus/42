/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:12:05 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:32:15 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;
t_joueur				*g_list_joueurs;

int		ft_live(t_process *proc)
{
	unsigned int	i;
	unsigned int	j;
	char			nb[4];

	++(proc->live);
	j = 5;
	while (--j)
		nb[4 - j] = g_memory[ft_pc(proc->pc + j)];
	i = (unsigned int)nb[0];
	j = -1;
	while (g_list_joueurs[++j].name)
		if (i == -j - 1)
		{
			++(g_list_joueurs[j].nb_live);
			g_list_joueurs[j].last_live = proc->atc_cycle;
			break ;
		}
	proc->pc = ft_pc(proc->pc + 5);
	ft_check_op(proc);
	return (-1);
}
