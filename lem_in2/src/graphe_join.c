/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphe_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:36:15 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 21:35:46 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_struct	**graphe_join(t_struct **src, t_struct *add)
{
	int			i;
	t_struct	**new;

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
	if (!(new = (t_struct**)malloc((i + 2) * sizeof(t_struct*))))
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
