/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:34:31 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 19:55:34 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_checker	*complete_list(int argc, char **argv, t_checker *prev)
{
	int			i;
	int			value;
	t_checker	*elem;

	i = 2;
	elem = prev;
	while (i < argc)
	{
		if (!(verif_entier(argv[i], &value)))
			return (NULL);
		if (!(elem->next = ft_new_checker(value, elem)))
			return (NULL);
		elem = elem->next;
		i++;
	}
	return (elem);
}

static int			double_list(t_checker *list)
{
	int			nb;
	t_checker	*tmp_list;

	while (list)
	{
		nb = list->nb;
		tmp_list = list->next;
		while (tmp_list)
		{
			if (tmp_list->nb == nb)
				return (-1);
			tmp_list = tmp_list->next;
		}
		list = list->next;
	}
	return (1);
}

t_checker			*new_list(int argv, char **argc)
{
	t_checker	*first_c;
	int			value;

	if (!(verif_entier(argc[1], &value)))
		return (NULL);
	if (!(first_c = ft_new_checker(value, NULL)))
		return (NULL);
	if (!(first_c->previous = complete_list(argv, argc, first_c)))
	{
		ft_free_checker(first_c);
		return (NULL);
	}
	if (double_list(first_c) == -1)
		return (NULL);
	return (first_c);
}
