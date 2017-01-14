/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:29:30 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 00:01:46 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_trie(t_checker *a_list, t_checker *b_list)
{
	if (b_list)
		return (0);
	while (a_list)
	{
		if (a_list->next)
			if (a_list->nb > a_list->next->nb)
				return (0);
		a_list = a_list->next;
	}
	return (1);
}

static int	expend(t_checker *a_list, t_checker *b_list, int len)
{
	if (is_trie(a_list, b_list))
	{
		ft_printf("\n");
		return (1);
	}
	if (len > 7)
		tri_fusion_ameliore(&a_list, &b_list, len);
	else
		recursif(&a_list, &b_list);
	ft_free_checker(a_list);
	ft_free_checker(b_list);
	return (1);
}


int			main(int argv, char **argc)
{
	int			len;
	char *ret;
	t_checker	*a_list;
	t_checker	*b_list;

	len = 0;
	if (argv == 1)
		return (1);
	if (!(a_list = new_list(argv, argc)))
	{
		ft_printf("Error\n");
		return (0);
	}
	b_list = a_list;
	while (a_list)
	{
		len++;
		a_list = a_list->next;
	}
	a_list = b_list;
	b_list = NULL;
	expend(a_list, b_list, len);
	return (1);
}
