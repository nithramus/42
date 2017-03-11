/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:48:08 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 12:52:05 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

extern	t_op	g_op_tab[17];

void	print_mem(t_stable *ptr)
{
	if (ptr->key == OPCODE || ptr->key == LABEL)
	{
		ft_putstr(ptr->value);
		ft_putstr("\t::mem_value:");
		ft_putnbr(ptr->label_pos);
		ft_putchar('\n');
	}
}

int		var_value(t_stable *ptr)
{
	int		res;
	char	*op;

	op = ptr->value;
	res = 0;
	ptr = ptr->next;
	while (ptr && ptr->key != OPCODE && ptr->key != LABEL)
	{
		if (ptr->key == P_REG)
			res += 1;
		if (ptr->key == P_IND)
			res += 2;
		if (ptr->key == P_DIR)
			res += ((get_modif_ind_value(op)) ? 2 : 4);
		ptr = ptr->next;
	}
	return (res);
}

int		info_tab(t_stable *ptr)
{
	int				i;
	const t_info	info[8] =
	{{"live", 5}, {"zjmp", 3}, {"aff", 3},
		{"lfork", 3}, {"fork", 3}, {"add", 5}, {"sub", 5},
		{0, 0}};

	i = -1;
	while (info[++i].opcode != 0)
		if (!ft_strcmp(ptr->value, info[i].opcode))
			return (info[i].value);
	return (var_value(ptr));
}

void	increment_octet(t_stable *ptr)
{
	int		mem_value;

	mem_value = 0;
	while (ptr)
	{
		if (ptr->key == LABEL)
			ptr->label_pos = mem_value;
		else if (ptr->key == OPCODE)
		{
			ptr->label_pos = mem_value;
			if (!ft_strcmp(ptr->value, "lldi")
	|| !ft_strcmp(ptr->value, "lld") || !ft_strcmp(ptr->value, "ldi")
	|| !ft_strcmp(ptr->value, "and") || !ft_strcmp(ptr->value, "ld")
	|| !ft_strcmp(ptr->value, "or") || !ft_strcmp(ptr->value, "xor")
	|| !ft_strcmp(ptr->value, "sti") || !ft_strcmp(ptr->value, "st"))
				mem_value += 2;
			mem_value += info_tab(ptr);
		}
		ptr = ptr->next;
	}
}
