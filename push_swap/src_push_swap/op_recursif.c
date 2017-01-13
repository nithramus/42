/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_recursif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:08:52 by bandre            #+#    #+#             */
/*   Updated: 2017/01/13 17:51:36 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_recursif_a(t_checker **a_list, t_checker **b_list
		, int len, int len_max)
{
	char *ret;
	char *tmp;

	if (!(*b_list))
		return (NULL);
	op_push(b_list, a_list);
	if ((ret = tri_recursif(a_list, b_list, len, len_max)))
	{
		tmp = ft_strjoin("pa\n", ret);
		free(ret);
		return (tmp);
	}
	op_push(a_list, b_list);
	return (NULL);
}

char	*push_recursif_b(t_checker **a_list, t_checker **b_list,
		int len, int len_max)
{
	char *ret;
	char *tmp;

	if (!(*a_list))
		return (NULL);
	op_push(a_list, b_list);
	if ((ret = tri_recursif(a_list, b_list, len, len_max)))
	{
		tmp = ft_strjoin("pb\n", ret);
		free(ret);
		return (tmp);
	}
	op_push(b_list, a_list);
	return (NULL);
}

char	*rotate_recursif_b(t_checker **a_list, t_checker **b_list,
		int len, int len_max)
{
	char *tmp;
	char *ret;

	op_rotate(b_list);
	if ((ret = tri_recursif(a_list, b_list, len, len_max)))
	{
		tmp = ft_strjoin("rb\n", ret);
		free(ret);
		return (tmp);
	}
	op_reverse_rotate(b_list);
	return (NULL);
}

char	*reverse_recursif_b(t_checker **a_list, t_checker **b_list,
		int len, int len_max)
{
	char *tmp;
	char *ret;

	op_reverse_rotate(b_list);
	if ((ret = tri_recursif(a_list, b_list, len, len_max)))
	{
		tmp = ft_strjoin("rrb\n", ret);
		free(ret);
		return (tmp);
	}
	op_rotate(b_list);
	return (NULL);
}
