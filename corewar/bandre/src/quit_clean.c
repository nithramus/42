/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:18:49 by bandre            #+#    #+#             */
/*   Updated: 2017/03/08 21:42:44 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_process		*g_list_process;
extern t_joueur			**g_list_joueurs;
extern unsigned char	*g_memory;

static void		free_process(void)
{
	t_process *tmp;

	tmp = g_list_process;
	while (tmp)
	{
		tmp = g_list_process->next;
		free(g_list_process);
		g_list_process = tmp;
	}
}

static void		free_joueur(void)
{
	int i;

	i = 0;
	while (g_list_joueurs[i])
	{
		free(g_list_joueurs[i]->cri_de_guerre);
		free(g_list_joueurs[i]);
		i++;
	}
	free(g_list_joueurs);
}

void			quit_clean(int error)
{
	if (error == 0)
		ft_putendl("Erreur lors de l'ouverture du fichier.");
	else if (error == 1)
		ft_putendl("Une allocation memoire a echoue.");
	else if (error == 2)
		ft_putendl("La ligne de commande n'est pas valide.");
	else if (error == 3)
		ft_putendl("Le fichier passe en parametres n'est pas valide.");
	else if (error == 4)
		ft_putendl("La bibliotheque SDL a rencontree une erreur.");
	if (g_list_process)
		free_process();
	if (g_list_joueurs)
		free_joueur();
	if (g_memory)
		free(g_memory);
	SDL_Quit();
	TTF_Quit();
	exit(0);
}
