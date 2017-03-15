/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:36:53 by bandre            #+#    #+#             */
/*   Updated: 2017/02/15 16:48:44 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_all_way(t_path ***list_path, t_struct *start,
		t_struct *end, t_struct **list_salles)
{
	int			i;
	t_struct	**list;

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

t_path		**find_path(t_struct *start, t_struct *end)
{
	t_path		**list_path;
	t_struct	**list_salles;

	if (!(list_path = (t_path**)malloc(sizeof(t_path*))))
		return (NULL);
	*list_path = NULL;
	if (!(list_salles = (t_struct**)malloc(sizeof(t_struct*) * 2)))
		return (NULL);
	*list_salles = start;
	list_salles[1] = NULL;
	find_all_way(&list_path, start, end, list_salles);
	return (list_path);
}
