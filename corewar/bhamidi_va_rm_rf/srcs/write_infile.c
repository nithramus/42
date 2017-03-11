/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:33:08 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 19:41:19 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_comment(char *value, int fd, size_t len_comment)
{
	ft_putstr_fd(value, fd);
	while (len_comment < COMMENT_LENGTH)
	{
		ft_putchar_fd(0, fd);
		len_comment++;
	}
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
}

void	write_name(t_stable *tab, char *value, int fd, size_t len_name)
{
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0xea, fd);
	ft_putchar_fd(0x83, fd);
	ft_putchar_fd(0xf3, fd);
	ft_putstr_fd(value, fd);
	while (len_name < PROG_NAME_LENGTH + 6)
	{
		ft_putchar_fd(0, fd);
		len_name++;
	}
	tab = get_last(tab);
	if (tab->key == LABEL)
	{
		ft_putchar_fd(tab->label_pos / 256, fd);
		ft_putchar_fd(tab->label_pos % 256, fd);
	}
	else
	{
		ft_putchar_fd(get_oct(tab) / 256, fd);
		ft_putchar_fd(get_oct(tab) % 256, fd);
	}
}

void	write_spec_name(t_stable *tab, int fd)
{
	while (tab)
	{
		if (tab->key == NAME)
		{
			write_name(tab, tab->value, fd, ft_strlen(tab->value));
			break ;
		}
		tab = tab->next;
	}
}

void	write_name_comment(t_stable *tab, int fd)
{
	int		op;

	write_spec_name(tab, fd);
	while (tab)
	{
		if (tab->key == OPCODE)
		{
			if (tab->label_pos > (CHAMP_MAX_SIZE))
				break ;
			op = get_num(tab->value);
			write_opcode(op, tab, fd);
		}
		if (tab->key == COMMENT)
			write_comment(tab->value, fd, ft_strlen(tab->value));
		if (tab->key == P_REG)
			ft_putchar_fd(ft_atoi(tab->value + 1), fd);
		if (tab->key == P_IND)
			write_ind(tab->value, fd);
		if (tab->key == P_DIR)
			write_dir(tab->value, fd, op);
		tab = tab->next;
	}
}

void	write_infile(t_stable *tab, char *file_name)
{
	int		fd;
	char	*str;

	ft_putendl("binary file generate..");
	str = ft_strnew(ft_strlen(file_name) + 2);
	ft_strncpy(str, file_name, ft_strlen(file_name) - 1);
	ft_strcat(str, "cor");
	if ((fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0600)) == -1)
		return ;
	write_name_comment(tab, fd);
	ft_strdel(&str);
	if (close(fd) == -1)
		return ;
}
