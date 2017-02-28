/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatabstruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 18:18:41 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/27 18:07:39 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

t_tabval	**ft_creatabstruc(int x, int y)
{
	t_tabval	**str;
	int			i;

	i = 0;
	str = malloc(sizeof(t_tabval *) * (x + 1));
	while (x > i)
	{
		str[i] = malloc(sizeof(t_tabval) * (y + 1));
		i++;
	}
	return (str);
}

void		ft_freetabstruc(t_tabval **str, int x)
{
	int i;

	i = 0;
	while (i != x)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		ft_destroydd(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
