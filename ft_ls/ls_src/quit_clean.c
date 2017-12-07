/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:52:42 by bandre            #+#    #+#             */
/*   Updated: 2017/04/29 18:48:04 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	quit_clean(int error)
{
	if (error == 0)
	{
		//perror("ft_ls:");
	}
	else if (error == 1)
	{
		ft_putendl("L'allocation de memoire a echoue, la memoire Ram est sans doute pleine");
	}
	else if (error == 2)
	{
		ft_putendl("usage");
	}
	else if (error == 4)
	{
		ft_putendl("Erreur des fonctions systemes");
	}
	mem_stock_free();
	exit(0);
}
