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

s_fourmis	**s_fourmis_join(s_fourmis **list, s_fourmis *new)
{
	int			i;
	s_fourmis	**new_list;

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
