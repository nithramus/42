/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:03:37 by bandre            #+#    #+#             */
/*   Updated: 2017/01/05 00:36:23 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_struct	*new_t_struct(char *name)
{
	t_struct *new;

	new = (t_struct*)malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->name = (char*)malloc(ft_strlen(name) + 1);
	if (!new->name)
	{
		free(new);
		return (NULL);
	}
	new->liaisons = (t_struct**)malloc(sizeof(t_struct*));
	if (!new->liaisons)
	{
		free(new);
		return (NULL);
	}
	new->liaisons[0] = NULL;
	ft_strcpy(new->name, name);
	return (new);
}
