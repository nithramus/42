/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:10:49 by msrun             #+#    #+#             */
/*   Updated: 2017/03/07 15:46:14 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_process		*g_list_process = NULL;
t_joueur		*g_list_joueurs = NULL;
unsigned char	*g_memory = NULL;
extern t_op		g_op_tab[17];
/*
int		ft_pc(int pc)
{
	pc = pc % MEM_SIZE;
	if (pc < 0)
		pc = MEM_SIZE + pc;
	else if (pc >= MEM_SIZE)
		pc -= MEM_SIZE;
	return (pc);
}

char	ft_is_reg(int pos)
{
	if (pos >= MEM_SIZE)
		pos = pos - MEM_SIZE;
	if (g_memory[pos] > 16 || !g_memory[pos])
		return (0);
	return (1);
}

void	ft_check_op(t_process *proc)
{
	if (g_memory[proc->pc] < 17 && g_memory[proc->pc])
	{
		proc->cycle = g_op_tab[g_memory[proc->pc] - 1].nb_cycle;
		proc->op_code = g_memory[proc->pc];
	}
}

void	ft_live(t_process *proc)
{
	unsigned int	i;
	unsigned int	j;
	char			nb[4];

	++(proc->live);
	j = 5;
	while (--j)
		nb[4 - j] = g_memory[ft_pc(proc->pc + j)];
	i = (unsigned int)nb[0];
	j = -1;
	while (g_list_joueurs[++j].name)
		if (i == -j - 1)
		{
			++(g_list_joueurs[j].nb_live);
			g_list_joueurs[j].last_live = proc->atc_cycle;
			break ;
		}
	proc->pc = ft_pc(proc->pc + 5);
	ft_check_op(proc);
}

void	ft_fill_reg(t_process *proc, int pos, int reg)
{
	int i;

	if (pos < 0)
		pos += MEM_SIZE;
	pos = pos % MEM_SIZE;
	i = -1;
	while (++i < 4)
	{
		if (pos + i >= MEM_SIZE)
			pos = -i;
		proc->registre[reg][i] = g_memory[pos + i];
	}
}

static void ft_load_i(t_process *proc)
{
	int	mod;

	if (ft_is_reg(ft_pc(proc->pc + 4)))
	{
		mod = g_memory[ft_pc(proc->pc + 2)] * 256 + g_memory[ft_pc(proc->pc + 3)];
		if (mod > 32767)
			mod = mod - 65536;
		g_memory[proc->pc] == 2 ? mod = mod % IDX_MOD : mod;
		ft_fill_reg(proc, ft_pc(proc->pc + mod % IDX_MOD), g_memory[ft_pc(proc->pc + 4)] - 1);
	}
}

static void ft_load_d(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
		ft_fill_reg(proc, ft_pc(proc->pc + 2), g_memory[ft_pc(proc->pc + 6)] - 1);
}

void	ft_load(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 1)] == 144)
	{
		ft_load_d(proc);
		proc->carry = 1;
		proc->pc = ft_pc(proc->pc + 7);
	}
	else if (g_memory[ft_pc(proc->pc + 1)] == 208)
	{
		ft_load_i(proc);
		proc->carry = 1;
		proc->pc = ft_pc(proc->pc + 5);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

void	ft_fill_reg_at_mem(t_process *proc, int pos, char reg)
{
	int	i;

	if (pos < 0)
		pos += MEM_SIZE;
	pos = pos % MEM_SIZE;
	i = -1;
	while (++i < 4)
	{
		if (pos + i >= MEM_SIZE)
			pos = -i;
		g_memory[pos + i] = proc->registre[reg][i];
	}
}

static void	ft_store_at_i(t_process *proc)
{
	int mod;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)])
	{
		mod = g_memory[ft_pc(proc->pc + 3)] * 256 + g_memory[ft_pc(proc->pc + 4)];
		if (mod > 32767)
			mod = mod - 65536;
		ft_fill_reg_at_mem(proc, ft_pc(proc->pc + mod), g_memory[ft_pc(proc->pc + 2)] - 1);
	}
}

static void	ft_store_r(t_process *proc)
{
	int i;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)])
	{
		i = -1;
		while(++i < 4)
			proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1][i] =
				proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1][i];
	}
}

void	ft_store(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 1)] == 112)
	{
		ft_store_at_i(proc);
		proc->pc = ft_pc(proc->pc + 5);
	}
	else if (g_memory[ft_pc(proc->pc + 1)] == 80)
	{
		ft_store_r(proc);
		proc->pc = ft_pc(proc->pc + 4);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

static void	ft_add_it(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)
{
	long int	nb1;
	long int	nb2;
	int			i;

	i = -1;
	nb1 = 0;
	nb2 = 0;
	while (++i < 4)
	{
		nb1 += nb1 * 255 + tab1[i];
		nb2 += nb2 * 255 + tab2[i];
	}
	nb1 = (nb1 + nb2) % 4294967296;
	i = -1;
	while (++i < 4)
	{
		tab3[3 - i] = nb1 % 256;
		nb1 /= 256;
	}
}

void	ft_add(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 1)] == 84)
	{
		if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
				g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
				g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
			ft_add_it(proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1],
					proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1],
					proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		proc->pc = ft_pc(proc->pc + 5);
		proc->carry = 1;
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

static void	ft_sub_it(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)
{
	long int	nb1;
	long int	nb2;
	int			i;

	i = -1;
	nb1 = 0;
	nb2 = 0;
	while (++i < 4)
	{
		nb1 += nb1 * 255 + tab1[i];
		nb2 += nb2 * 255 + tab2[i];
	}
	if (nb1 >= nb2)
		nb1 -= nb2;
	else
		nb1 = nb1 - (nb2 - 4294967296);
	i = -1;
	while (++i < 4)
	{
		tab3[3 - i] = nb1 % 256;
		nb1 /= 256;
	}
}

void	ft_sub(t_process *proc)
{
	if (g_memory[ft_pc(proc->pc + 1)] == 84)
	{
		if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
				g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
				g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
			ft_sub_it(proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1],
					proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1],
					proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		proc->pc = ft_pc(proc->pc + 5);
		proc->carry = 1;
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

void	ft_xor_fill_reg(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)
{
	tab3[0] = tab1[0] ^ tab2[0];
	tab3[1] = tab1[1] ^ tab2[1];
	tab3[2] = tab1[2] ^ tab2[2];
	tab3[3] = tab1[3] ^ tab2[3];
}

void	ft_or_fill_reg(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)
{
	tab3[0] = tab1[0] | tab2[0];
	tab3[1] = tab1[1] | tab2[1];
	tab3[2] = tab1[2] | tab2[2];
	tab3[3] = tab1[3] | tab2[3];
}

void	ft_and_fill_reg(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)
{
	tab3[0] = tab1[0] & tab2[0];
	tab3[1] = tab1[1] & tab2[1];
	tab3[2] = tab1[2] & tab2[2];
	tab3[3] = tab1[3] & tab2[3];
}

void	ft_get_from_reg(unsigned char *tab, unsigned char *reg)
{
	int i;

	i = -1;
	while (++i < 4)
		tab[i] = reg[i];
}

int		ft_ind_eq_to(int pos)
{
	int nb;

	nb = g_memory[pos] * 256 + g_memory[ft_pc(pos + 1)];
	return (nb);
}

unsigned int	ft_dir_eq_to(int pos)
{
	unsigned int nb;

	nb =  g_memory[pos] * 16777216 + g_memory[ft_pc(pos + 1)] * 65536 +
		g_memory[ft_pc(pos + 2)] * 256 + g_memory[ft_pc(pos + 3)];
	return (nb);
}

void	ft_get_from_ind(unsigned char *tab, int pos)
{
	int i;

	if (pos > 32767)
		pos = pos - 65536;
	pos = pos % IDX_MOD;
	i = -1;
	while (++i < 4)
		tab[i] = g_memory[ft_pc(pos + i)];
}

void	ft_get_from_dir(unsigned char* tab, int pos)
{
	int i ;

	i = -1;
	while (++i < 4)
		tab[i] = g_memory[ft_pc(pos + i)];
}

void	ft_rrr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
			g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
	{
		ft_get_from_reg(tab1, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		ft_get_from_reg(tab2, proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]);
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 4)] -1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 5);
}

void	ft_rir(t_process *proc, 
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		ft_get_from_reg(tab1, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		ft_get_from_ind(tab2, ft_ind_eq_to(ft_pc(proc->pc + 3)));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 6);
}

void	ft_rdr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))

{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 7)] < 17 && g_memory[ft_pc(proc->pc + 7)])
	{
		ft_get_from_reg(tab1, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		ft_get_from_dir(tab2, ft_pc(proc->pc + 3));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 7)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 8);
}

void	ft_irr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		ft_get_from_ind(tab1, ft_ind_eq_to(ft_pc(proc->pc + 2)));
		ft_get_from_reg(tab2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 6);
}

void	ft_idr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 8)] < 17 && g_memory[ft_pc(proc->pc + 8)])
	{
		ft_get_from_ind(tab1, ft_ind_eq_to(ft_pc(proc->pc + 2)));
		ft_get_from_dir(tab2, ft_pc(proc->pc + 4));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 8)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 9);
}

void	ft_iir(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
	{
		ft_get_from_ind(tab1, ft_ind_eq_to(ft_pc(proc->pc + 2)));
		ft_get_from_ind(tab2, ft_ind_eq_to(ft_pc(proc->pc + 4)));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 7);
}

void	ft_ddr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 10)] < 17 && g_memory[ft_pc(proc->pc + 10)])
	{
		ft_get_from_dir(tab1, ft_pc(proc->pc + 2));
		ft_get_from_dir(tab2, ft_pc(proc->pc + 6));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 10)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 11);
}

void	ft_drr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)] && 
			g_memory[ft_pc(proc->pc + 7)] < 17 && g_memory[ft_pc(proc->pc + 7)])
	{
		ft_get_from_dir(tab1, ft_pc(proc->pc + 2));
		ft_get_from_reg(tab2, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 7)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 8);
}

void	ft_dir(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3))
{
	unsigned char	tab1[4];
	unsigned char	tab2[4];

	if (g_memory[ft_pc(proc->pc + 8)] < 17 && g_memory[ft_pc(proc->pc + 8)])
	{
		ft_get_from_dir(tab1, ft_pc(proc->pc + 2));
		ft_get_from_ind(tab2, ft_ind_eq_to(ft_pc(proc->pc + 6)));
		f(tab1, tab2, proc->registre[g_memory[ft_pc(proc->pc + 8)] - 1]);
		proc->carry = 1;
	}
	proc->pc = ft_pc(proc->pc + 9);
}

void	ft_define_op_aox(void    (*ft_aox[9])(t_process *proc,
			void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)))
{
	ft_aox[0] = &ft_rrr;
	ft_aox[1] = &ft_rdr;
	ft_aox[2] = &ft_rir;
	ft_aox[3] = &ft_drr;
	ft_aox[4] = &ft_ddr;
	ft_aox[5] = &ft_dir;
	ft_aox[6] = &ft_irr;
	ft_aox[7] = &ft_idr;
	ft_aox[8] = &ft_iir;
}

void	ft_and(t_process *proc)
{
	void	(*ft_aox[9])(t_process *proc,
			void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));

	ft_define_op_aox(ft_aox);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 && g_memory[ft_pc(proc->pc + 1)] <= 244
			&& !((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 132 && g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_aox[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
			((g_memory[ft_pc(proc->pc + 1)] - 84) / 48)](proc, &ft_and_fill_reg);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

void	ft_or(t_process *proc)
{
	void	(*ft_aox[9])(t_process *proc,
			void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));

	ft_define_op_aox(ft_aox);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 && g_memory[ft_pc(proc->pc + 1)] <= 244
			&& !((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 132 && g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_aox[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
			((g_memory[ft_pc(proc->pc + 1)] - 84) / 48)](proc, &ft_or_fill_reg);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

void	ft_xor(t_process *proc)
{
	void	(*ft_aox[9])(t_process *proc,
			void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));

	ft_define_op_aox(ft_aox);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 && g_memory[ft_pc(proc->pc + 1)] <= 244
			&& !((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 132 && g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_aox[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
			((g_memory[ft_pc(proc->pc + 1)] - 84) / 48)](proc, &ft_xor_fill_reg);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

void	ft_zjmp(t_process *proc)
{
	int	i;
	int pos;

	if (proc->carry == 1)
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 1));
		if (pos > 32767)
			pos = pos - 65536;
		pos = pos % IDX_MOD;
		proc->pc = ft_pc(proc->pc + pos);
	}
	else
		proc->pc = ft_pc(proc->pc + 3);
	ft_check_op(proc);
}

void	ft_ldi_fill_reg(unsigned char *tab, unsigned char *reg)
{
	reg[0] = tab[0];
	reg[1] = tab[1];
	reg[2] = tab[2];
	reg[3] = tab[3];
}

int		ft_ind_eq_to2(int pos, unsigned char *mem)
{
	return (mem[pos] * 256 + mem[ft_pc(pos + 1)]);
}

void	ft_get_from_ind_ldi(unsigned char *tab, int pos)
{
	int i;

	i = -1;
	while (++i < 4)
		tab[i] = g_memory[ft_pc(pos + i)];
}

void	ft_ldi_rrr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] && 
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
			g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
	{
		pos = ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]) +
			ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		proc->pc = ft_pc(proc->pc + 5);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_rdr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]) +
			ft_ind_eq_to2(ft_pc(proc->pc + 3), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_drr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	printf("ok\n");
	if (g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)] && 
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]) +
			ft_ind_eq_to2(ft_pc(proc->pc + 2), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_ddr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
	{
		pos = ft_ind_eq_to2(ft_pc(proc->pc + 2), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 4), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_irr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 2));
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
		ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_ldi_idr(t_process *proc)
{
	int				pos;
	unsigned char	tab[4];

	if (g_memory[ft_pc(proc->pc + 6)] < 17 && g_memory[ft_pc(proc->pc + 6)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 2));
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
		ft_ind_eq_to2(ft_pc(proc->pc + 4), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		g_memory[ft_pc(proc->pc)] == 10 ? pos = pos % IDX_MOD : pos;
		ft_get_from_ind_ldi(tab, ft_pc(proc->pc + pos));
		ft_ldi_fill_reg(tab, proc->registre[g_memory[ft_pc(proc->pc + 6)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_define_op_ldi(void (*ft_ldi[6])(t_process *proc))
{
	ft_ldi[0] = &ft_ldi_rrr;
	ft_ldi[1] = &ft_ldi_rdr;
	ft_ldi[2] = &ft_ldi_drr;
	ft_ldi[3] = &ft_ldi_ddr;
	ft_ldi[4] = &ft_ldi_irr;
	ft_ldi[5] = &ft_ldi_idr;
}

void	ft_ldi(t_process *proc)
{
	void	(*ft_ldi[6])(t_process *proc);

	ft_define_op_ldi(ft_ldi);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 && g_memory[ft_pc(proc->pc + 1)] <= 228
			&& !((g_memory[ft_pc(proc->pc + 1)] - 84) % 16) &&
			g_memory[ft_pc(proc->pc + 1)] != 116 && g_memory[ft_pc(proc->pc + 1)] != 132 &&
			g_memory[ft_pc(proc->pc + 1)] != 180 && g_memory[ft_pc(proc->pc + 1)] != 196)
	{
		ft_ldi[((g_memory[ft_pc(proc->pc + 1)] - 84) / 16) -
			((g_memory[ft_pc(proc->pc + 1)] - 84) / 60) * 2](proc);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}

void	ft_sti_reg_pos(t_process *proc, int pos, unsigned char *reg)
{
	int i;

	i = -1;
	while (++i < 4)
		g_memory[ft_pc(proc->pc + pos + i)] = reg[i];
}

void	ft_sti_rrr(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)] &&
			g_memory[ft_pc(proc->pc + 4)] < 17 && g_memory[ft_pc(proc->pc + 4)])
	{
		pos = ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]) +
		ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 4)] - 1]);	 
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 5);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_sti_rrd(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 3)] < 17 && g_memory[ft_pc(proc->pc + 3)])
	{
		pos = ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 3)] - 1]) +
			ft_ind_eq_to2(ft_pc(proc->pc + 4), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_sti_rdr(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]) +
			ft_ind_eq_to2(ft_pc(proc->pc + 3), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_sti_rdd(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)])
	{
		pos = ft_ind_eq_to2(ft_pc(proc->pc + 3), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 5), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_sti_rir(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 5)] < 17 && g_memory[ft_pc(proc->pc + 5)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 3));
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
			ft_ind_eq_to2(2, proc->registre[g_memory[ft_pc(proc->pc + 5)] - 1]);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 6);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_sti_rid(t_process *proc)
{
	int pos;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)])
	{
		pos = ft_ind_eq_to(ft_pc(proc->pc + 3));
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		pos = ft_ind_eq_to2(ft_pc(proc->pc + pos), g_memory) +
			ft_ind_eq_to2(ft_pc(proc->pc + 5), g_memory);
		pos = pos % 65536;
		if (pos > 32767)
			pos -= 65536;
		pos = pos % IDX_MOD;
		ft_sti_reg_pos(proc, pos, proc->registre[g_memory[ft_pc(proc->pc + 2)] - 1]);
		proc->pc = ft_pc(proc->pc + 7);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
}

void	ft_define_op_sti(void (*ft_sti[6])(t_process *proc))
{
	ft_sti[0] = &ft_sti_rrr;
	ft_sti[1] = &ft_sti_rrd;
	ft_sti[2] = &ft_sti_rdr;
	ft_sti[3] = &ft_sti_rdd;
	ft_sti[4] = &ft_sti_rir;
	ft_sti[5] = &ft_sti_rid;
}

void	ft_store_i(t_process *proc)
{
	void	(*ft_sti[6])(t_process *proc);

	ft_define_op_sti(ft_sti);
	if (g_memory[ft_pc(proc->pc + 1)] >= 84 && g_memory[ft_pc(proc->pc + 1)] <= 120
			&& !((g_memory[ft_pc(proc->pc + 1)] - 84) % 4) &&
			g_memory[ft_pc(proc->pc + 1)] != 92 && g_memory[ft_pc(proc->pc + 1)] != 96 &&
			g_memory[ft_pc(proc->pc + 1)] != 108 && g_memory[ft_pc(proc->pc + 1)] != 112)
	{
		ft_sti[((g_memory[ft_pc(proc->pc + 1)] - 84) / 4) -
			((g_memory[ft_pc(ft_pc(proc->pc + 1))] - 84) / 16 * 2)](proc);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}
*/
void	quit_clean(int error)
{}
/*
void	ft_fork_reg_cpy(unsigned char reg[REG_NUMBER][REG_SIZE],
		unsigned char new_reg[REG_NUMBER][REG_SIZE])
{
	int i;
	int u;

	i = -1;
	while (++i < REG_NUMBER)
		u = -1;
		while (++u < REG_SIZE)
			new_reg[i][u] = reg[i][u];
}

void	ft_fork(t_process *proc)
{
	t_process	*new_proc;
	int			pos;

	if (!(new_proc = malloc(sizeof(t_process))))
		quit_clean(1);
	ft_fork_reg_cpy(proc->registre, new_proc->registre);
	new_proc->live = proc->live;
	new_proc->carry = proc->carry;
	if ((pos = ft_ind_eq_to(g_memory[ft_pc(proc->pc + 1)])) > 32767)
		pos -= 65536;
	g_memory[ft_pc(proc->pc)] == 12 ? pos = pos % IDX_MOD : pos;
	new_proc->pc = ft_pc(proc->pc + pos);
	new_proc->cycle = 0;
	new_proc->atc_cycle = 0;
	ft_check_op(new_proc);
	new_proc->next = g_list_process;
	new_proc->previous = NULL;
	g_list_process = new_proc;
	proc->pc = ft_pc(proc->pc + 3);
	ft_check_op(proc);
}

void	ft_lld(t_process *proc)
{
	ft_load(proc);
}

void	ft_lldi(t_process *proc)
{
	ft_ldi(proc);
}

void	ft_lfork(t_process *proc)
{
	ft_fork(proc);
}

void	ft_aff(t_process *proc)
{
	unsigned char	c;

	if (g_memory[ft_pc(proc->pc + 2)] < 17 && g_memory[ft_pc(proc->pc + 2)] &&
			g_memory[ft_pc(proc->pc + 1)] == 64)
	{
		c = proc->registre[g_memory[(ft_pc(proc->pc + 2))] - 1][3];
		write(1, &c,1);
	}
	else
		proc->pc = ft_pc(proc->pc + 2);
	ft_check_op(proc);
}
*/
/*void	ft_op_proc(t_process *proc)
{
	ft_op[proc->op_code - 1](proc);
}*/
/*
void	ft_define_op(void  (*ft_op[16])(t_process *proc))
{
	ft_op[0] = &ft_live;
	ft_op[1] = &ft_load;
	ft_op[2] = &ft_store;
	ft_op[3] = &ft_add;
	ft_op[4] = &ft_sub;
	ft_op[5] = &ft_and;
	ft_op[6] = &ft_or;
	ft_op[7] = &ft_xor;
	ft_op[8] = &ft_zjmp;
	ft_op[9] = &ft_ldi;
	ft_op[10] = &ft_store_i;
	ft_op[11] = &ft_fork;
	ft_op[12] = &ft_lld;
	ft_op[13] = &ft_lldi;
	ft_op[14] = &ft_lfork;
	ft_op[15] = &ft_aff;
}
*/
int main()
{
	t_process	*proc;
	int i;
	//void	*ft_op[16](t_process *proc);
	int  (*ft_op[16])(struct s_process *proc);

//	ft_op = malloc(sizeof(ft_op) * 16);
//	proc->ft_op = malloc(sizeof(proc->ft_op) * 16);
	//proc->ft_op = malloc(sizeof(proc->ft_op) * 16000);
	ft_define_op(ft_op);
//	ft_define_op(proc->ft_op);
//	printf("%p\n%p\n", ft_op[0], proc->ft_op[0]);
//	printf("%p\n%p\n", ft_op[1], proc->ft_op[1]);
//	printf("%p\n%p\n", ft_op[2], proc->ft_op[2]);
//	ft_define_op(proc->ft_op);
//	proc->ft_op[0] = &ft_live;
//	ft_define_op(proc->ft_op);
//	ft_define_op_ldi(proc->ft_ldi);
//	proc->ft_ldi[0](proc, &ft_ldi_fill_reg);
	g_list_joueurs = malloc(sizeof(t_joueur) * 3);
	g_list_joueurs[0].num_joueur = 1;
	g_list_joueurs[0].nb_live = 0;
	g_list_joueurs[0].name = malloc(1);
	g_list_joueurs[0].name[0] = 1;
	g_list_joueurs[0].last_live = 0;
	g_list_joueurs[1].num_joueur = 2;
	g_list_joueurs[1].nb_live = 0;
	g_list_joueurs[1].name = malloc(1);
	g_list_joueurs[1].name[0] = 2;
	g_list_joueurs[1].last_live = 0;
	g_list_joueurs[2].name = 0;
	if (!(proc = malloc(sizeof(t_process))))
		return (0);
	proc->live = 0;
	proc->carry = 0;
	proc->pc = 0;
	proc->op_code = 1;
	proc->cycle = 1506;
	if (!(g_memory = malloc(sizeof(char) * MEM_SIZE)))
		return (0);
	i = -1;
	while (++i < 4096)
		g_memory[i] = 0;
	g_memory[0] = 1;
	g_memory[1] = 225;
	g_memory[2] = 255;
	g_memory[3] = 255;
	g_memory[4] = 255;
	g_memory[5] = 3;
	g_memory[6] = 1;
	proc->registre[0][0] = 0;
	proc->registre[0][1] = 0;
	proc->registre[0][2] = 0;
	proc->registre[0][3] = 0;
	//ft_op_proc(proc);
	ft_op[proc->op_code - 1](proc);
//	((proc->ft_op)[proc->op_code - 1])(proc);
	printf("op code%d\n", proc->op_code);
	printf("last live %-5d g_list_joueurs live %d, proc live %d\n", g_list_joueurs[0].last_live, g_list_joueurs[0].nb_live, proc->live);
	printf("last live %-5d g_list_joueurs live %d, proc live %d\n", g_list_joueurs[1].last_live, g_list_joueurs[1].nb_live, proc->live);
	i = -1;
	while (++i < 4)
		printf("%u ", proc->registre[0][i]);
	printf("next cycle %d\n", proc->cycle);
	proc->op_code = 11;
	proc->pc = 0;
	g_memory[0] = 11;
	g_memory[1] = 120;
	g_memory[2] = 1;
	g_memory[3] = 0;
	g_memory[4] = 7;
	g_memory[5] = 0;
	g_memory[6] = 3;
	g_memory[7] = 255;
	g_memory[8] = 254;
	g_memory[9] = 0x22;
	g_memory[10] = 3;
	
	i = -1;
	while (++i < 4)
	{
		proc->registre[0][i] = 0;
		proc->registre[1][i] = 0;
		proc->registre[2][i] = 0;
	}
	i = 10;
//	while (++i < 100)
//		g_memory[i] = i;
	proc->registre[0][0] = 5;
	proc->registre[1][0] = 0;
	proc->registre[0][1] = 2;
	proc->registre[1][1] = 0;
	proc->registre[0][2] = 4;
	proc->registre[1][2] = 0;
	proc->registre[0][3] = 2;
	proc->registre[1][3] = 5;
	printf("\n");
	printf("pc %d \n ", proc->pc);
	//proc->carry = 0;
	//ft_op_proc(proc);
	ft_op[proc->op_code - 1](proc);
	//proc->ft_op[proc->op_code - 1](proc);
	printf("pc %d \n ", proc->pc);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf(" * %02x ", proc->registre[0][i]);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf(" * %02x ", proc->registre[1][i]);
	i = -1;
	printf("\n");
	while (++i < 4)
		printf(" * %02x ", proc->registre[2][i]);
	printf("\n");
	i = 4086;
	while (++i < 4096)
		printf("%02x ", g_memory[i]);
	i = -1;
	while (++i < 100)
		printf("%02x ", g_memory[i]);

}
