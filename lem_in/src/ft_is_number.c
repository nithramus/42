/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:52:16 by bandre            #+#    #+#             */
/*   Updated: 2017/02/01 21:42:34 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_number(int *fourmis)
{
	int i;
	char *str;

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
	*fourmis = ft_atoi(str);
	ft_putendl(str);
	free(str);
	return (1);
}
