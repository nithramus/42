/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 23:25:24 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 20:54:29 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

f_path	**path_join(f_path ***list, g_struct **add)
{
	int		i;
	f_path	**new;
	f_path	**stock;

	i = 0;
	stock = *list;
	while ((*list)[i])
		i++;
	if (!(new = (f_path**)malloc((i + 2) * sizeof(f_path*))))
		return (NULL);
	i = 0;
	while ((*list)[i])
	{
		new[i] = (*list)[i];
		i++;
	}
	*list = new;
	if (!(new[i] = new_f_path(add)))
		return (NULL);
	new[i + 1] = NULL;
	free(stock);
	return (new);
}
