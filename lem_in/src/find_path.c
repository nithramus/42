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

int		find_all_way(g_struct ***list_path, g_struct *start, g_struct *end)
{
}

g_struct	***find_path(g_struct *start, g_struct *end)
{
	g_struct ***list_path;

	list_path = (g_struct***)malloc(sizeof(g_struct**));
	*list_path = NULL;

	find_all_way(list_path, start, end);
	return (NULL);
}
