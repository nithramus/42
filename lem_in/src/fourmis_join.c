/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmis_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 22:14:51 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 22:24:57 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_fourmis	**t_fourmis_join(t_fourmis **list, t_fourmis *new)
{
	int			i;
	t_fourmis	**new_list;

	i = 0;
	while (list[i])
		i++;
	if (!(new_list = (t_fourmis**)malloc(sizeof(t_fourmis*) * (i + 2))))
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
