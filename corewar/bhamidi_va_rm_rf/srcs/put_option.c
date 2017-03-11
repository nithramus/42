/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:23:27 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 18:12:49 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_opcode(t_stable *ptr)
{
	int		i;

	i = info_tab(ptr);
	if (!ft_strcmp(ptr->value, "lldi") || !ft_strcmp(ptr->value, "lld")
			|| !ft_strcmp(ptr->value, "ldi") || !ft_strcmp(ptr->value, "and")
			|| !ft_strcmp(ptr->value, "ld") || !ft_strcmp(ptr->value, "or")
			|| !ft_strcmp(ptr->value, "xor") || !ft_strcmp(ptr->value, "sti")
			|| !ft_strcmp(ptr->value, "st"))
		i += 2;
	ft_printf("%-6d(%d)  :\t\t%s: %d",
			ptr->label_pos, i, ptr->value, get_num(ptr->value));
	if (get_opcode(ptr, get_num(ptr->value)) != 0)
		ft_printf("\t[%d]",
				(unsigned char)get_opcode(ptr, get_num(ptr->value)));
	ft_putchar('\n');
}

void	print_prog_size(t_stable *ptr)
{
	t_stable *tab;

	tab = NULL;
	tab = get_last(ptr);
	ft_putstr("Programe size: ");
	if (tab->key == LABEL)
		ft_printf("%d bytes\n", tab->label_pos);
	else
		ft_printf("%d bytes\n", (get_oct(tab)));
}

void	put_option(t_stable *tab)
{
	ft_putendl("Write info program in standard output");
	print_prog_size(tab);
	while (tab)
	{
		if (tab->key == NAME)
			ft_printf("%s\"%s\"\n", "NAME: ", tab->value);
		if (tab->key == COMMENT)
			ft_printf("%s\"%s\"\n\n", "COMMENT: ", tab->value);
		if (tab->key == LABEL)
			ft_printf("%-11d:\t%s:\n", tab->label_pos, tab->value);
		if (tab->key == OPCODE)
		{
			print_opcode(tab);
			ft_putchar('\n');
		}
		tab = tab->next;
	}
}
