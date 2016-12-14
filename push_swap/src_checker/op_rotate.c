/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:13:52 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 18:41:25 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		op_rotate(t_checker **list)
{
	t_checker	*tmp;
	t_checker	*parcour;
	int			i;

	i = 0;
	if (!*list)
		return (1);
	else if (!((*list)->next))
		return (1);
	tmp = *list;
	*list = (*list)->next;
	parcour = *list;
	while (parcour)
	{
		if (parcour->next == NULL)
		{
			parcour->next = tmp;
			tmp->next = NULL;
			return (1);
		}
		parcour = parcour->next;
	}
	return (1);
}
