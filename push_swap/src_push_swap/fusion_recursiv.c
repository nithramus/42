/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funsion_recursiv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 00:17:56 by bandre            #+#    #+#             */
/*   Updated: 2016/12/14 02:50:35 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			afficher(t_checker *src, t_checker *dest)
{
	ft_putendl("############debut##################");
	while (src)
	{
		ft_printf("liste a:%d\n", src->nb);
		src = src->next;
	}
	ft_putendl("############milieu##################");
	while (dest)
	{
		ft_printf("list b:%d\n", dest->nb);
		dest = dest->next;
	}
	ft_putendl("############fin##################");
	return (1);
}

static int	ft_extend(t_checker **src, t_checker **dest, int len, int *act_len)
{
	int lensrc;
	int lendest;
	int src_or_dest;

	src_or_dest = 0;
	lensrc = ft_checker_len(*src);
	lendest = ft_checker_len(*dest);
	while (*act_len <= lendest && *act_len <= lensrc)
	{
		tri_am_b(dest, src, len / 2, len / 2);
		*act_len += len / 2;
		src_or_dest = 1;
		if (*act_len <= lendest && *act_len <= lensrc)
		{
			tri_am_a(src, dest, len / 2, len / 2);
			*act_len += len / 2;
			src_or_dest = 0;
		}
	}
	return (src_or_dest);
}

int			fusion_recursiv(t_checker **src, t_checker **dest, int len,
		int src_or_dest)
{
	int act_len;
	int lensrc;
	int lendest;

	lensrc = ft_checker_len(*src);
	lendest = ft_checker_len(*dest);
	act_len = len / 2;
	if (lensrc + lendest <= len)
	{
		tri_am_a(src, dest, lensrc, lendest);
		return (1);
	}
	src_or_dest = ft_extend(src, dest, len, &act_len);
	lensrc = lensrc - act_len + len / 2;
	lendest = lendest - act_len + len / 2;
	if (lensrc != 0 || lendest != 0)
	{
		if (src_or_dest == 0)
			tri_am_b(dest, src, lendest, lensrc);
		else
			tri_am_a(src, dest, lensrc, lendest);
	}
	return (fusion_recursiv(src, dest, len * 2, 0));
}
