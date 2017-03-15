/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:52:16 by bandre            #+#    #+#             */
/*   Updated: 2017/02/15 14:30:15 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_number(int *fourmis, char **fichier)
{
	int		i;
	char	*str;

	if (!(get_next_line(0, &str)))
		afficher_error();
	i = 0;
	if (str[i])
		if (str[i + 1])
			if (ft_strchr("+-", str[i]))
				i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(str) < 0)
		return (0);
	*fourmis = ft_atoi(str);
	if (!(*fichier = ft_strjoin(str, "\n")))
		return (0);
	free(str);
	return (1);
}
