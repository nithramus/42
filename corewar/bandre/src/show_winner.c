/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_winner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:44:12 by bandre            #+#    #+#             */
/*   Updated: 2017/03/09 17:14:37 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_joueur		**g_list_joueurs;

void	blit_text(SDL_Surface *ecran, SDL_Surface *text, int pc)
{
	SDL_Rect		position;

	position.x = (pc % 64) * 23;
	position.y = (pc / 64) * 18;
	SDL_BlitSurface(text, NULL, ecran, &position);
	SDL_FreeSurface(text);
}

void	sdl_color_init(SDL_Color *color)
{
	color->r = 255;
	color->g = 255;
	color->b = 255;
}

void	afficher_winner(SDL_Surface *ecran, TTF_Font *police, char *winner)
{
	SDL_Surface		*text;
	SDL_Color		white;
	SDL_Rect		position;

	sdl_color_init(&white);
	position.x = 1500;
	ft_putendl(winner);
	position.y = 700;
	text = TTF_RenderText_Blended(police, winner, white);
	SDL_BlitSurface(text, NULL, ecran, &position);
	SDL_Flip(ecran);
	SDL_FreeSurface(text);
}

int		show_winner(SDL_Surface *ecran, TTF_Font *police, t_option option)
{
	int			i;
	int			winner;
	SDL_Event	event;

	i = 0;
	winner = 0;
	while (g_list_joueurs[i])
	{
		if (g_list_joueurs[i]->last_live > g_list_joueurs[winner]->last_live)
			winner = i;
		i++;
	}
	if (option.visu == 1)
	{
		afficher_winner(ecran, police, g_list_joueurs[winner]->name);
		i = 1;
		while (i)
		{
			SDL_WaitEvent(&event);
			if (event.type == SDL_QUIT)
				i = 0;
		}
	}
	return (winner);
}
