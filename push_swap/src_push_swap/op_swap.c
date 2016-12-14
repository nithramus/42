/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 01:16:52 by bandre            #+#    #+#             */
/*   Updated: 2016/12/09 00:54:38 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		op_swap(t_checker *elem_c)
{
	int tmp;

	if (!elem_c)
		return (1);
	if (!elem_c->next)
		return (1);
	tmp = elem_c->nb;
	elem_c->nb = elem_c->next->nb;
	elem_c->next->nb = tmp;
	return (1);
}
