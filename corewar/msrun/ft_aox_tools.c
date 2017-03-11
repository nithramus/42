/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aox_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:26:33 by msrun             #+#    #+#             */
/*   Updated: 2017/03/04 13:30:16 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char	*g_memory;

void			ft_get_from_reg(unsigned char *tab, unsigned char *reg)
{
	int	i;

	i = -1;
	while (++i < 4)
		tab[i] = reg[i];
}

int				ft_ind_eq_to(int pos)
{
	int	nb;

	nb = g_memory[pos] * 256 + g_memory[ft_pc(pos + 1)];
	return (nb);
}

unsigned int	ft_dir_eq_to(int pos)
{
	unsigned int	nb;

	nb = g_memory[pos] * 16777216 + g_memory[ft_pc(pos + 1)] * 65536 +
		g_memory[ft_pc(pos + 2)] * 256 + g_memory[ft_pc(pos + 3)];
	return (nb);
}

void			ft_get_from_ind(unsigned char *tab, int pos)
{
	int	i;

	if (pos > 32767)
		pos = pos - 65536;
	pos = pos % IDX_MOD;
	i = -1;
	while (++i < 4)
		tab[i] = g_memory[ft_pc(pos + i)];
}

void			ft_get_from_dir(unsigned char *tab, int pos)
{
	int	i;

	i = -1;
	while (++i < 4)
		tab[i] = g_memory[ft_pc(pos + i)];
}
