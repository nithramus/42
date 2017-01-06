/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:36:53 by bandre            #+#    #+#             */
/*   Updated: 2017/01/06 00:02:32 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_all_way(g_struct ***list_path, g_struct *start, g_struct *end, g_struct **list_salles)
{
	int i;
	g_struct **list;

	i = 0;
	if (start == end)
	{
		ft_putendl("fin du prog");
		return (1);
	}
	while (start->liaisons[i])
	{
		if (!(is_in_list(list_salles, start->liaisons[i])))
		{
			list = ptr_join(list_salles, start->liaisons[i]);
			find_all_way(list_path, start->liaisons[i], end, list);
		}
		i++;
	}
	free(list_salles);
	return (1);
}

g_struct	***find_path(g_struct *start, g_struct *end)
{
	g_struct ***list_path;
	g_struct **list_salles;

	list_path = (g_struct***)malloc(sizeof(g_struct**));
	*list_path = NULL;
	list_salles = (g_struct**)malloc(sizeof(g_struct*));
	*list_salles = NULL;

	find_all_way(list_path, start, end, list_salles);
	return (NULL);
}
