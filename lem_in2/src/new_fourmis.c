/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fourmis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 22:12:54 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 22:13:38 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_fourmis	*new_fourmis(t_path *road, int num_fourmis)
{
	t_fourmis *new;

	if (!(new = (t_fourmis*)malloc(sizeof(t_fourmis))))
		afficher_error();
	new->pos = 0;
	new->road = road;
	new->num_fourmis = num_fourmis;
	new->move = 1;
	return (new);
}
