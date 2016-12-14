/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau_trie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 01:02:18 by bandre            #+#    #+#             */
/*   Updated: 2016/12/11 01:14:46 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*tableau_trie(t_checker *a_list, int len)
{
	int *tab;
	int i;
	int count;
	int tmp;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		tab[i] = a_list->nb;
		a_list = a_list->next;
		i++;
	}
	count = 1;
	while (count)
	{
		count = 0;
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
				count = 1;
			}
			i++;
		}
	}
	i = 0;
	while (i < len)
	{
		ft_printf("tab:%d\n", tab[i]);
		i++;
	}
	return (tab);
}

