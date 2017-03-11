/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:50:00 by bandre            #+#    #+#             */
/*   Updated: 2017/03/11 15:54:13 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char			*g_memory;
extern t_process	*g_list_process;
extern t_joueur		**g_list_joueurs;

static void		put_in_memory(int fd, int nb_joueurs, int nb_joueur)
{
	int		result;
	char	buff[CHAMP_MAX_SIZE + 1];
	int		i;

	i = 0;
	result = read(fd, buff, CHAMP_MAX_SIZE + 1);
	if (result <= 0 || result > CHAMP_MAX_SIZE)
		quit_clean(3);
	buff[CHAMP_MAX_SIZE] = '\0';
	while (i <= result)
	{
		g_memory[i + ((MEM_SIZE / nb_joueurs) * (nb_joueur))
			% MEM_SIZE] = buff[i];
		i++;
	}
}

static void		put_in_memory_draw(int fd, int nb_joueurs,
		int nb_joueur, SDL_Surface *ecran)
{
	int		result;
	char	buff[CHAMP_MAX_SIZE + 1];
	int		i;

	i = 0;
	result = read(fd, buff, CHAMP_MAX_SIZE + 1);
	if (result <= 0 || result > CHAMP_MAX_SIZE)
		quit_clean(3);
	buff[CHAMP_MAX_SIZE] = '\0';
	while (i <= result)
	{
		g_memory[i + ((MEM_SIZE / nb_joueurs) * (nb_joueur))
			% MEM_SIZE] = buff[i];
		i++;
	}
	color_change(((MEM_SIZE / nb_joueurs) * (nb_joueur))
			% MEM_SIZE, result, ecran, nb_joueur);
}

static void		create_process(int nb_joueurs, int r1, int nb_joueur)
{
	t_process *tmp;

	tmp = new_t_process(r1, nb_joueurs, g_list_process, NULL);
	tmp->pc = ((MEM_SIZE / nb_joueurs) * (nb_joueur)) % MEM_SIZE;
	tmp->num_joueur = nb_joueur;
	if (g_list_process)
		g_list_process->previous = tmp;
	g_list_process = tmp;
}

static int		nombres_joueurs(t_parse *joueurs)
{
	int i;

	i = 0;
	while (joueurs[i].fichier && i < 4)
		i++;
	return (i);
}

int				recup_param(t_parse *num_joueurs,
		SDL_Surface *ecran, t_option option)
{
	int		i;
	int		fd;

	i = 3;
	while (i >= 0)
	{
		if (num_joueurs[i].fichier)
		{
			if ((fd = open(num_joueurs[i].fichier, O_RDONLY)) == -1)
				quit_clean(0);
			test_valide(fd, num_joueurs[i].num);
			if (option.visu == 1)
				put_in_memory_draw(fd, nombres_joueurs(num_joueurs), i, ecran);
			else
				put_in_memory(fd, nombres_joueurs(num_joueurs), i);
			create_process(nombres_joueurs(num_joueurs), num_joueurs[i].num, i);
		}
		i--;
	}
	free(num_joueurs);
	i = 0;
	return (0);
}
