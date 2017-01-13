/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_recursif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:16:57 by bandre            #+#    #+#             */
/*   Updated: 2017/01/13 18:39:53 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*tri_recursif(t_checker **a_list, t_checker
		**b_list, int len, int len_max)
{
	char *ret;

	if (is_trie(*a_list, *b_list))
		return (ft_strnew(1));
	if (len == len_max)
		return (NULL);
	if ((ret = swap_recursif_a(a_list, b_list, len + 1, len_max)))
		return (ret);
	if ((ret = swap_recursif_b(a_list, b_list, len + 1, len_max)))
		return (ret);
	if ((ret = push_recursif_a(a_list, b_list, len + 1, len_max)))
		return (ret);
	if ((ret = push_recursif_b(a_list, b_list, len + 1, len_max)))
		return (ret);
	if ((ret = reverse_recursif_a(a_list, b_list, len + 1, len_max)))
		return (ret);
	return (NULL);
}

int		recursif(t_checker **a_list, t_checker **b_list)
{
	int		len_max;
	char	*ret;

	len_max = 1;
	while (1)
	{
		ret = tri_recursif(a_list, b_list, 0, len_max);
		if (ret)
		{
			ft_printf("%s", ret);
			free(ret);
			return (1);
		}
		len_max++;
	}
	return (1);
}
