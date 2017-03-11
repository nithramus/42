/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:58:41 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 15:22:06 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

extern t_op	g_op_tab[17];

int		handle_state(t_stable **head, t_stable *ptr)
{
	ptr = *head;
	if (ptr->key != LABEL && ptr->key != OPCODE)
		return (1);
	if (ptr->key == LABEL)
		return (0);
	if (get_num(ptr->value) == 16)
		return (test_aff(head));
	if (get_num(ptr->value) == 1 || get_num(ptr->value) == 9
			|| get_num(ptr->value) == 12 || get_num(ptr->value) == 15)
		return (test_only_dir(head));
	if (get_num(ptr->value) == 14 || get_num(ptr->value) == 10)
		return (test_ldi(head));
	if (get_num(ptr->value) == 4 || get_num(ptr->value) == 5)
		return (test_add_sub(head));
	if (get_num(ptr->value) == 7 || get_num(ptr->value) == 8
			|| get_num(ptr->value) == 6)
		return (test_xor_or(head));
	if (get_num(ptr->value) == 2 || get_num(ptr->value) == 13)
		return (test_load(head));
	if (get_num(ptr->value) == 3)
		return (test_st(head));
	if (get_num(ptr->value) == 11)
		return (test_sti(head));
	return (1);
}

int		exist(char *dir_lab, t_stable *ptr)
{
	char	*str;

	str = NULL;
	while (ptr)
	{
		if (ptr->key == LABEL)
		{
			str = ft_strdup(ptr->value);
			str[ft_strlen(str) - 1] = '\0';
			if (!ft_strcmp(str, dir_lab))
			{
				ft_strdel(&str);
				return (0);
			}
		}
		ft_strdel(&str);
		ptr = ptr->next;
	}
	ft_strdel(&str);
	return (1);
}

int		valide_label(t_stable *ptr, t_stable **head)
{
	t_stable	*tmp;

	tmp = ptr;
	while (ptr)
	{
		if (ptr->key == P_DIR && ptr->value[0] == LABEL_CHAR)
		{
			if (exist(&ptr->value[1], tmp))
				print_syntax_error(head, ptr->value, ptr->line);
		}
		ptr = ptr->next;
	}
	return (0);
}

void	tr_label(t_stable *ptr)
{
	while (ptr)
	{
		if (ptr->key == LABEL)
			ptr->value[ft_strlen(ptr->value) - 1] = '\0';
		ptr = ptr->next;
	}
}

int		parsing(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	while (ptr)
	{
		if (ptr->key != NAME && ptr->key != COMMENT)
			if (handle_state(&ptr, ptr))
				print_syntax_error(head, ptr->value, ptr->line);
		ptr = ptr->next;
	}
	ptr = *head;
	valide_label(ptr, head);
	tr_label(ptr);
	return (0);
}
