/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:37:32 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 21:04:11 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

g_struct	**ptr_join_not_free(g_struct **list, g_struct *add)
{
	int			i;
	g_struct	**new;

	i = 0;
	while (list[i])
		i++;
	if (!(new = (g_struct**)malloc((i + 2) * sizeof(g_struct*))))
		return (NULL);
	i = 0;
	while (list[i])
	{
		new[i] = list[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = NULL;
	return (new);
}

g_struct	**ptr_join(g_struct **list, g_struct *add)
{
	int			i;
	g_struct	**new;

	i = 0;
	while (list[i])
		i++;
	if (!(new = (g_struct**)malloc((i + 2) * sizeof(g_struct*))))
		return (NULL);
	i = 0;
	while (list[i])
	{
		new[i] = list[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = NULL;
	free(list);
	return (new);
}
