/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:08:41 by bandre            #+#    #+#             */
/*   Updated: 2017/03/09 17:08:30 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*g_list_process = NULL;
t_joueur	**g_list_joueurs = NULL;
unsigned char		*g_memory = NULL;

TTF_Font	*start_sdl(SDL_Surface **ecran)
{
	TTF_Font	*police;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	if (!(police = TTF_OpenFont("test.ttf", 15)))
		quit_clean(4);
	if (!(*ecran = SDL_SetVideoMode(1800, 1200, 32, SDL_HWSURFACE)))
		quit_clean(4);
	SDL_FillRect(*ecran, NULL, SDL_MapRGB((*ecran)->format, 0, 0, 0));
	return (police);
}
int		main(int argc, char **argv)
{
	int			winner;
	t_option	option;
	t_parse		*num_joueurs;
	SDL_Surface	*ecran;
	TTF_Font	*police;

	num_joueurs = parse_number(&(option.dump), &(option.visu), argc, argv);
	if (option.visu == 1)
		police = start_sdl(&ecran);
	if (!(g_memory = (unsigned char*)ft_strnew(sizeof(char) * (MEM_SIZE + 1))))
		quit_clean(1);
	if (!(g_list_joueurs = (t_joueur**)malloc(sizeof(t_joueur*))))
		quit_clean(1);
	*g_list_joueurs = NULL;
	recup_param(num_joueurs, ecran, option);
	boucle_principal(ecran, police, option);
	winner = show_winner(ecran, police, option);
	ft_printf("le joueur: %d a gagne:", g_list_joueurs[winner]->num_joueur);
	ft_putendl(g_list_joueurs[winner]->name);
	ft_putendl(g_list_joueurs[winner]->cri_de_guerre);
	quit_clean(5);
	return (0);
}
