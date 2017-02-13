/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:04:25 by bandre            #+#    #+#             */
/*   Updated: 2017/02/13 20:55:33 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free(char **split, char *line)
{
	free(line);
	ft_free_split(split);
}

int		test_error(char **split, char *line)
{
	int		i;

	i = 0;
	if (split[0][0] == '#')
		return (0);
	if (!split[0])
	{
		ft_free(split, line);
		return (1);
	}
	while (split[i])
		i++;
	if (i != 2)
	{
		ft_free(split, line);
		return (1);
	}
	return (0);
}

int		test_valide(char **split, char *line)
{
	int i;

	i = 0;
	if (ft_strchr(line, '-'))
	{
		while (split[i])
			i++;
		if (i == 1)
			if (split[0][0] != '#')
			{
				ft_free_split(split);
				return (1);
			}
		return (0);
	}
	else
		return (0);
	return (1);
}
