/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 19:52:11 by bandre            #+#    #+#             */
/*   Updated: 2017/04/02 19:57:00 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printf_option(t_option option)
{
	ft_printf("r: %d\nR %d\na %d\nl %d\nt %d\n" ,option.r, option.rmaj, option.a, option.l, option.t);
}
