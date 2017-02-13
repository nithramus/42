/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:51:05 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 20:51:39 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*new_t_path(t_struct **add)
{
	t_path	*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	if (!(new->dependance = (t_path**)malloc(sizeof(t_path*))))
		return (NULL);
	new->dependance[0] = NULL;
	new->path = add;
	new->nb_fourmis = 0;
	return (new);
}
