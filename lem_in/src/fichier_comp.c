/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_comp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:21:58 by bandre            #+#    #+#             */
/*   Updated: 2017/02/02 13:33:58 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		fichier_comp(char **fichier, char *str)
{
	char *tmp;

	tmp = *fichier;
	if (!(*fichier = ft_strjoin(*fichier, str)))
		return (0);
	free(tmp);
	tmp = *fichier;
	if (!(*fichier = ft_strjoin(*fichier, "\n")))
		return (0);
	free(tmp);
	return (1);
}
