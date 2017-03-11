/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_opcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:36:53 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 15:30:52 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

extern	t_op	g_op_tab[17];

void	write_dir(char *value, int fd, int op)
{
	long long int	n;

	n = ft_spec_atoi(value);
	if (n > LONG_MAX || n < LONG_MIN)
		n = UINT_MAX;
	if (n > UINT_MAX || n < -UINT_MAX)
		n = n % UINT_MAX;
	if (!g_op_tab[op - 1].modif_ind)
	{
		if (n < 0 || n > 2147483647)
			n = 4294967296 + n;
		ft_putuchar_fd(n / (256 * 256 * 256), fd);
		n = n % (256 * 256 * 256);
		ft_putuchar_fd(n / (256 * 256), fd);
		n = n % (256 * 256);
	}
	n = (n < 0 || n > 32767) ? (unsigned short int)n : n;
	ft_putuchar_fd(n / 256, fd);
	ft_putuchar_fd(n % 256, fd);
}

char	get_code_ldi(t_stable *tab)
{
	char	k1;
	char	k2;

	k1 = tab->next->key;
	k2 = tab->next->next->key;
	if (k1 == P_REG)
	{
		if (k2 == P_REG)
			return (0x54);
		return (0x64);
	}
	else if (k1 == P_IND)
	{
		if (k2 == P_REG)
			return (0xd4);
		return (0xe4);
	}
	if (k2 == P_REG)
		return (0x94);
	return (0xa4);
}

char	get_code_sti(t_stable *tab)
{
	char	k1;
	char	k2;

	k1 = tab->next->next->key;
	k2 = tab->next->next->next->key;
	if (k1 == P_REG)
	{
		if (k2 == P_REG)
			return (0x54);
		return (0x58);
	}
	else if (k1 == P_IND)
	{
		if (k2 == P_REG)
			return (0x74);
		return (0x78);
	}
	if (k2 == P_REG)
		return (0x64);
	return (0x68);
}

void	write_opcode(int op, t_stable *tab, int fd)
{
	ft_putuchar_fd(op, fd);
	if (op == 4 || op == 5)
		ft_putchar_fd(0x54, fd);
	if (op == 11)
		ft_putchar_fd(get_code_sti(tab), fd);
	if (op == 10 || op == 14)
		ft_putchar_fd(get_code_ldi(tab), fd);
	if (op == 16)
		ft_putchar_fd(0x40, fd);
	if (op == 2 || op == 13)
		ft_putchar_fd((tab->next->key == P_DIR) ? 0x90 : 0xd0, fd);
	if (op == 3)
		ft_putchar_fd((tab->next->next->key == P_REG) ? 0x50 : 0x70, fd);
	if (op == 6 || op == 7 || op == 8)
		ft_putchar_fd(get_code_axo(tab), fd);
}

char	get_opcode(t_stable *tab, int op)
{
	char	res;

	res = 0;
	if (op == 4 || op == 5)
		res = 0x54;
	if (op == 11)
		res = get_code_sti(tab);
	if (op == 10 || op == 14)
		res = get_code_ldi(tab);
	if (op == 16)
		res = 0x40;
	if (op == 2 || op == 13)
		res = (tab->next->key == P_DIR) ? 0x90 : 0xd0;
	if (op == 3)
		res = (tab->next->next->key == P_REG) ? 0x50 : 0x70;
	if (op == 6 || op == 7 || op == 8)
		res = get_code_axo(tab);
	return (res);
}
