/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 01:24:24 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 18:40:10 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_extend(t_checker **dest)
{
	t_checker *parcour;

	parcour = *dest;
	if (parcour)
		while (parcour)
		{
			if (!(parcour->next))
				(*dest)->previous = parcour;
			parcour = parcour->next;
		}
	return (1);
}

int			op_push(t_checker **src, t_checker **dest)
{
	t_checker *tmpsrc;
	t_checker *parcour;

	if (!(*src))
		return (1);
	tmpsrc = *src;
	*src = (*src)->next;
	parcour = *src;
	if (parcour)
		while (parcour)
		{
			if (!(parcour->next))
				(*src)->previous = parcour;
			parcour = parcour->next;
		}
	if (*dest)
		(*dest)->previous = tmpsrc;
	tmpsrc->next = *dest;
	*dest = tmpsrc;
	ft_extend(dest);
	return (1);
}
