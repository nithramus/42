/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:35:34 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/07 17:40:18 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

extern t_op	g_op_tab[17];

int		free_string(char **str, int res)
{
	ft_strdel(str);
	return (res);
}

int		get_mem_value_where(char *label, t_stable *ptr)
{
	while (ptr)
	{
		if (ptr->key == LABEL)
			if (!ft_strcmp(label + 1, ptr->value))
				return (ptr->label_pos);
		ptr = ptr->next;
	}
	return (-1);
}

int		check(char *str)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].op_name != 0)
		if (!ft_strcmp(str, g_op_tab[i].op_name))
			return (0);
	return (1);
}

int		get_op_tab(char *str)
{
	return (check(str));
}
