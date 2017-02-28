/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remptab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 18:24:22 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/27 16:50:25 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_rempcol(char **str, t_tabval **tab, int *var, char *carac)
{
	int var2[2];

	var2[0] = var[0];
	var2[1] = var[1];
	if (str[var2[0]][var2[1]] == '\0')
	{
		tab[var2[0]][var2[1]].down = -1;
		return (0);
	}
	if (str[var2[0]][var2[1]] == carac[1])
	{
		tab[var2[0]][var2[1]].down = 0;
		var2[0]++;
		ft_rempcol(str, tab, var2, carac);
		return (0);
	}
	var2[0]++;
	tab[var[0]][var[1]].down = 1 + ft_rempcol(str, tab, var2, carac);
	return (tab[var[0]][var[1]].down);
}

int			ft_remplign(char **str, t_tabval **tab, int *var, char *carac)
{
	int var2[2];

	var2[0] = var[0];
	var2[1] = var[1];
	if (str[var2[0]][var2[1]] == '\0')
	{
		tab[var2[0]][var2[1]].right = -1;
		return (0);
	}
	if (str[var2[0]][var2[1]] == carac[1])
	{
		tab[var2[0]][var2[1]].right = 0;
		var2[1]++;
		ft_remplign(str, tab, var2, carac);
		return (0);
	}
	var2[1]++;
	tab[var[0]][var[1]].right = 1 + ft_remplign(str, tab, var2, carac);
	return (tab[var[0]][var[1]].right);
}

t_tabval	**ft_remptab(int x, int y, char **str, char *carac)
{
	t_tabval	**tab;
	int			var[2];

	var[0] = 0;
	var[1] = 0;
	tab = ft_creatabstruc(x, y);
	while (y > var[1])
	{
		ft_rempcol(str, tab, var, carac);
		var[1]++;
	}
	var[0] = 0;
	var[1] = 0;
	while (x > var[0])
	{
		ft_remplign(str, tab, var, carac);
		var[0]++;
	}
	return (tab);
}
