/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_g_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:03:37 by bandre            #+#    #+#             */
/*   Updated: 2017/01/05 00:36:23 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

g_struct	*new_g_struct(char *name)
{
	g_struct *new;

	new = (g_struct*)malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->name = (char*)malloc(ft_strlen(name) + 1);
	if (!new->name)
	{
		free(new);
		return (NULL);
	}
	new->liaisons = (g_struct**)malloc(sizeof(g_struct*));
	if (!new->liaisons)
	{
		free(new);
		return (NULL);
	}
	new->liaisons[0] = NULL;
	ft_strcpy(new->name, name);
	return (new);
}
