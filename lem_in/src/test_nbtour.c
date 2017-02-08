/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbtour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:04:15 by bandre            #+#    #+#             */
/*   Updated: 2017/02/06 22:41:55 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	calc_len_road(t_path *path)
{
	int i;

	i = 0;
	while (path->path[i])
		i++;
	i--;
	return (i);
}

int			test_nbtour(t_path **list_road, int nb_fourmis)
{
	int nb_road;
	int len_road;
	int fourmis_arrive;
	int nb_tour;

	fourmis_arrive = 0;
	nb_road = 0;
	len_road = 0;
	nb_tour = 0;
	while (fourmis_arrive <= nb_fourmis)
	{
		nb_road = 0;
		while (list_road[nb_road])
		{
			len_road = calc_len_road(list_road[nb_road]);
			if (nb_tour >= len_road)
				fourmis_arrive++;
			nb_road++;
		}
		nb_tour++;
	}
	return (nb_tour--);
}
