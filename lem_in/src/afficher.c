/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:43:48 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 21:05:43 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		afficher(g_struct **list_salles)
{
	int i;

	i = 0;
	ft_putendl("###############");
	while (list_salles[i])
	{
		ft_putendl((list_salles[i])->name);
		i++;
	}
	ft_putendl("###############");
	return (1);
}

int		afficher_road(f_path **path)
{
	int i;

	i = 0;
	ft_putendl("##############################");
	while (path[i])
	{
		afficher(path[i]->path);
		i++;
	}
	ft_putendl("###############################");
	return (1);
}

void	afficher_error(void)
{
	ft_putendl("ERROR");
	exit(0);
}
