/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_msrun.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:03:23 by bandre            #+#    #+#             */
/*   Updated: 2017/03/11 18:03:27 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdlib.h>

typedef struct			s_process
{
	unsigned char		registre[REG_NUMBER][REG_SIZE];
	int					live;
	char				carry;
	int					pc;
	int					cycle;
	int					act_cycle;
	unsigned char		op_code;
	struct s_process	*next;
	struct s_process	*previous;
	int					num_joueur;
}						t_process;

typedef struct			s_joueur
{
	char	num_joueur;
	int		nb_live;
	int		last_live;
	char	*name;
	char	*cri_de_guerre;
}						t_joueur;

typedef struct			s_op
{
	char	*op_name;
	int		nb_param;
	char	code_param[3];
	int		op_code;
	int		nb_cycle;
	char	*op_comment;
	int		codage_octal;
	int		modif_ind;
}						t_op;

/*
**	ft_live.c
*/

int		ft_live(t_process *proc);

/*
**	ft_tools.c
*/

int     ft_pc(int pc);
char    ft_is_reg(int pos);
void	ft_check_op(t_process *proc);
void	ft_fill_reg(t_process *proc, int pos, int reg);
void	ft_define_op(int  (*ft_op[16])(t_process *proc));

/*
**	ft_tools2.c
*/

unsigned int	ft_dir_uint(unsigned char *str);

/*
**	ft_load.c
*/

int			ft_load(t_process *proc);
int			ft_lld(t_process *proc);

/*
**	ft_store.c
*/

int			ft_store(t_process *proc);
void		ft_fill_reg_at_mem(t_process *proc, int pos, int reg);

/*
**	ft_add.c
*/

int			ft_add(t_process *proc);

/*
**	ft_sub.c
*/

int			ft_sub(t_process *proc);

/*
**	ft_aox_tools.c
*/

void			ft_get_from_reg(unsigned char *tab, unsigned char *reg);
int				ft_ind_eq_to(int pos);
unsigned int	ft_dir_eq_to(int pos);
void			ft_get_from_ind(unsigned char *tab, int pos);
void			ft_get_from_dir(unsigned char* tab, int pos);

/*
**	ft_aox_r.c
*/

void	ft_rrr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
void	ft_rir(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
void	ft_rdr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));

/*
**	ft_aox_i.c
*/

void	ft_irr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
void	ft_idr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
void	ft_iir(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));

/*
**	ft_aox_d.c
*/

void	ft_dir(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
void	ft_drr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));
void	ft_ddr(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3));

/*
**	ft_aox.c
*/

void	ft_define_op_aox(void (*ft_aox[9])(t_process *proc,
		void (*f)(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3)));
int		ft_and(t_process *proc);
int		ft_or(t_process *proc);
int		ft_xor(t_process *proc);

/*
**	ft_aox2.c
*/

void	ft_and_fill_reg(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3);
void	ft_or_fill_reg(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3);
void	ft_xor_fill_reg(unsigned char *tab1, unsigned char *tab2, unsigned char *tab3);

/*
**	ft_zjmp.c
*/

int		ft_zjmp(t_process *proc);

/*
**	ft_ldi_par.c
*/

void	ft_ldi_rrr(t_process *proc);
void	ft_ldi_rdr(t_process *proc);
void	ft_ldi_drr(t_process *proc);
void	ft_ldi_ddr(t_process *proc);

/*
**	ft_ldi_par2.c
*/

void	ft_ldi_irr(t_process *proc);
void	ft_ldi_idr(t_process *proc);
void	ft_define_op_ldi(void (*ft_ldi[6])(t_process *proc));

/*
**	ft_ldi.c
*/

int		ft_ldi(t_process *proc);
void	ft_get_from_ind_ldi(unsigned char *tab, int pos);
int		ft_ind_eq_to2(int pos, unsigned char *mem);
void	ft_ldi_fill_reg(unsigned char *tab, unsigned char *reg);
int		ft_lldi(t_process *proc);

/*
**	ft_sti.c
*/

void    ft_sti_reg_pos(t_process *proc, int pos, unsigned char *reg);
int	    ft_sti_rrr(t_process *proc);
void    ft_define_op_sti(int (*ft_sti[6])(t_process *proc));
int	    ft_store_i(t_process *proc);

/*
**	ft_sti2.c
*/

int		ft_sti_rrd(t_process *proc);
int		ft_sti_rdr(t_process *proc);
int		ft_sti_rdd(t_process *proc);
int		ft_sti_rir(t_process *proc);
int		ft_sti_rid(t_process *proc);

/*
**	ft_fork_lfork.c
*/

void	ft_fork_reg_cpy(unsigned char reg[REG_NUMBER][REG_SIZE],
		unsigned char new_reg[REG_NUMBER][REG_SIZE]);
int		ft_fork(t_process *proc);
int		ft_lfork(t_process *proc);

/*
**	ft_aff.c
*/

int		ft_aff(t_process *proc);

