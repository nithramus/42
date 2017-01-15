/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:36:53 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 21:36:41 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_all_way(f_path ***list_path, g_struct *start,
		g_struct *end, g_struct **list_salles)
{
	int			i;
	g_struct	**list;

	i = 0;
	if (start == end)
	{
		if (!(path_join(list_path, list_salles)))
			afficher_error();
		return (1);
	}
	while (start->liaisons[i])
	{
		if (!(is_in_list(list_salles, start->liaisons[i])))
		{
			if (!(list = ptr_join_not_free(list_salles, start->liaisons[i])))
				afficher_error();
			find_all_way(list_path, start->liaisons[i], end, list);
		}
		i++;
	}
	free(list_salles);
	return (1);
}

f_path		**find_path(g_struct *start, g_struct *end)
{
	f_path		**list_path;
	g_struct	**list_salles;

	if (!(list_path = (f_path**)malloc(sizeof(f_path*))))
		return (NULL);
	*list_path = NULL;
	if (!(list_salles = (g_struct**)malloc(sizeof(g_struct*) * 2)))
		return (NULL);
	*list_salles = start;
	list_salles[1] = NULL;
	find_all_way(&list_path, start, end, list_salles);
	return (list_path);
}
