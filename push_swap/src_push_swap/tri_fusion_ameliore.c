/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion_ameliore.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:57:31 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 18:06:56 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		fusion_recursiv(t_checker **src, t_checker **dest, int len, int len_max)
{
	int act_len;
	int nb_op;
	int lensrc;
	int lendest;
	int src_or_dest;

	lensrc = ft_checker_len(*src);
	lendest = ft_checker_len(*dest);
	//ft_printf("lensrc:%d\nlendest:%d\n", lensrc, lendest);

	src_or_dest = 0;
	nb_op = 0;
	act_len = len/2;

	if (lensrc + lendest <= len)
	{
		nb_op += tri_am(src, dest, lensrc, lendest);
		afficher(*src, *dest);
		return (nb_op);
	}

	while (act_len <= lendest && act_len <= lensrc)
	{
		nb_op += tri_am(dest, src, len/2, len/2);
		act_len += len/2;
		src_or_dest = 1;
		if (act_len <= lendest && act_len <= lensrc)
		{
			nb_op += tri_am(src, dest, len/2, len/2);
			act_len += len/2;
			src_or_dest = 0;
		}
	}
	lensrc = lensrc - act_len + len/2;
	lendest = lendest - act_len + len/2;
	if (lensrc != 0 || lendest != 0)
	{
		if (src_or_dest == 0)
			tri_am(dest, src, lendest, lensrc);
		else
		{
	afficher(*src, *dest);
			tri_am(src, dest, lensrc, lendest);
		}
	}
	nb_op += fusion_recursiv(src, dest, len * 2, len_max);
	return (nb_op);
}

int		tri_fusion_ameliore(t_checker **src, t_checker **dest, int len_max)
{
	int i;
	int nb_op;
	int lendest;
	int lensrc;

	i = 0;
	nb_op = 0;
	while (i < len_max /2)
	{
		op_push(src, dest);
		i++;
	}
	i = 2;
	lensrc = ft_checker_len(*src);
	lendest = ft_checker_len(*dest);
	while (i <= lendest || i <= lensrc)
	{
		if (i <= lendest)
		{
			if ((*dest)->nb > (*dest)->next->nb)
				op_swap(*dest);
			op_rotate(dest);
			op_rotate(dest);
		}
		if (i <= lensrc)
		{
			if ((*src)->nb > (*src)->next->nb)
				op_swap(*src);
			op_rotate(src);
			op_rotate(src);
		}
		i += 2;
	}
	if (lendest % 2 != 0)
		op_rotate(dest);
	if (lensrc % 2 != 0)
		op_rotate(src);
	nb_op += len_max + len_max/2;
	nb_op += fusion_recursiv(src, dest, 4, len_max);
	return (nb_op);
}
