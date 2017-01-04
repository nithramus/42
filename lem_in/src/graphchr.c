/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:14:32 by bandre            #+#    #+#             */
/*   Updated: 2017/01/05 00:17:11 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

g_struct	*graphchr(g_struct **list_salles, char *salle)
{
	int i;
	 i = 0;
	 while (list_salles[i])
	 {
		 if (ft_strcmp((list_salles[i])->name, salle))
			 return (list_salles[i]);
		 i++;
	 }
	 return (NULL);
}
