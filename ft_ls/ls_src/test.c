/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 19:52:11 by bandre            #+#    #+#             */
/*   Updated: 2017/05/03 20:57:26 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_list(t_file *first)
{
		ft_putendl("##########################");
	while (first)
	{
		ft_putstr(first->file);
		first = first->next;
	}
	ft_putendl("##########################");
}

void	printf_option(t_option option)
{
	ft_printf("r: %d\nR %d\na %d\nl %d\nt %d\n" ,option.r, option.rmaj, option.a, option.l, option.t);
}
