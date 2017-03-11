/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_principal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:05:05 by bandre            #+#    #+#             */
/*   Updated: 2017/03/11 18:06:43 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_process				*g_list_process;
extern t_joueur					**g_list_joueurs;
extern unsigned char			*g_memory;

void			list_process(void)
{
	t_process	*process;

	process = g_list_process;
	while (process)
	{
		if (process->op_code == 0)
		{
			ft_check_op(process);
			if (process->op_code == 0)
			{
				process->pc++;
				process->pc = process->pc % MEM_SIZE;
			}
		}
		process = process->next;
	}
}

int				count_live(void)
{
	t_process	*process;
	int			nb_live;

	nb_live = 0;
	process = g_list_process;
	while (process)
	{
		nb_live += process->live;
		if (nb_live >= NBR_LIVE)
			return (1);
		process = process->next;
	}
	return (0);
}

void			test_live(void)
{
	t_process	*process;
	t_process	*tmp;

	process = g_list_process;
	while (process)
	{
		if (process->live == 0)
		{
			if (process->previous)
				process->previous->next = process->next;
			else
				g_list_process = process->next;
			if (process->next)
				process->next->previous = process->previous;
			tmp = process;
			process = process->next;
			free(tmp);
		}
		else
		{
			process->live = 0;
			process = process->next;
		}
	}
}

static void		op_pross(int (*ft_op[16])(t_process *proc),
		SDL_Surface *ecran, TTF_Font *police, int visu, int cycle)
{
	t_process	*process;
	int			retour;

	process = g_list_process;
	while (process)
	{
		if (process->cycle == 0 && process->op_code > 0
				&& process->op_code < 17)
		{
			process->act_cycle = cycle;
			retour = ft_op[process->op_code - 1](process);
			if (retour != -1 && visu == 1)
				affichage_mem_change(ecran, police,
						process->num_joueur, retour);
		}
		else
			process->cycle--;
		process = process->next;
	}
}

int				boucle_principal(SDL_Surface *ecran,
		TTF_Font *police, t_option option)
{
	int			cycles;
	int			cycles_to_die;
	int			checks;
	int			((*ft_op[16])(t_process *proc));
	int			total_cycles;

	ft_define_op(ft_op);
	list_process();
	op_pross(ft_op, ecran, police, option.visu, cycles);
	cycles = CYCLE_TO_DIE;
	total_cycles = 0;
	cycles_to_die = CYCLE_TO_DIE;
	checks = 0;
	if (option.visu == 1)
		affichage(ecran, police, cycles);
	while (cycles_to_die > 0 && g_list_process)
	{
		if (total_cycles == option.dump)
			print_memory();
		gestion_cycles(&cycles, option, &cycles_to_die, &checks);
		op_pross(ft_op, ecran, police, option.visu, total_cycles);
		cycles--;
		total_cycles++;
		list_process();
		if (gestion_event(option, total_cycles, ecran, police) == 0)
			return (1);
	}
	return (1);
}
