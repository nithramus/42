/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_op_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:36:59 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/06 16:34:21 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

extern	t_op	g_op_tab[17];

int				count_basic_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i] != 0)
		;
	return (i);
}

int				get_modif_ind_value(char *op)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].op_name)
		if (!ft_strcmp(g_op_tab[i].op_name, op))
			return (g_op_tab[i].modif_ind);
	return (-1);
}

int				get_num(char *str)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].op_name)
		if (!ft_strcmp(g_op_tab[i].op_name, str))
			return (g_op_tab[i].op_code);
	return (-1);
}
