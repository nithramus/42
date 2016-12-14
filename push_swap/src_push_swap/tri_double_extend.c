/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_double_extend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:34:06 by bandre            #+#    #+#             */
/*   Updated: 2016/12/14 01:50:34 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tridouble_extend(t_checker **dest, char a)
{
	if ((*dest)->nb > (*dest)->next->nb)
	{
		ft_printf("s%c\n", a);
		op_swap(*dest);
	}
	op_rotate(dest);
	op_rotate(dest);
	ft_printf("r%c\n", a);
	ft_printf("r%c\n", a);
}
