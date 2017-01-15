/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphe_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:36:15 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 15:37:06 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

g_struct	**graphe_join(g_struct **src, g_struct *add)
{
	int			i;
	g_struct	**new;

	i = 0;
	if (is_in_list(src, add))
	{
		free(add->name);
		free(add->liaisons);
		free(add);
		return (src);
	}
	while (src[i])
		i++;
	new = (g_struct**)malloc((i + 2) * sizeof(g_struct*));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = NULL;
	free(src);
	return (new);
}
