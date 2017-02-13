/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:06:13 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 18:13:04 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_list_t_struct(t_struct **list_ptr)
{
	int i;

	i = 0;
	while (list_ptr[i])
	{
		free(list_ptr[i]->liaisons);
		free(list_ptr[i]->name);
		free(list_ptr[i]);
		i++;
	}
	free(list_ptr);
}

void	ft_free_list_t_path(t_path **list_ptr)
{
	int i;

	i = 0;
	while (list_ptr[i])
	{
		free(list_ptr[i]->path);
		free(list_ptr[i]->dependance);
		free(list_ptr[i]);
		i++;
	}
	free(list_ptr);
}

void	ft_free_t_fourmis(t_fourmis **list)
{
	int i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	ft_free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
