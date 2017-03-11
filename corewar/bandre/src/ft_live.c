/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:12:05 by msrun             #+#    #+#             */
/*   Updated: 2017/03/11 16:08:37 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;
t_joueur				**g_list_joueurs;

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
	while (g_list_joueurs[++j])
		if (i == g_list_joueurs[j]->num_joueur)
		{
			++(g_list_joueurs[j]->nb_live);
			g_list_joueurs[j]->last_live = proc->act_cycle;
			break ;
		}
	proc->pc = ft_pc(proc->pc + 5);
	ft_check_op(proc);
	return (-1);
}
