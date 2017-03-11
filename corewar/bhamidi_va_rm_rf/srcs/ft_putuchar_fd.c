/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:39:09 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/09 13:51:29 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_error_bad_file(t_stable **tab)
{
	ft_putendl("error: Unknow or bad file");
	free_stable(tab);
	exit(EXIT_FAILURE);
}

char		get_code_axo(t_stable *tab)
{
	char	k1;
	char	k2;

	k1 = tab->next->key;
	if ((k2 = tab->next->next->key) && k1 == P_REG)
	{
		if (k2 == P_REG)
			return (0x54);
		if (k2 == P_IND)
			return (0x74);
		return (0x64);
	}
	else if (k1 == P_IND)
	{
		if (k2 == P_REG)
			return (0xd4);
		if (k2 == P_IND)
			return (0xf4);
		return (0xe4);
	}
	if (k2 == P_REG)
		return (0x94);
	if (k2 == P_IND)
		return (0xb4);
	return (0xa4);
}

int			get_oct(t_stable *ptr)
{
	int		res;

	res = ptr->label_pos;
	if (!ft_strcmp(ptr->value, "lldi")
			|| !ft_strcmp(ptr->value, "lld") || !ft_strcmp(ptr->value, "ldi")
			|| !ft_strcmp(ptr->value, "and") || !ft_strcmp(ptr->value, "ld")
			|| !ft_strcmp(ptr->value, "or") || !ft_strcmp(ptr->value, "xor")
			|| !ft_strcmp(ptr->value, "sti") || !ft_strcmp(ptr->value, "st"))
		res += 2;
	res += info_tab(ptr);
	return (res);
}

t_stable	*get_last(t_stable *tab)
{
	t_stable *tmp;

	tmp = tab;
	while (tab)
	{
		if (tab->key == LABEL || tab->key == OPCODE)
			tmp = tab;
		tab = tab->next;
	}
	return (tmp);
}

void		ft_putuchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}
