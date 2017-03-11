/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:34:47 by bandre            #+#    #+#             */
/*   Updated: 2017/03/11 18:05:04 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char *g_memory;

void		affichage_mem_change(SDL_Surface *ecran, TTF_Font *police,
		int num_joueur, int pc)
{
	SDL_Surface		*texte;
	SDL_Color		white;
	char			*ito;
	char			*tmp;
	int				i;

	sdl_color_init(&white);
	i = (pc + 4) % MEM_SIZE;
	color_change(pc, 4, ecran, num_joueur);
	while (pc != i)
	{
		if (!(ito = ft_itoa_base((unsigned char)g_memory[pc], 16, 1)))
			quit_clean(1);
		if (ft_strlen(ito) < 2)
		{
			tmp = ito;
			ito = ft_strjoin("0", ito);
			free(tmp);
		}
		texte = TTF_RenderText_Blended(police, ito, white);
		free(ito);
		blit_text(ecran, texte, pc);
		pc++;
		pc = pc % MEM_SIZE;
	}
}

void		color_change(int pc, int nb, SDL_Surface *ecran, int num_joueur)
{
	SDL_Rect	rect;
	int			i;

	i = pc;
	rect.w = 23;
	rect.h = 18;
	while (i != (pc + nb) % MEM_SIZE)
	{
		rect.x = (i % 64) * 23;
		rect.y = (i / 64) * 18;
		if (num_joueur == 0)
			SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 255, 0, 0));
		if (num_joueur == 1)
			SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 0, 255, 0));
		if (num_joueur == 2)
			SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 155, 90, 255));
		if (num_joueur == 3)
			SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 255, 125, 0));
		i++;
		i = i % MEM_SIZE;
	}
}

void		affichage(SDL_Surface *ecran, TTF_Font *police, int cycles)
{
	SDL_Surface		*texte;
	SDL_Color		white;
	char			*ito;
	char			*tmp;
	int				i;

	sdl_color_init(&white);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (!(ito = ft_itoa_base((unsigned char)g_memory[i], 16, 1)))
			quit_clean(1);
		if (ft_strlen(ito) < 2)
		{
			tmp = ito;
			ito = ft_strjoin("0", ito);
			free(tmp);
		}
		texte = TTF_RenderText_Blended(police, ito, white);
		free(ito);
		blit_text(ecran, texte, i);
		i++;
	}
}

SDL_Rect	rect_noir(int w, int h, int x, int y)
{
	SDL_Rect rect;

	rect.w = w;
	rect.h = h;
	rect.x = x;
	rect.y = y;
	return (rect);
}

void		afficher_cycles(SDL_Surface *ecran, TTF_Font *police, int cycles)
{
	SDL_Surface		*text;
	char			*value;
	SDL_Color		white;
	SDL_Rect		position;
	SDL_Rect		rect;

	sdl_color_init(&white);
	rect = rect_noir(100, 50, 1500, 400);
	SDL_FillRect(ecran, &rect, SDL_MapRGB(ecran->format, 0, 0, 0));
	if (!(value = ft_itoa_base(cycles, 10, 0)))
		quit_clean(1);
	text = TTF_RenderText_Blended(police, "Cycles:", white);
	position.x = 1500;
	position.y = 400;
	SDL_BlitSurface(text, NULL, ecran, &position);
	SDL_FreeSurface(text);
	text = TTF_RenderText_Blended(police, value, white);
	position.x = 1550;
	SDL_BlitSurface(text, NULL, ecran, &position);
	SDL_FreeSurface(text);
	free(value);
}
