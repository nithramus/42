/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:13:40 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 11:03:59 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	if (ft_strlen(to_find) == 0)
		return ((char*)str);
	while (i < ft_strlen(str))
	{
		if (str[i] == to_find[cpt])
		{
			while (str[i + cpt] == to_find[cpt] && cpt < ft_strlen(to_find))
			{
				if (cpt == (ft_strlen(to_find) - 1))
					return ((char*)str + i);
				cpt++;
			}
		}
		cpt = 0;
		i++;
	}
	return (0);
}
