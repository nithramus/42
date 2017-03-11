/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_asm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:40:45 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 13:36:18 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ASM_H
# define REVERSE_ASM_H

# include <fcntl.h>
# include <unistd.h>
# include "op.h"
# include <stdlib.h>

size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putunbr_fd(unsigned int n, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**	reverse_op.c
*/

void			fill_ops(unsigned char *str, int fd, int len);
void			define_get_op(int (*get_op[16])(unsigned char *str,
			int fd, int i));

/*
**	reverse_asm.c
*/

char			*change_name(char *name);
int				ft_fill_file_with_str(int fd, unsigned char *str, int len);
int				fill_name_comment(int fd_f, int fd_n, unsigned char *str);
int				fill_file(int fd_f, int fd_n);

/*
**	reverse_tool.c
*/

unsigned int	dir_uint(unsigned char *str);
unsigned int	ind_uint(unsigned char *str);
void			put_reg(unsigned char *str, int fd, int i);

/*
**	reverse_op_ft.c
*/

int				fill_live(unsigned char *str, int fd, int i);
int				fill_load_d(unsigned char *str, int fd, int i);
int				fill_load_i(unsigned char *str, int fd, int i);
int				fill_load(unsigned char *str, int fd, int i);

/*
**	reverse_little_op_comb.c
*/

int				fill_little_rdr(unsigned char *str, int fd, int i);
int				fill_little_drr(unsigned char *str, int fd, int i);
int				fill_little_ddr(unsigned char *str, int fd, int i);
int				fill_little_idr(unsigned char *str, int fd, int i);
int				fill_little_rrd(unsigned char *str, int fd, int i);

/*
**	reverse_little_op_comb2.c
*/

int				fill_little_rdd(unsigned char *str, int fd, int i);
int				fill_little_rid(unsigned char *str, int fd, int i);

/*
**	reverse_op.c
*/

void			define_get_op(int (*get_op[16])(unsigned char *str,
			int fd, int i));
void			fill_ops(unsigned char *str, int fd, int len);

/*
**	reverse_op_comb.c
*/

int				fill_rrr(unsigned char *str, int fd, int i);
int				fill_rdr(unsigned char *str, int fd, int i);
int				fill_rir(unsigned char *str, int fd, int i);
int				fill_drr(unsigned char *str, int fd, int i);
int				fill_ddr(unsigned char *str, int fd, int i);

/*
**	reverse_op_comb2.c
*/

int				fill_dir(unsigned char *str, int fd, int i);
int				fill_irr(unsigned char *str, int fd, int i);
int				fill_idr(unsigned char *str, int fd, int i);
int				fill_iir(unsigned char *str, int fd, int i);

/*
**	reverse_op_ft.c
*/

int				fill_live(unsigned char *str, int fd, int i);
int				fill_load_d(unsigned char *str, int fd, int i);
int				fill_load_i(unsigned char *str, int fd, int i);
int				fill_load(unsigned char *str, int fd, int i);

/*
**	reverse_op_ft2.c
*/

int				fill_st_i(unsigned char *str, int fd, int i);
int				fill_st_r(unsigned char *str, int fd, int i);
int				fill_st(unsigned char *str, int fd, int i);
int				fill_add(unsigned char *str, int fd, int i);
int				fill_sub(unsigned char *str, int fd, int i);

/*
**	reverse_op_ft3.c
*/

int				fill_and(unsigned char *str, int fd, int i);
int				fill_or(unsigned char *str, int fd, int i);
int				fill_xor(unsigned char *str, int fd, int i);
int				fill_zjmp(unsigned char *str, int fd, int i);
int				fill_ldi(unsigned char *str, int fd, int i);

/*
**	reverse_op_ft4.c
*/

int				fill_sti(unsigned char *str, int fd, int i);
int				fill_fork(unsigned char *str, int fd, int i);
int				fill_lld(unsigned char *str, int fd, int i);
int				fill_lldi(unsigned char *str, int fd, int i);

/*
**	reverse_op_ft5.c
*/

int				fill_lfork(unsigned char *str, int fd, int i);
int				fill_aff(unsigned char *str, int fd, int i);

#endif
