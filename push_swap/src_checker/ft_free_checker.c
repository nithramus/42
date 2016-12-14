/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:32:00 by bandre            #+#    #+#             */
/*   Updated: 2016/12/08 00:33:42 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_checker(t_checker *first)
{
	t_checker *elem;

	while (first)
	{
		elem = first->next;
		free(first);
		first = elem;
	}
}
