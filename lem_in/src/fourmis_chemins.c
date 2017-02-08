/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmis_chemins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 23:47:46 by bandre            #+#    #+#             */
/*   Updated: 2017/02/06 19:02:56 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			calc_len_road(t_path *path)
{
	int i;

	i = 0;
	while (path->path[i])
		i++;
	i--;
	return (i);
}

static int			nb_fourmis_in_path(t_path **list_road, int nb_fourmis)
{
	int nb_road;
	int len_road;
	int fourmis_arrive;
	int nb_tour;

	fourmis_arrive = 0;
	nb_road = 0;
	len_road = 0;
	nb_tour = 0;
	while (fourmis_arrive < nb_fourmis)
	{
		nb_road = 0;
		while (list_road[nb_road] && fourmis_arrive < nb_fourmis)
		{
			len_road = calc_len_road(list_road[nb_road]);
			if (nb_tour >= len_road)
			{
				list_road[nb_road]->nb_fourmis += 1;
				fourmis_arrive++;
			}
			nb_road++;
		}
		nb_tour++;
	}
	return (nb_tour--);
}

static t_fourmis	**add_fourmis(t_fourmis **list, t_path **best_path)
{
	int			i;
	t_fourmis	**new;
	int			nbfour;

	nbfour = 0;
	while (list[nbfour])
		nbfour++;
	i = 0;
	while (best_path[i])
	{
		if (best_path[i]->nb_fourmis > 0)
		{
			new = t_fourmis_join(list, new_fourmis(best_path[i], 1 + nbfour));
			free(list);
			list = new;
			best_path[i]->nb_fourmis--;
			nbfour++;
		}
		i++;
	}
	return (list);
}

static int			affichage_final(t_fourmis **list_fourmis)
{
	int i;
	int cont;

	cont = 0;
	i = 0;
	while (list_fourmis[i])
	{
		if (list_fourmis[i]->move)
		{
			if (list_fourmis[i]->road->path[list_fourmis[i]->pos + 1])
			{
				ft_printf("L%d-%s ", list_fourmis[i]->num_fourmis,
						list_fourmis[i]->road
						->path[list_fourmis[i]->pos + 1]->name);
				list_fourmis[i]->pos++;
				cont = 1;
			}
			else
				list_fourmis[i]->move = 0;
		}
		i++;
	}
	if (cont)
		ft_printf("\n");
	return (cont);
}

int					fourmis_chemins(t_path **best_path, int nb_fourmis)
{
	t_fourmis	**list_fourmis;
	int			i;
	int			nb_road;

	nb_road = 0;
	while (best_path[nb_road])
		nb_road++;
	i = 0;
	nb_fourmis_in_path(best_path, nb_fourmis);
	if (!(list_fourmis = (t_fourmis**)malloc(sizeof(t_fourmis*) *
					(nb_fourmis + 1))))
		afficher_error();
	*list_fourmis = NULL;
	list_fourmis = add_fourmis(list_fourmis, best_path);
	while (list_fourmis[i])
		i++;
	while (affichage_final(list_fourmis))
		list_fourmis = add_fourmis(list_fourmis, best_path);
	ft_free_t_fourmis(list_fourmis);
	return (0);
}
