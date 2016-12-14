/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion_ameliore.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:57:31 by bandre            #+#    #+#             */
/*   Updated: 2016/12/14 02:49:33 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_checker **src, t_checker **dest, int len_max)
{
	int i;

	i = 0;
	while (i < len_max / 2)
	{
		op_push(src, dest);
		ft_printf("pb\n");
		i++;
	}
	return (1);
}

static int	opti_tri(t_checker **src, t_checker **dest, int print)
{
	if ((*dest)->nb > (*dest)->next->nb)
	{
		print += 1;
		op_swap(*dest);
	}
	if ((*src)->nb > (*src)->next->nb)
	{
		print += 2;
		op_swap(*src);
	}
	if (print == 3)
		ft_printf("ss\n");
	if (print == 1)
		ft_printf("sb\n");
	if (print == 2)
		ft_printf("sa\n");
	op_rotate(dest);
	op_rotate(dest);
	op_rotate(src);
	op_rotate(src);
	ft_printf("rr\n");
	ft_printf("rr\n");
	return (1);
}

int			tri_double(t_checker **src, t_checker **dest,
		int lensrc, int lendest)
{
	int i;

	i = 0;
	while ((i += 2) && (i <= lendest || i <= lensrc))
	{
		if (i <= lendest && i <= lensrc)
			opti_tri(src, dest, 0);
		else if (i <= lensrc)
			tridouble_extend(src, 'a');
		else if (i <= lendest)
			tridouble_extend(dest, 'b');
	}
	if (lendest % 2 != 0)
	{
		op_rotate(dest);
		ft_printf("rb\n");
	}
	if (lensrc % 2 != 0)
	{
		op_rotate(src);
		ft_printf("ra\n");
	}
	return (1);
}

int			tri_fusion_ameliore(t_checker **src, t_checker **dest, int len_max)
{
	int i;
	int lendest;
	int lensrc;

	i = 2;
	push(src, dest, len_max);
	lensrc = ft_checker_len(*src);
	lendest = ft_checker_len(*dest);
	tri_double(src, dest, lensrc, lendest);
	return (fusion_recursiv(src, dest, 4, 0) + len_max + len_max / 4);
}
