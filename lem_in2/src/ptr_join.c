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

t_struct	**ptr_join_not_free(t_struct **list, t_struct *add)
{
	int			i;
	t_struct	**new;

	i = 0;
	while (list[i])
		i++;
	if (!(new = (t_struct**)malloc((i + 2) * sizeof(t_struct*))))
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

t_struct	**ptr_join(t_struct **list, t_struct *add)
{
	int			i;
	t_struct	**new;

	i = 0;
	while (list[i])
		i++;
	if (!(new = (t_struct**)malloc((i + 2) * sizeof(t_struct*))))
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
