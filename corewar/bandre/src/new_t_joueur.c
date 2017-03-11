/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_joueur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:41:12 by bandre            #+#    #+#             */
/*   Updated: 2017/03/08 18:21:08 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_joueur	*new_t_joueur(char *name, char *cri, char num)
{
	t_joueur	*new;

	if (!(new = (t_joueur*)malloc(sizeof(t_joueur))))
		quit_clean(1);
	if (!(new->name = (char*)malloc(ft_strlen(name))))
		quit_clean(1);
	ft_strcpy(new->name, name);
	if (!(new->cri_de_guerre = (char*)malloc(ft_strlen(cri))))
		quit_clean(1);
	ft_strcpy(new->cri_de_guerre, cri);
	new->num_joueur = num;
	new->nb_live = 0;
	new->last_live = 0;
	return (new);
}
