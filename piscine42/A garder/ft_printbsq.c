/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:58:23 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/27 19:15:12 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_x(char **tab, int *pos, int size, char *carac)
{
	int i;
	int j;
	int x;
	int y;

	x = pos[1];
	y = pos[0];
	i = x;
	j = y;
	size--;
	while (i <= (x + size))
	{
		j = y;
		while (j <= (y + size))
		{
			tab[i][j] = carac[2];
			j++;
		}
		i++;
	}
}

void	ft_printbsq(char **str, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < x - 1)
	{
		j = 0;
		while (j < y)
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
