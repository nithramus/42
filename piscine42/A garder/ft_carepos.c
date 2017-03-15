/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carepos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 13:52:31 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/27 11:42:24 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_verif(t_tabval **tab, int x, int y)
{
	int size;
	int i;

	if (tab[x][y].down == 0 || tab[x][y].right == 0)
		return (0);
	if (tab[x][y].down < tab[x][y].right)
	{
		size = tab[x][y].down;
		i = 1;
		while (i < size && size > 0)
		{
			if (tab[x+ i][y].right < size)
			{
				size--;
				i--;
			}
			else
			{
				i++;
			}
		}
	}
	else
	{
		size = tab[x][y].right;
		i = 1;
		while (i < size && size > 0)
		{
			if (tab[x][y + i].down < size)
			{
				size--;
				i--;
			}
			else
			{
				i++;
			}
		}
	}
	return (size);
}
int		ft_carepos(t_tabval **tab, int *posx, int *posy)
{
	int x;
	int y;
	int maxsize;
	int maxx;
	int maxy;

	x = 0;
	y = 0;
	maxx = 0;
	maxy = 0;
	maxsize = 0;
	while (x < *posx)
	{
		y = 0;
		while (y < *posy)
		{
			if (ft_verif(tab, x, y) > maxsize)
			{
				maxy = y;
				maxx = x;
				maxsize = ft_verif(tab, x , y);
			}
			y++;
		}
		x++;
	}
	*posx = maxx;
	*posy = maxy;
	return (maxsize);
}

