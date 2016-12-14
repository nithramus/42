/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_am.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 02:24:10 by bandre            #+#    #+#             */
/*   Updated: 2016/12/14 01:46:33 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_push(t_checker **src, t_checker **dest, int *nb_push, char a)
{
	op_push(dest, src);
	ft_printf("p%c\n", a);
	(*nb_push)++;
}

static void		ft_rotate(t_checker **src, int *nb_rotate, char a)
{
	op_rotate(src);
	ft_printf("r%c\n", a);
	(*nb_rotate)++;
}

int				tri_am_b(t_checker **src, t_checker **dest, int lensrc,
		int lendest)
{
	int i;
	int nb_rotate;
	int nb_push;

	i = 0;
	nb_push = 0;
	nb_rotate = 0;
	while (i < (lensrc + 2 * lendest))
	{
		if (*dest)
		{
			if (!*src)
				ft_push(src, dest, &nb_push, 'b');
			else if (((*dest)->nb < (*src)->nb || nb_rotate ==
						(lensrc + nb_push)) && (nb_push < lendest))
				ft_push(src, dest, &nb_push, 'b');
			else
				ft_rotate(src, &nb_rotate, 'b');
		}
		else
			ft_rotate(src, &nb_rotate, 'b');
		i++;
	}
	return (nb_rotate + nb_push);
}

int				tri_am_a(t_checker **src, t_checker **dest, int lensrc,
		int lendest)
{
	int i;
	int nb_rotate;
	int nb_push;

	i = 0;
	nb_push = 0;
	nb_rotate = 0;
	while (i < (lensrc + 2 * lendest))
	{
		if (*dest)
		{
			if (!*src)
				ft_push(src, dest, &nb_push, 'a');
			else if (((*dest)->nb < (*src)->nb || nb_rotate ==
						(lensrc + nb_push)) && (nb_push < lendest))
				ft_push(src, dest, &nb_push, 'a');
			else
				ft_rotate(src, &nb_rotate, 'a');
		}
		else
			ft_rotate(src, &nb_rotate, 'a');
		i++;
	}
	return (nb_rotate + nb_push);
}
