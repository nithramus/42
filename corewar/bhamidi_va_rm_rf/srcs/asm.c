/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 08:44:26 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/09 16:05:27 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	write_ind(char *value, int fd)
{
	long long int	n;

	n = ft_spec_atoi(value);
	if (n > LONG_MAX || n < LONG_MIN)
		n = 65535;
	if (n > 65535 || n < -65535)
		n = n % 65535;
	n = (n < 0) ? (unsigned short int)n : n;
	ft_putuchar_fd(n / 256, fd);
	ft_putuchar_fd(n % 256, fd);
}

int		data_verif(t_stable *ptr)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (count_tab(ptr) < 3)
		return (1);
	if (ptr->key != NAME && ptr->key != COMMENT)
		return (1);
	if (ptr->next->key != NAME && ptr->next->key != COMMENT)
		return (1);
	while (ptr)
	{
		if (ptr->key == 4)
			i++;
		if (ptr->key == 5)
			j++;
		ptr = ptr->next;
	}
	return ((j == 1 && i == 1) ? 0 : 1);
}

void	set_dir_num(t_stable *ptr)
{
	char		*tmp;
	t_stable	*t;
	int			label_pos;

	t = ptr;
	tmp = NULL;
	while (ptr)
	{
		if (ptr->key == OPCODE)
			label_pos = ptr->label_pos;
		if ((ptr->key == P_DIR || ptr->key == P_IND)
				&& ptr->value[0] == LABEL_CHAR)
		{
			tmp = ft_strdup(ptr->value);
			ft_strdel(&ptr->value);
			ptr->value = ft_itoa(get_mem_value_where(tmp, t) - label_pos);
			ft_strdel(&tmp);
		}
		ptr = ptr->next;
	}
}

int		bad_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 's' || path[len - 2] != '.')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_stable	*tab;
	int			fd;

	tab = NULL;
	if (ac == 1 || bad_file(av[ac - 1]))
		print_usage(av[0]);
	if ((fd = open(av[ac - 1], O_RDONLY)) == -1)
		print_error_file();
	lexical_parse(&tab, fd);
	if (data_verif(tab))
	{
		free_stable(&tab);
		print_name_comment_error();
	}
	parsing(&tab);
	increment_octet(tab);
	set_dir_num(tab);
	if (!ft_strcmp("-a", av[1]))
		put_option(tab);
	else
		write_infile(tab, av[ac - 1]);
	free_stable(&tab);
	return (0);
}
