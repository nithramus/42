/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmis_chemins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 23:47:46 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 20:58:26 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		calc_len_road(f_path *path)
{
	int i;

	i = 0;
	while (path->path[i])
		i++;
	i--;
	return (i);
}

static int		nb_fourmis_in_path(f_path **list_road, int nb_fourmis)
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
	nb_tour--;
	return (nb_tour);
}

static s_fourmis	*new_fourmis(f_path *road, int num_fourmis)
{
	s_fourmis *new;

	if (!(new = (s_fourmis*)malloc(sizeof(s_fourmis))))
		afficher_error();
	new->pos = 0;
	new->road = road;
	new->num_fourmis = num_fourmis;
	new->move = 1;
	return (new);
}

static s_fourmis	**s_fourmis_join(s_fourmis **list, s_fourmis *new)
{
	int i;
	s_fourmis **new_list;

	i = 0;
	while (list[i])
		i++;
	if (!(new_list = (s_fourmis**)malloc(sizeof(s_fourmis*) * (i + 2))))
		afficher_error();
	i = 0;
	while (list[i])
	{
		new_list[i] = list[i];
		i++;
	}
	new_list[i] = new;
	new_list[i + 1] = NULL;
	return (new_list);
}

static s_fourmis	**add_fourmis(s_fourmis **list, f_path **best_path)
{
	int			i;
	s_fourmis	**new;

	i = 0;
	while (best_path[i])
	{
		if (best_path[i]->nb_fourmis > 0)
		{
			new = s_fourmis_join(list, new_fourmis(best_path[i], i + 1));
			free(list);
			list = new;
			best_path[i]->nb_fourmis--;
		}
		i++;
	}
	return (list);
}

static int		affichage_final(s_fourmis **list_fourmis)
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
				ft_printf("L%s-%s ",
						list_fourmis[i]->road->path[list_fourmis[i]->pos]->name,
						list_fourmis[i]->road->path[list_fourmis[i]->pos + 1]->name);
				list_fourmis[i]->pos++;
				cont = 1;
			}
			else
				list_fourmis[i]->move = 0;
		}
		i++;
	}
	ft_printf("\n");
	return (cont);
}

int		fourmis_chemins(f_path **best_path, int nb_fourmis)
{
	s_fourmis	**list_fourmis;
	int			i;
	int			nb_road;

	nb_road = 0;
	while (best_path[nb_road])
		nb_road++;
	i = 0;
	nb_fourmis_in_path(best_path, nb_fourmis);
	if (!(list_fourmis = (s_fourmis**)malloc(sizeof(s_fourmis*) * (nb_fourmis + 1))))
		afficher_error();
	*list_fourmis = NULL;
	list_fourmis = add_fourmis(list_fourmis, best_path);
	ft_putendl("test");
	while (list_fourmis[i])
	{
		ft_printf("%s\n", list_fourmis[i]->road->path[1]->name);
		ft_putendl("test");
		i++;
	}
	while (affichage_final(list_fourmis))
		list_fourmis = add_fourmis(list_fourmis, best_path);
	ft_free_s_fourmis(list_fourmis);
	return (0);
}
