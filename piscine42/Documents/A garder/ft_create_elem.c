/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 18:08:55 by bandre            #+#    #+#             */
/*   Updated: 2016/07/25 17:16:20 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_buff	*ft_create_elem(char *data)
{
	int		i;
	t_buff	*buff;

	i = 0;
	buff = malloc(sizeof(t_buff));
	if (buff)
	{
		buff->next = NULL;
		buff->data = malloc(sizeof(char) * (26));
		if (buff->data)
		{
			while (data[i])
			{
				buff->data[i] = data[i];
				i++;
			}
			buff->data[i] = '\0';
			return (buff);
		}
		else
			return (0);
	}
	else
		return (0);
}
