/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_am.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 02:24:10 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 18:06:50 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		tri_am(t_checker **src, t_checker **dest, int lensrc, int lendest)
{
	int i;
	int nb_rotate;
	int nb_push;
	int nb_op;

	nb_op = 0;
	i = 0;
	nb_push = 0;
	nb_rotate = 0;
	while (i < (lensrc + 2 * lendest))
	{

		if (*dest)
		{
			if (!*src)
			{
				op_push(dest, src);
				nb_push++;
			}
			else if (((*dest)->nb < (*src)->nb || nb_rotate == (lensrc + nb_push)) && (nb_push < lendest))
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
	return (nb_rotate + nb_push);
}
