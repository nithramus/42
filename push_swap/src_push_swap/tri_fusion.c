/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:57:07 by bandre            #+#    #+#             */
/*   Updated: 2016/12/11 02:26:40 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		afficher(t_checker *src, t_checker *dest)
{
	ft_putendl("############debut##################");
	while (src)
	{
		ft_printf("liste a:%d\n", src->nb);
		src= src->next;
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

int		tri(t_checker **src, t_checker **dest, int len)
{
	int i;
	int nb_push;
	int nb_rotate;
	int ret;

	nb_push = 0;
	nb_rotate = 0;
	i = 0;
	while (i < (len + len/2))
	{
		if (*dest)
		{
			if (((*dest)->nb < (*src)->nb || nb_rotate == (len / 2 + nb_push)) && (nb_push < len / 2))
			{
				op_push(dest, src);
				nb_push++;
			}
			else
			{
				op_rotate(src);
				nb_rotate++;
			}
		}
		else
		{
			op_rotate(src);
			nb_rotate++;
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		op_reverse_rotate(src);
		i++;
	}
	ret = nb_push + nb_rotate;
	return (ret);
}

int		tri_fusion(t_checker **src, t_checker **dest, char list, int len)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	list = 'b';
	if (len == 2)
	{
		if ((*dest)->nb > (*dest)->next->nb)
		{
			op_swap(*dest);
			return (1);
		}
		return (1);
	}
	while (i < (len / 2))
	{
		op_push(src, dest);
		i++;
	}
	ret += i;
	ret += tri_fusion(src, dest, list, len /2);
	ft_putendl("\npasser");
	ret += tri_fusion(dest, src, list, len/2);
	ret += tri(src, dest, len);

	return (ret);
}
