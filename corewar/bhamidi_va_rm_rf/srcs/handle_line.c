/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:48:39 by bhamidi           #+#    #+#             */
/*   Updated: 2017/02/26 17:52:37 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

extern t_op	g_op_tab[17];

int		have_param(char *str)
{
	if (!ft_strchr(str, ','))
		return (0);
	return (0);
}

int		handle_line(char *str, char **tab)
{
	int		i;
	int		cpt;

	cpt = 0;
	i = -1;
	while (tab[++i] != 0)
		if (!get_op_tab(tab[i]))
		{
			cpt = 1;
			break ;
		}
	if (!cpt && ft_strchr(str, ','))
		return (1);
	if (cpt && have_param(str))
		return (1);
	return (0);
}
