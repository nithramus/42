/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:11:30 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 14:47:27 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	if (ft_strlen(to_find) == 0)
		return ((char*)str);
	while (i < n && str[i])
	{
		if (str[i] == to_find[cpt])
		{
			while (str[i + cpt] == to_find[cpt] && cpt < ft_strlen(to_find))
			{
				if ((cpt + i) >= n)
					return (0);
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
