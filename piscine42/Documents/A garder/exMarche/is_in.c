/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 18:19:36 by cpierre           #+#    #+#             */
/*   Updated: 2016/07/17 05:04:28 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		line(char **tab, int x, int y)
{
	char	check;
	int		i;

	check = tab[x][y];
	i = 1;
	while (i < 10)
	{
		if (tab[i][y] == check && i != x)
			return (0);
		i++;
	}
	return (1);
}

int		column(char **tab, int x, int y)
{
	char	check;
	int		i;

	check = tab[x][y];
	i = 0;
	while (i < 9)
	{
		if (tab[x][i] == check && i != y)
			return (0);
		i++;
	}
	return (1);
}

int		square(char **tab, int x, int y)
{
	int		check;
	int		i;
	int		j;
	int		posx;
	int		posy;

	check = tab[x][y];
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			posx = (((x - 1) / 3) * 3) + i + 1;
			posy = ((y / 3) * 3) + j;
			if (tab[posx][posy] == check && (posy != y && posx != x))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
