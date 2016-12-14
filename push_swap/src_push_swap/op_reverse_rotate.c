/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:55:51 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 20:14:21 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		op_reverse_rotate(t_checker **list)
{
	t_checker *tmp;
	t_checker *parcour;

	if (!(*list))
		return (1);
	if (!((*list)->next))
		return (1);
	parcour = *list;
	while (parcour)
	{
		if (!(parcour->next))
		{
			tmp = parcour;
			parcour->previous->next = NULL;
		}
		parcour = parcour->next;
	}
	tmp->next = *list;
	*list = tmp;
	return (1);
}
